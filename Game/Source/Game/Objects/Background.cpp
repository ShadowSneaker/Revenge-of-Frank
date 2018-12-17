#include "Background.h"


CBackground::CBackground(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform)
	:CWorldObject::CWorldObject{ Base, InTransform }
{
	Image = GetRenderer()->CreateImage<CSprite>("Backgrounds/Background.bmp");
	Image->ZOrder = -10;
}


CBackground::~CBackground()
{
	GetRenderer()->DestroyImage(Image);
	Image = nullptr;
}
