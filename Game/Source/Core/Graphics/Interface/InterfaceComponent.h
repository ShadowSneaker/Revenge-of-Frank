#pragma once
#include "../../../Math/Transform.h"

#include <SDL.h>


class CInterfaceComponent
{
private:
	/// Properties

	SDL_Renderer* Renderer;

public:
	STransform Transform;

	bool Enable;


public:
	/// Constructors
	CInterfaceComponent(SDL_Renderer* InRenderer);
	

	/// Functions

	virtual void Draw() = 0;


	/// Setters


	/// Getters

protected:
	inline SDL_Renderer* GetRenderer() const { return Renderer; }
};