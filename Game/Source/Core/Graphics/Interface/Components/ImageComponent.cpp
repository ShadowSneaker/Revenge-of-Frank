#include "ImageComponent.h"


CImageComponent::CImageComponent(SDL_Renderer* InRenderer)
	:CInterfaceComponent::CInterfaceComponent{ InRenderer }
{
	Image = new CImage(InRenderer);
	Image->Transform.SetParent(&Transform);
}


void CImageComponent::Draw()
{
	Image->Draw();
}