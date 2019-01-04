#pragma once
#include "Image.h"

// A image that moves in the world relative to the main camera.
class CSprite :public CImage
{
protected:
	/// Properties

	// A reference to the camera's transform.
	STransform* Camera;


public:
	/// Constructors

	// Constructor, Initiates a empty sprite.
	CSprite(SDL_Renderer* InRenderer);

	// Constructor, Initiates a sprite with an image based off a file path.
	// @param FilePath - The local file path to the image (starts at "Content/Sprites/").
	CSprite(SDL_Renderer* InRenderer, const std::string FilePath);


	/// Functiosn

	// Draws the Animation onto the screen.
	virtual void Draw() override;


	/// Setters

	// Sets the camera reference to an imputted transform reference.
	inline void SetCamera(STransform* InCamera) { Camera = InCamera; }


	/// Getters
};