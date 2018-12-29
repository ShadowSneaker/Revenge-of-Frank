#include "Entity.h"
#include "../../../Core/World/World.h"


CEntity::CEntity(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform)
	:CWorldObject::CWorldObject{ Base, InTransform }
{
	MaxHealth = 100.0f;
	Health = MaxHealth;

	Damage = 10.0f;

	Dead = false;
	Immune = false;

	ImmunityFrames = 1.0f;


	EnableGravity = true;
	MovementSpeed = 500.0f;
	JumpStrength = 20.0f;

	Animation = GetRenderer()->CreateImage<CAnimation>();
	Animation->Transform.SetParent(&Transform);

	Animation->ZOrder = 1;

	BoxCollider = new CAABB(&Transform, Animation->GetCellSize());
	GetPhysics()->AddCollider(SObjectType(this, BoxCollider, "Col"));
}


CEntity::~CEntity()
{
	GetRenderer()->DestroyImage(Animation);
	Animation = nullptr;
	//delete Animation;
	GetPhysics()->DestroyCollider(BoxCollider);
	BoxCollider = nullptr;
	//delete BoxCollider;
}


void CEntity::Update()
{
	CWorldObject::Update();
	Animation->Update(*DeltaTime);

	ApplyGravity(BoxCollider);

	if (Immune)
	{
		if (ImmuneTimer > 0.0f)
		{
			ImmuneTimer -= *DeltaTime;
		}
		else
		{
			Immune = false;
		}
	}
}


void CEntity::MoveHorizontal(float Value)
{
	MoveDir = Value;
	Animation->FlipX = (Value < 0.0f);

	std::vector<SHitInfo> Hit;
	GetPhysics()->CheckCollisions(SObjectType(this, BoxCollider, ""), STransform(Transform.GetWorldLocation() + SVector2i(int((MovementSpeed * Value) * *DeltaTime), 0), Transform.GetWorldRotation(), Transform.GetWorldScale()), Hit);

	bool HitCol = false;
	if (!IsPendingKill)
	{
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
			Transform.Location[X] += int((MovementSpeed * MoveDir) * *DeltaTime);

			if (Animation && !Animation->Playing)
			{
				Animation->Play();
			}
		}
		else
		{

			SHitInfo NewInfo;
			NewInfo.Hit = false;
			while (!NewInfo.Hit)
			{
				Transform.Location[X] += (int)Value;
				if (BoxCollider->CheckCollision(Hit[0].Collider))
				{
					Transform.Location[X] -= (int)Value;
					break;
				}
			}

			if (Animation && Animation->Playing)
			{
				Animation->SetFrame(0);
				Animation->Stop();
			}
		}
	}
}


float CEntity::ApplyDamage(const float Damage)
{
	if (!Immune)
	{
		Immune = true;
		ImmuneTimer = ImmunityFrames;

		Health -= Damage;
		if (Health <= 0.0f)
		{
			Dead = true;
			GetWorld()->DestroyObject(this);
		}
	}

	return Health;
}


void CEntity::Jump()
{
	if (OnGround())
	{
		VelY -= JumpStrength * GetPhysics()->GravityDirection();
		Grounded = false;
	}
}


void CEntity::Posess()
{
	GetWorld()->PossessedObject = this;
}