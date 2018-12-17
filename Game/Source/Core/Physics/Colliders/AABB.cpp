#include "AABB.h"
#include "Circle.h"


CAABB::CAABB()
	:CCollider::CCollider()
{
	Type = EColliderType::Box;
	Extents = 1;
	Scale = 1.0f;
}


CAABB::CAABB(STransform* Transform)
	:CCollider::CCollider(Transform)
{
	Type = EColliderType::Box;
	Extents = 1;
	Scale = 1.0f;
}


CAABB::CAABB(STransform* Transform, SVector2i InExtents)
	:CCollider::CCollider(Transform), Extents{ InExtents }
{
	Type = EColliderType::Box;
	Scale = 1.0f;
}

CAABB::CAABB(STransform* Transform, SVector2i InLocation, SVector2i InExtents)
	:CCollider::CCollider(Transform, InLocation), Extents{ InExtents }
{
	Type = EColliderType::Box;
	Scale = 1.0f;
}


bool CAABB::CheckCollision(const CAABB* Other) const
{
	// Calculate the distance between this collider's min extent with the other's max extent.
	SVector2 Distance1 = (Other->GetMinExtent() - GetMaxExtent());

	// Calcualte the distance between other's min extent with my max extent.
	SVector2 Distance2 = (GetMinExtent() - Other->GetMaxExtent());

	SVector2 Distances = Distance1.Max(Distance2);

	// The the highest component in both vectors then test if it is less than or equal to 0.
	float MaxDistance = Distances.MaxComp();
	
	return MaxDistance < 0;
}


bool CAABB::CheckCollision(const class CCircle* Other) const
{
	SVector2 Delta;
	SVector2 Dist = (GetMinExtent() + GetMaxExtent().ToFloat());

	Delta = Other->GetCenter().ToFloat() - (GetMinExtent().Max(Other->GetCenter().ToFloat().Min(Dist.ToFloat())));

	return ((Delta[X] * Delta[X]) + (Delta[Y] * Delta[Y]) < (Other->GetRadius() * Other->GetRadius()));	
}


bool CAABB::CheckCollision(const CCollider* Other) const
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