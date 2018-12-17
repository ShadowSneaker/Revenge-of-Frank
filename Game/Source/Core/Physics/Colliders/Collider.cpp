#include "Collider.h"
#include "Circle.h"
#include "AABB.h"


CCollider::CCollider()
	: Owner{ nullptr }, Overlap{ false }
{}


CCollider::CCollider(STransform* Transform)
	: Owner{ Transform }, Overlap{ false }
{}


CCollider::CCollider(STransform* Transform, SVector2i InLocation)
	: Owner{ Transform }, Location{ InLocation }, Overlap{ false }
{}


bool CCollider::CheckCollision(const CCollider* Other) const
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