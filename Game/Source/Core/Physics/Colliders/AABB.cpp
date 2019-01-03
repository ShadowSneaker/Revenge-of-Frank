#include "AABB.h"
#include "Circle.h"
#include "../../../Math/MathStatics.h"

#include <math.h>


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
	SVector2i Dist;
	Dist[X] = abs(Other->GetWorldLocation()[X] - GetWorldLocation()[X]);
	Dist[Y] = abs(Other->GetWorldLocation()[Y] - GetWorldLocation()[Y]);

	if (Dist[X] > (GetMaxExtent()[X] / 2 + Other->GetRadius())) { return false; }
	if (Dist[Y] > (GetMaxExtent()[Y] / 2 + Other->GetRadius())) { return false; }

	if (Dist[X] <= (GetMaxExtent()[X] / 2)) { return true; }
	if (Dist[Y] <= (GetMaxExtent()[Y] / 2)) { return true; }

	float CornerDist = Power(Dist[X] - GetMaxExtent()[X] / 2, 2) + Power(Dist[Y] - GetMaxExtent()[Y] / 2, 2);

	return (CornerDist <= Other->GetRadius());
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