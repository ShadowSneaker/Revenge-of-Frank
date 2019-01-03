#pragma once
#include "../InterfaceComponent.h"
#include "../../Images/Image.h"


// Draws an image to the Interface.
class CImageComponent :public CInterfaceComponent
{
private:
	/// Properties

	// A reference to the image class.
	CImage* Image;

public:
	/// Constructors

	// Constructor, Initiates the base image to be drawn on the screen.
	CImageComponent(SDL_Renderer* InRenderer);


	/// Functions

	// Draws the image onto the screen.
	virtual void Draw() override;

	/// Setters

	// Sets the display image based off a file path.
	// @param FilePath - the file location for the new image (starts at "Content/Sprites").
	// @param ChangeImageSize - Should the image be allowed to change size.
	inline void SetImage(const std::string FilePath, bool ChangeImageSize = true) { Image->SetImage(FilePath, ChangeImageSize); }

	/// Getters

	// Returns the drawn image on the screen.
	inline CImage* GetImage() const { return Image; }
};