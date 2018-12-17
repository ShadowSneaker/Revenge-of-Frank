#include "Obstacle.h"
#include "../../../Core/Graphics/Renderer/Renderer.h"


CObstacle::CObstacle(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform)
	:CWorldObject::CWorldObject{ Base, InTransform }
{
	Image = GetRenderer()->CreateImage<CSprite>("Wall.bmp");
	Image->Transform.SetParent(&Transform);

	BoxCollider = new CAABB(&Transform, Image->GetImageSize());
	GetPhysics()->AddCollider(SObjectType(this, BoxCollider, ""));
}


CObstacle::~CObstacle()
{
	GetRenderer()->DestroyImage(Image);
	Image = nullptr;
	//delete Image;
	GetPhysics()->DestroyCollider(BoxCollider);
	BoxCollider = nullptr;
	//delete BoxCollider;
}