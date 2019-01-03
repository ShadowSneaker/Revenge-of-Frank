#pragma once
#include "../Core/Graphics/Images/Image.h"

#include <SDL_ttf.h>


// This class displays font onto the screen using a font file sheet.
class CFont : public CImage
{
private:
	/// Properties

	// A reference to the created font
	TTF_Font* Font;

	// The path leading to the base root folder where all fonts are stored.
	const std::string BasePath = "Content/Fonts/";

	// The text this font page displays
	std::string Text;

	// The colour the text is.
	SDL_Color Colour;

	// The size of the font displayed.
	size_t FontSize;

public:
	///Constructors

	// Constructor, Initiates a base Font that can be displayed on the screen.
	CFont(SDL_Renderer* InRenderer);

	//Constructor, Initiates a Font using an inputted font based on file location.
	CFont(SDL_Renderer* InRenderer, const std::string FilePath);

	// Default Destructor.
	~CFont();


	/// Functions

private:
	// Destroys the Texture and Surface of this font.
	void DestroyText();
public:


	/// Setters

	// Sets the font type to be an inputted font type based on file location.
	void SetFont(const std::string InFilePath);

	// Set the display text of this font.
	void SetText(const std::string NewText);
	
	// Sets the display colour of this font.
	void SetColour(SDL_Color NewColor);

	// Set the display size of this font.
	void SetFontSize(size_t NewSize);


	/// Getters

	// Returns the display text of this font.
	inline std::string GetText() const { return Text; }

	// Returns the display colour of this font.
	inline SDL_Color GetColour() const { return Colour; }

	// Returns the display size of this font.
	inline size_t GetFontSize() const { return FontSize; }
};