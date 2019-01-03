#include "Physics.h"
#include "Colliders/AABB.h"
#include "Colliders/Circle.h"
#include "../Objects/WorldObject.h"

#include <vector>


CPhysics::CPhysics()
{
	Gravity = -50.0f;
}


const std::vector<SHitInfo> CPhysics::CheckCollisions(SObjectType Object, STransform NewLocation, std::vector<SHitInfo>& HitInfo, const bool IgnoreSelf)
{
	CCollider* Tester;

	HitInfo.clear();

	SHitInfo ColliderInfo;
	ColliderInfo.Collider = Object.Collider;
	ColliderInfo.HitObject = Object.Object;
	ColliderInfo.Hit = false;


	switch (Object.Collider->GetType())
	{
	case EColliderType::Box:
		Tester = new CAABB(*(CAABB*)Object.Collider);
		Tester->SetOwner(&NewLocation);
		break;


	case EColliderType::Circle:
		Tester = new CCircle(*(CCircle*)Object.Collider);
		Tester->SetOwner(&NewLocation);
		break;


	default:
		return std::vector<SHitInfo>();
	}



	for (size_t i = 0; i < Objects.size(); ++i)
	{
		if (Objects[i].Object && !Objects[i].Object->IsPendingKill)
		{
			// Skip this collider if it is the same as the inputted collider
			if (IgnoreSelf && Object.Object == Objects[i].Object)
			{
				++i;
				if (i >= Objects.size())
				{
					break;
				}
			}


			if (Tester->CheckCollision(Objects[i].Collider))
			{
				SHitInfo Info;
				Info.Hit = true;
				Info.HitObject = Objects[i].Object;
				Info.Collider = Objects[i].Collider;

				HitInfo.push_back(Info);
				
				ColliderInfo.Hit = true;

				if (Info.Collider->Overlap && !Info.HitObject->IsPendingKill)
				{
					Object.Object->OnOverlap(Info, Object.Tag);
					if (Objects[i].Object && Objects[i].Collider)
						Info.HitObject->OnOverlap(ColliderInfo, Objects[i].Tag);
				}
				else
				{
					Object.Object->OnCollision(Info, Object.Tag);
					if (Objects[i].Object && Objects[i].Collider)
						Info.HitObject->OnCollision(ColliderInfo, Objects[i].Tag);
				}
			}
		}
		else
		{
			Objects.erase(Objects.begin() + i);
		}
	}


	if (Tester)
	{
		delete Tester;
	}

	return HitInfo;
}


const SHitInfo CPhysics::CheckCollisions(CCollider* Collider, SHitInfo& HitInfo, const bool IgnoreSelf) const
{
	HitInfo.Hit = false;
	HitInfo.HitObject = nullptr;
	HitInfo.Collider = nullptr;

	for (size_t i = 0; i < Objects.size(); ++i)
	{
		if (IgnoreSelf && Collider == Objects[i].Collider)
		{
			++i;
		}


		if (Collider->CheckCollision(Objects[i].Collider))
		{
			HitInfo.Hit = true;
			HitInfo.HitObject = Objects[i].Object;
			HitInfo.Collider = Objects[i].Collider;

			return HitInfo;
		}
	}


	return HitInfo;
}


void CPhysics::DestroyCollider(CCollider* Collider)
{
	for (size_t i = 0; i < Objects.size(); ++i)
	{
		if (Objects[i].Collider == Collider)
		{
			delete Objects[i].Collider;
			Objects.erase(Objects.begin() + i);
			return;
		}
	}
	delete Collider;
}