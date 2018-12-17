#include "TextComponent.h"


CTextComponent::CTextComponent(SDL_Renderer* InRenderer)
	:CInterfaceComponent::CInterfaceComponent(InRenderer)
{
	Font = new CFont(InRenderer);
	Font->Transform.SetParent(&Transform);


	//Font->FontFilePath = "Content/Fonts/DejaVuSans.ttf";
	//Font->SetColour(SDL_Color{ 255,255,255 });
	
}


CTextComponent::~CTextComponent()
{
	delete Font;
}


void CTextComponent::Draw()
{
	Font->Draw();
}