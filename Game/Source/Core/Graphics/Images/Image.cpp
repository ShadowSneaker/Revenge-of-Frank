#include "Image.h"


CImage::CImage(SDL_Renderer* InRenderer)
	:Renderer{ InRenderer }, Enable{ true }
{
	Transform.Scale = 1.0f;
	ZOrder = 0;
}


CImage::CImage(SDL_Renderer* InRenderer, const std::string InFilePath)
	: Renderer{ InRenderer }, ImageName{ InFilePath }, Enable{ true }
{
	SetImage(ImageName, true);
	Transform.Scale = 1.0f;
	ZOrder = 0;
}


CImage::~CImage()
{
	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}

	if (Surface)
	{
		SDL_FreeSurface(Surface);
		Surface = nullptr;
	}
}


void CImage::Draw()
{
	SDL_Point Center = GetCenter().ToPoint();
	
	
	SVector2i Point = RotateAroundParent(GetCenter());
	

	SDL_Rect Rect;
	Rect.y = Point[Y] + Transform.GetWorldLocation()[Y];
	Rect.x = Point[X] + Transform.GetWorldLocation()[X];
	Rect.w = int(ImageSize[X] * Transform.GetWorldScale()[X]);
	Rect.h = int(ImageSize[Y] * Transform.GetWorldScale()[Y]);



	

	SDL_RenderCopyEx(Renderer, Texture, NULL, &Rect, Transform.GetWorldRotation(), &Center, GetFlip());

}


void CImage::RemoveBackground()
{
	Uint32 ColourKey = SDL_MapRGB(Surface->format, 255, 0, 255);
	SDL_SetColorKey(Surface, SDL_TRUE, ColourKey);

	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}

	Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
	if (!Texture)
	{
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return;
	}
}


void CImage::SetImage(std::string InFilePath, bool ChangeImageSize)
{
	ImageName = InFilePath;

	if (Texture)
	{
		SDL_DestroyTexture(Texture);
		Texture = nullptr;
	}

	if (Surface)
	{
		SDL_FreeSurface(Surface);
		Surface = nullptr;
	}

	Surface = SDL_LoadBMP((DefaultSpritePath + InFilePath).c_str());
	if (!Surface)
	{
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return;
	}

	Texture = SDL_CreateTextureFromSurface(Renderer, Surface);
	if (!Texture)
	{
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return;
	}

	if (ChangeImageSize)
	{
		SDL_QueryTexture(Texture, NULL, NULL, &ImageSize[X], &ImageSize[Y]);
	}
}


void CImage::SetColour(SDL_Color NewColor)
{
	Colour = NewColor;

	SDL_SetTextureColorMod(Texture, NewColor.r, NewColor.g, NewColor.b);
	SDL_SetTextureAlphaMod(Texture, NewColor.a);
}


inline SDL_RendererFlip CImage::GetFlip()
{
	Flip = SDL_FLIP_NONE;

	if (FlipY)
	{
		Flip += SDL_FLIP_VERTICAL;
	}

	if (FlipX)
	{
		Flip += SDL_FLIP_HORIZONTAL;
	}

	return SDL_RendererFlip(Flip);
}


SVector2i CImage::RotateAroundParent(SVector2i ImageCenter)
{

	SVector2i Point{ 0 };
	SDL_Point Center = ImageCenter.ToPoint();
	/*if (Transform.GetParent()->GetParent())
	{
		float C = cos(Transform.GetParent()->GetParent()->Rotation);
		float S = sin(Transform.GetParent()->GetParent()->Rotation);

		Point = Transform.GetParent()->GetParent()->GetWorldLocation();

		Point[X] += (ImageSize[X] * Transform.GetParent()->GetParent()->GetWorldScale()[X]) / 2;
		Point[Y] += (ImageSize[Y] * Transform.GetParent()->GetParent()->GetWorldScale()[Y]) / 2;




		Point[X] -= Center.x;
		Point[Y] -= Center.y;


		float xNew = (Point[X] * C) - (Point[Y] * S);
		float yNew = (Point[X] * S) + (Point[Y] * C);

		Point[X] = xNew + Center.x;
		Point[Y] = yNew + Center.y;
	}*/

	return Point;
}


inline const SVector2i CImage::GetCenter()
{
	SVector2i Result;
	Result[X] = int(ImageSize[X] * Transform.GetWorldScale()[X]) / 2;
	Result[Y] = int(ImageSize[Y] * Transform.GetWorldScale()[Y]) / 2;
	return Result;
}