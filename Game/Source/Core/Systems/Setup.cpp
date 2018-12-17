#include "Setup.h"



CSetup::CSetup()
{
	SDL_Setup = new CSDL_Setup();
	SDL_Setup->WindowName = "Name of Window";
	SDL_Setup->WindowSize = SVector2i(1280, 720);
	SDL_Setup->WindowMode = WindowPlayer;
	SDL_Setup->Init();

	StartupWorld = new CWorld(SDL_Setup);
}


CSetup::~CSetup()
{
	delete StartupWorld;
	delete SDL_Setup;
}


void CSetup::Init()
{
	StartupWorld->GameLoop();
}