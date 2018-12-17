#include "Sprite.h"


CSprite::CSprite(SDL_Renderer* InRenderer)
	:CImage::CImage{ InRenderer }, Camera{ nullptr }
{}


CSprite::CSprite(SDL_Renderer* InRenderer, const std::string FilePath)
	: CImage::CImage{ InRenderer, FilePath }, Camera{ nullptr }
{}


void CSprite::Draw()
{
	SDL_Point Center = GetCenter().ToPoint();

	SVector2i Point = RotateAroundParent(GetCenter());

	SDL_Rect Rect;
	Rect.x = Point[X] + Transform.GetWorldLocation()[X] + -Camera->GetWorldLocation()[X];
	Rect.y = Point[Y] + Transform.GetWorldLocation()[Y] + -Camera->GetWorldLocation()[Y];
	Rect.w = int(GetImageSize()[X] * Transform.GetWorldScale()[X]);
	Rect.h = int(GetImageSize()[Y] * Transform.GetWorldScale()[Y]);

	//printf("%f, %f\n", Transform.GetParent()->Scale[X], Transform.GetParent()->Scale[Y]);


	SDL_RenderCopyEx(GetRenderer(), GetTexture(), NULL, &Rect, Transform.GetWorldRotation(), &Center, GetFlip());
}