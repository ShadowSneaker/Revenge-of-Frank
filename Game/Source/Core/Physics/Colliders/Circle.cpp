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
	SVector2i Dist;
	Dist[X] = abs(GetWorldLocation()[X] - Other->GetWorldLocation()[X]);
	Dist[Y] = abs(GetWorldLocation()[Y] - Other->GetWorldLocation()[Y]);

	if (Dist[X] > (Other->GetMaxExtent()[X] / 2 + GetRadius())) { return false; }
	if (Dist[Y] > (Other->GetMaxExtent()[Y] / 2 + GetRadius())) { return false; }

	if (Dist[X] <= (Other->GetMaxExtent()[X] / 2)) { return true; }
	if (Dist[Y] <= (Other->GetMaxExtent()[Y] / 2)) { return true; }

	float CornerDist = Power(Dist[X] - Other->GetMaxExtent()[X] / 2, 2) + Power(Dist[Y] - Other->GetMaxExtent()[Y] / 2, 2);

	return (CornerDist <= GetRadius());
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