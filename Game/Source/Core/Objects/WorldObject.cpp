#include "WorldObject.h"
#include "../World/World.h"


CWorldObject::CWorldObject(OBJECT_CONSTRUCTOR_BASE InBase, STransform InTransform)
	:Base{ InBase }, Transform{ InTransform }
{
	Active = true;
	DeltaTime = nullptr;
	EnableGravity = false;
}


CWorldObject::~CWorldObject() 
{
	IsPendingKill = true;
}


void CWorldObject::ApplyGravity(CCollider* Collider)
{
	if (EnableGravity && Active)
	{
		VelY -= Base.Physics->Gravity * *DeltaTime;

		std::vector<SHitInfo> Hit;
		if (Collider)
		{
			Base.Physics->CheckCollisions(SObjectType(this, Collider, ""), STransform(Transform.Location + (SVector2i(0, int(VelY))), Transform.Rotation, Transform.Scale), Hit, true);
		}
		else
		{
			return;
		}

		if (!IsPendingKill)
		{
			bool HitCol = false;

			for (size_t i = 0; i < Hit.size(); ++i)
			{
				if (Hit[i].Hit && !Hit[i].Collider->Overlap)
				{
					HitCol = true;
					break;
				}
			}

			if (!HitCol)
			{
				Transform.Location[Y] += int(VelY);
				Grounded = false;
			}
			else
			{
				if (Base.Physics->GravityDirection() > 0)
				{
					if (VelY < 0.0f)
					{
						VelY = 0.0f;
					}
					else
					{
						AdjustLocation(Collider, Hit[0]);
					}
				}
				else
				{
					if (VelY > 0.0f)
					{

						VelY = 0.0f;
					}
					else
					{
						AdjustLocation(Collider, Hit[0]);
					}
				}
			}
		}
	}
}


void CWorldObject::AdjustLocation(CCollider* Collider, SHitInfo Hit)
{
	SHitInfo NewInfo;
	NewInfo.Hit = false;
	while (!NewInfo.Hit)
	{
		Transform.Location[Y] += 1 * Base.Physics->GravityDirection();
		if (Collider->CheckCollision(Hit.Collider))
		{
			Transform.Location[Y] -= 1 * Base.Physics->GravityDirection();
			break;
		}
	}

	Grounded = true;
	VelY = 0.0f;
}