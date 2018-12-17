#pragma once
#include "../../../Math/Vector.h"

#include <SDL_ttf.h>
#include <string>


enum EWindowMode
{
	WindowPlayer,
	Windowed,
	Fullscreen,
	WindowBorderless
};


class CSDL_Setup
{
private:
	/// Properties

	// The main created window reference.
	SDL_Window* Window;

	// The main created renderer reference.
	SDL_Renderer* Renderer;

	// The currently used monitor info.
	SDL_DisplayMode DisplayMode;

public:
	// What type of window should be created.
	EWindowMode WindowMode;

	// The name of the window begine created.
	std::string WindowName;

	// The size of the window.
	SVector2i WindowSize;


public:
	/// Constructors
	CSDL_Setup() {}
	~CSDL_Setup();


	/// Functions

	// Creates the window and renderer.
	bool Init();


	bool CreateDisplay();


	/// Getters

	// Gets the current monitor info.
	inline const SDL_DisplayMode GetDisplayMode() const { return DisplayMode; }

	// Gets the created window reference.
	inline SDL_Window* GetWindow() const { return Window; }

	// Gets the created renderer reference.
	inline SDL_Renderer* GetRenderer() const { return Renderer; }
};