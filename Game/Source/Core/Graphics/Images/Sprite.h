#pragma once
#include "Image.h"


class CSprite :public CImage
{
protected:
	STransform* Camera;



public:
	CSprite(SDL_Renderer* InRenderer);

	CSprite(SDL_Renderer* InRenderer, const std::string FilePath);


	virtual void Draw() override;


	/// Setters
	inline void SetCamera(STransform* InCamera) { Camera = InCamera; }


	/// Getters
};