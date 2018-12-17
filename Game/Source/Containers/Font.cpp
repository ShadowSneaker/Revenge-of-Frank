#include "Font.h"


CFont::CFont(SDL_Renderer* InRenderer)
	:CImage::CImage{ InRenderer }
{
	ImageName = "DejaVuSans.ttf";
	FontSize = 16;
	Colour = SDL_Color{ 255, 255, 255 };
	Text = "Sample Text";

	SetFont(ImageName);
}


CFont::CFont(SDL_Renderer* InRenderer, const std::string InFilePath)
	:CImage::CImage{ InRenderer }
{
	FontSize = 16;
	Colour = SDL_Color{ 255, 255, 255 };
	Text = "Sample Text";
	
	SetFont(InFilePath);
}


CFont::~CFont()
{
	TTF_CloseFont(Font);
}


void CFont::DestroyText()
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


void CFont::SetFont(const std::string InFilePath)
{
	ImageName = InFilePath;

	if (Font)
	{
		TTF_CloseFont(Font);
	}

	Font = TTF_OpenFont((BasePath + InFilePath).c_str(), FontSize);
	SetColour(Colour);
}


void CFont::SetText(const std::string NewText)
{
	Text = NewText;
	DestroyText();

	if (Font)
	{
		Surface = TTF_RenderText_Solid(Font, Text.c_str(), Colour);
		if (!Surface)
		{
			printf("Surface failed to load!\n");
			printf("%s\n", SDL_GetError());
			return;
		}

		Texture = SDL_CreateTextureFromSurface(GetRenderer(), Surface);
		if (!Texture)
		{
			printf("Surface for font not loaded! \n");
			printf("%s\n", SDL_GetError());
			SDL_FreeSurface(Surface);
			return;
		}
	}

	SDL_QueryTexture(Texture, NULL, NULL, &ImageSize[X], &ImageSize[Y]);
}


void CFont::SetColour(SDL_Color NewColour)
{
	Colour = NewColour;
	SetText(Text);
}


void CFont::SetFontSize(size_t NewFontSize)
{
	FontSize = NewFontSize;
	SetFont(GetFileName());
}