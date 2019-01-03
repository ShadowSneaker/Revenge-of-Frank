#pragma once
#include "../../../Math/Transform.h"

#include <SDL.h>


// A base component type that can be put onto the Interface.
class CInterfaceComponent
{
private:
	/// Properties

	// A reference of the renderer to draw stuff to.
	SDL_Renderer* Renderer;

public:
	// The location, rotation and scale of this component.
	STransform Transform;

	// Should this component be enabled.
	bool Enable;


public:
	/// Constructors

	// Constructor, Initiates a base component to be drawn onto the screen.
	CInterfaceComponent(SDL_Renderer* InRenderer);
	

	/// Functions

	// A empty Draw function created to be overwritten by child components.
	virtual void Draw() = 0;


	/// Setters


	/// Getters

protected:
	// Returns a reference to the renderer.
	inline SDL_Renderer* GetRenderer() const { return Renderer; }
};