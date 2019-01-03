#include "Goal.h"
#include "../../Core/Graphics/Renderer/Renderer.h"
#include "../../Core/Physics/Colliders/AABB.h"
#include "../../Core/World/World.h"
#include "../../Core/Graphics/Interface/Components/TextComponent.h"


CGoal::CGoal(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform)
	:CWorldObject::CWorldObject{ Base, InTransform }
{
	Image = GetRenderer()->CreateImage<CSprite>("OmegaSmiley.bmp");
	Image->Transform.SetParent(&Transform);

	BoxCollider = new CAABB(&Transform, Image->GetImageSize());
	GetPhysics()->AddCollider(SObjectType(this, BoxCollider, ""));
	BoxCollider->Overlap = true;

	Won = false;
}


CGoal::~CGoal() 
{
	GetRenderer()->DestroyImage(Image);
	Image = nullptr;
	GetPhysics()->DestroyCollider(BoxCollider);
	BoxCollider = nullptr;
}


void CGoal::OnOverlap(SHitInfo Info, std::string Tag)
{
	if (Info.HitObject->CompareTag("Player") && !Won)
	{
		Won = true;
		if (GetWorld()->LoadedLevel() == "Level1.txt")
		{
			GetWorld()->LoadLevel("Level2.txt");
		}
		else if (GetWorld()->LoadedLevel() == "Level2.txt")
		{
			GetWorld()->LoadLevel("Win.txt");
		}
	}
}