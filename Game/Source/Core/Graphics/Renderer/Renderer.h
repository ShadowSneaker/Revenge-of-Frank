#pragma once
//#include "../SDL/SDL_Setup.h"
#include "../Images/Sprite.h"
#include "../Camera.h"

#include <vector>


// Renders In-game objects onto the screen.
class CRenderer
{
private:
	/// Properties

	// A reference to the created SDL_Setup.
	CSDL_Setup* Setup;

	// A list of all the images that should be drawn to the screen.
	std::vector<CImage*> Images;

	// A reference to the camera.
	CCamera* Camera;


public:
	/// Constructors

	// Default Constructor.
	CRenderer(CSDL_Setup* SDL_Setup, class CCamera* InCamera);

	// Deconstructor
	~CRenderer();


	/// Functions

	// Draws all the images onto the screen based off the Image's ZOrder.
	void DrawImages();

	// Adds an image to the list.
	void AddImage(CImage* Image);


	// Creates an images and renders it onto the screen.
	// @param FileName - The filepath leading to the Image bmp (starts from Content/Sprites).
	// @return - Returns a reference to the created Image.
	template <typename Type>
	Type* CreateImage(std::string FileName)
	{
		Type* NewImage = new Type(Setup->GetRenderer(), FileName);

		if (NewImage)
		{
			if (dynamic_cast<CSprite*>(NewImage))
			{
				NewImage->SetCamera(&Camera->Transform);
			}

			Images.push_back(NewImage);
			return NewImage;
		}

		delete NewImage;
		return nullptr;
	}


	// Creates an images and renders it onto the screen.
	// @return - Returns a reference to the created Image.
	template <typename Type>
	Type* CreateImage()
	{
		Type* NewImage = new Type(Setup->GetRenderer());

		if (NewImage)
		{
			if ((CSprite*)NewImage)
			{
				NewImage->SetCamera(&Camera->Transform);
			}
			Images.push_back(NewImage);
			return NewImage;
		}

		delete NewImage;
		return nullptr;
	}


	// Destroys a specified image on the screen.
	// @param Image - The image reference that should be destroyed.
	void DestroyImage(CImage* Image);


	/// Setters


	/// Getters

	// Returns a reference to the renderer.
	SDL_Renderer* GetRenderer() const { return Setup->GetRenderer(); }

	// Returns a reference to the window.
	SDL_Window* GetWindow() const { return Setup->GetWindow(); }

	// Returns the size of the window in pixels.
	SVector2i GetScreenSize() const { return Setup->WindowSize; }

};