#pragma once
#include "../../../Math/Transform.h"


class CImage
{
private:
	/// Properties




	// A reference to the renderer so this sprite can be drawn.
	SDL_Renderer* Renderer;


	Uint32 Flip;

	
	SDL_Color Colour;

protected:
	// The surface used to create the sprite.
	SDL_Surface* Surface;

	// The Texture that is drawn to the screen.
	SDL_Texture* Texture;
	
	// The size of the entire image in Pixels.
	SVector2i ImageSize;
	
	// The name of the file.
	std::string ImageName;

	// The default file path for sprites.
	const std::string DefaultSpritePath = "Content/Sprites/";


public:
	// The location, rotation and scale of this object.
	STransform Transform;
	
	// what order this image should be drawn.
	int ZOrder;


	bool Enable;


	bool FlipX;


	bool FlipY;



public:
	/// Constructors

	// Default constructor, Creates a sprite that can be drawn on the screen.
	CImage(SDL_Renderer* InRenderer);

	// Constructor, Creates a image that can be drawn to the screen and sets an image to be displayed
	// @param - FilePath - The path in Content/Sprites/.. of the file.
	CImage(SDL_Renderer* InRenderer, const std::string FilePath);

	// Default Deconstructor.
	~CImage();

	/// Functions
	
	// Draws the image onto the screen.
	virtual void Draw();

	// Removes the background of images (only the colour 255,0,255 will be removed from the image).
	void RemoveBackground();


protected:

	SVector2i RotateAroundParent(SVector2i ImageCenter);

public:


	/// Setters

	// Sets the image to a new image based off a file path.
	void SetImage(std::string InFilePath, bool ChangeImageSize = true);

	// Sets the multiplied colour on the image.
	void SetColour(SDL_Color NewColour);


	/// Getters

	// Gets the size of the image being displayed.
	inline SVector2i GetImageSize() const { return ImageSize; }

	// Gets the name of the image in the file.
	inline std::string GetFileName() const { return ImageName; }

	// Gets the multiplied colour on the image.
	inline SDL_Color GetColour() const { return Colour; }

protected:
	inline SDL_RendererFlip GetFlip();

	inline SDL_Renderer* GetRenderer() const { return Renderer; }

	inline SDL_Texture* GetTexture() const { return Texture; }

	inline SDL_Surface* GetSurface() const { return Surface; }

	// Gets the center point of this image.
	inline const SVector2i GetCenter();
};


struct IMAGE_ZORDER
{
	inline bool operator()(const CImage* ImgA, const CImage* ImgB)
	{
		return (ImgA->ZOrder < ImgB->ZOrder);
	}
};