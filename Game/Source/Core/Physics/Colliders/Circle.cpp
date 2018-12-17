#include "Circle.h"
#include "AABB.h"
#include "../../../Math/MathStatics.h"


CCircle::CCircle()
	:CCollider::CCollider{}, Radius{ 1.0f }
{
	Type = EColliderType::Circle;
}


CCircle::CCircle(STransform* Transform, float SetRadius)
	:CCollider::CCollider{ Transform }, Radius{ SetRadius }
{
	Type = EColliderType::Circle;
}


CCircle::CCircle(STransform* Transform, SVector2i Center, float SetRadius)
	:CCollider{ Transform, Center }, Radius{ SetRadius }
{
	Type = EColliderType::Circle;
}


bool CCircle::CheckCollision(const class CAABB* Other) const
{
	SVector2 Delta;
	SVector2 Dist = (Other->GetMinExtent() + Other->GetMaxExtent());

	Delta = GetCenter().ToFloat() - (Other->GetMinExtent().Max(GetCenter().ToFloat().Min(Dist)));

	return ((Delta[X] * Delta[X]) + (Delta[Y] * Delta[Y]) < (GetRadius() * GetRadius()));
}


bool CCircle::CheckCollision(const CCircle* Other) const
{
	float Radi = GetRadius() + Other->GetRadius();
	Radi *= Radi;
	return Radi < ((GetCenter()[X] + Other->GetCenter()[X]) ^ 2) + ((GetCenter()[Y] + Other->GetCenter()[Y]) ^ 2);
}


bool CCircle::CheckCollision(const CCollider* Other) const
{
	if (Other->GetType() == EColliderType::Box)
	{
		CAABB* Collider = (CAABB*)Other;
		return CheckCollision(Collider);
	}
	else if (Other->GetType() == EColliderType::Circle)
	{
		CCircle* Collider = (CCircle*)Other;
		return CheckCollision(Collider);
	}

	return false;
}