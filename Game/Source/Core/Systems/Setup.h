#pragma once
#include "../Graphics/SDL/SDL_Setup.h"
#include "../World/World.h"


class CSetup
{
private:
	/// Properties

	// The reference to the created setup for SDL.
	CSDL_Setup* SDL_Setup;

	// The reference to the created startup world.
	CWorld* StartupWorld;

public:
	/// Constructors

	CSetup();
	~CSetup();

	/// Functions

	// Startups the world.
	void Init();
};

