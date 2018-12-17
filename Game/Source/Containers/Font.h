#pragma once
#include "../Core/Graphics/Images/Image.h"

#include <SDL_ttf.h>


class CFont : public CImage
{
private:
	/// Properties


	TTF_Font* Font;


	const std::string BasePath = "Content/Fonts/";


	//std::string FilePath;


	//SDL_Renderer* Renderer;
	
	//SDL_Surface* Surface;

	//SDL_Texture* Texture;

	
	std::string Text;

	
	SDL_Color Colour;

	
	size_t FontSize;

public:
	///Constructors


	CFont(SDL_Renderer* InRenderer);


	CFont(SDL_Renderer* InRenderer, const std::string FilePath);


	~CFont();


	/// Functions

private:
	void DestroyText();
public:


	/// Setters

	void SetFont(const std::string InFilePath);


	void SetText(const std::string NewText);
	

	void SetColour(SDL_Color NewColor);


	void SetFontSize(size_t NewSize);


	/// Getters

	
	inline std::string GetText() const { return Text; }


	inline SDL_Color GetColour() const { return Colour; }


	inline size_t GetFontSize() const { return FontSize; }
};