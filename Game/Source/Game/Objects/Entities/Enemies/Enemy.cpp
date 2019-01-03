#include "Enemy.h"
#include "../Player.h"
#include "../../../../Core/Physics/Colliders/Circle.h"
#include "../../../../Math/MathStatics.h"


CEnemy::CEnemy(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform)
	:CEntity::CEntity{ Base, InTransform }
{
	MovementSpeed = 400.0f;

	ImmunityFrames = 0.1f;
	
	Animation->SetAnimation("MiniFrank.bmp", 1, 1);
	BoxCollider->Extents = Animation->GetCellSize();
	

	CircleCollider = new CCircle(&Transform, Animation->GetCellCenter(), 75.0f);
	CircleCollider->Overlap = true;
	GetPhysics()->AddCollider(SObjectType(this, CircleCollider, "Agro"));

	AttackRange = new CCircle(&Transform, Animation->GetCellCenter(), 1.0f);
	AttackRange->Overlap = true;
	GetPhysics()->AddCollider(SObjectType(this, CircleCollider, "Range"));// , &CEntity::AgroRange));
	Transform.Scale = 0.25f;
}


CEnemy::~CEnemy()
{
	GetPhysics()->DestroyCollider(CircleCollider);
	CircleCollider = nullptr;

	GetPhysics()->DestroyCollider(AttackRange);
	AttackRange = nullptr;
	//delete CircleCollider;
}


void CEnemy::Update()
{
	CEntity::Update();

	if (PlayerRef)
	{
	
		// Basic AI.
		if (IsAgro && !IsPendingKill)
		{
			int Val1 = Transform.GetWorldLocation()[X] + GetAnimation()->GetCellCenter()[X];
			int Val2 = PlayerRef->Transform.GetWorldLocation()[X] + PlayerRef->GetAnimation()->GetCellCenter()[X];
			int Range = int(GetAnimation()->GetCellSize()[X] * Transform.GetWorldScale()[X] / 2);


			if (!NearlyEqual(Val1, Val2, Range))
			{

				if (PlayerRef->Transform.GetWorldLocation()[X] < Transform.GetWorldLocation()[X])
				{
					MoveHorizontal(-1);
				}
				else
				{
					MoveHorizontal(1);
				}
			}

			if (GetPhysics()->GravityDirection() < 0.0f)
			{
				GetAnimation()->FlipY = true;
				if (PlayerRef->Transform.Location[Y] > Transform.Location[Y])
				{
					Jump();
				}
			}
			else
			{
				if (!IsPendingKill)
				{
					GetAnimation()->FlipY = false;
					if (PlayerRef->Transform.Location[Y] + PlayerRef->GetAnimation()->GetCellSize()[Y] < Transform.Location[Y])
					{
						Jump();
					}
				}
			}
		}
	}
}


// Use a string in the SObjectType struct for initialization to determine the different Overlap/Collision calls.

void CEnemy::OnOverlap(SHitInfo Info, std::string Tag)
{
	if (Info.HitObject == PlayerRef)
	{
		if (Tag == "Agro")
		{
			if (!IsAgro)
			{
				IsAgro = true;
			}
		}
		else if (Tag == "Range")
		{
			// Box to circle collisions still don't work propperly, the radius is ignored.
			if (Info.HitObject->ApplyDamage(Damage) <= 0.0f)
			{
				PlayerRef = nullptr;
			}
		}
	}
}