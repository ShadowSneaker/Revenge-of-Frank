#include "Goal.h"
#include "../../Core/Graphics/Renderer/Renderer.h"
#include "../../Core/Physics/Colliders/AABB.h"
#include "../../Core/World/World.h"
#include "../../Core/Graphics/Interface/Components/TextComponent.h"

//void TestFunction(SHitInfo Info) {}

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
	//delete Image;
	GetPhysics()->DestroyCollider(BoxCollider);
	BoxCollider = nullptr;
	//delete BoxCollider;
}


void CGoal::OnOverlap(SHitInfo Info, std::string Tag)
{
	if (Info.HitObject->CompareTag("Player") && !Won)
	{
		Won = true;
		//printf("Game Won!");
		GetWorld()->LoadLevel("Level2.txt");
		//CTextComponent* Text = GetWorld()->GetUI()->AddComponent<CTextComponent>(SVector2i((GetRenderer()->GetScreenSize()[X] / 2) - 50, 10));
		//Text->SetFontSize(42);
		//Text->SetText("You Win!");
		//GetWorld()->QuitGame();
	}
}