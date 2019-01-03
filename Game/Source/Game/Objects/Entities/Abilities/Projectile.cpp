#include "Projectile.h"
#include "../../../../Core/World/World.h"
#include "../../../../Core/Physics/Colliders/AABB.h"


CProjectile::CProjectile(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform)
	:CWorldObject::CWorldObject{ Base, InTransform }
{
	Speed = 800.0f;
	Damage = 10.0f;

	Image = GetRenderer()->CreateImage<CSprite>("PlasmaBall.bmp");
	Image->Transform.SetParent(&Transform);
	Image->ZOrder = 1;
	Image->RemoveBackground();

	Transform.Location -= Image->GetImageSize() / 2;


	BoxCollider = new CAABB(&Transform, 32/*Image->GetImageSize()*/);
	GetPhysics()->AddCollider(SObjectType(this, BoxCollider, ""));
	BoxCollider->Overlap = true;
}


CProjectile::~CProjectile()
{
	GetRenderer()->DestroyImage(Image);
	Image = nullptr;
	GetPhysics()->DestroyCollider(BoxCollider);
	BoxCollider = nullptr;
}


void CProjectile::Update()
{
	int Direction = (Image->FlipX) ? -1 : 1;
	SVector2i NewLocation = Transform.Location + SVector2i(int((Speed * Direction) * *DeltaTime), 0);

	std::vector<SHitInfo> Hit;
	GetPhysics()->CheckCollisions(SObjectType(this, BoxCollider, ""), STransform(NewLocation, Transform.Rotation, Transform.Scale), Hit);

	if (!IsPendingKill)
	{
		Transform.Location = NewLocation;
	}
}



void CProjectile::OnOverlap(SHitInfo Info, std::string Tag)
{
	if (Info.HitObject && Info.HitObject != Owner && !Info.Collider->Overlap)
	{
		Info.HitObject->ApplyDamage(Damage);

		GetWorld()->DestroyObject(this);
	}
}