#include "SDL_Setup.h"


CSDL_Setup::~CSDL_Setup()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}


bool CSDL_Setup::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Failed to initiate SDL.");
		return false;
	}

	if (TTF_Init() != 0)
	{
		printf("Failed to initiate TFF.");
		return false;
	}

	SDL_GetCurrentDisplayMode(0, &DisplayMode);

	return CreateDisplay();
}


bool CSDL_Setup::CreateDisplay()
{
	if (Renderer)
	{
		SDL_DestroyRenderer(Renderer);
	}

	if (Window)
	{
		SDL_DestroyWindow(Window);
	}


	Uint32 Modes;
	switch (WindowMode)
	{
	case WindowPlayer:
		Modes = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_FOCUS;
		break;


	case Windowed:
		Modes = SDL_WINDOW_MAXIMIZED | SDL_WINDOW_INPUT_GRABBED;
		break;


	case Fullscreen:
		Modes = SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_GRABBED;
		break;


	case WindowBorderless:
		Modes = SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_GRABBED;
		break;
	}


	Window = SDL_CreateWindow(WindowName.c_str(), (DisplayMode.w / 2) - (WindowSize[X] / 2), (DisplayMode.h / 2) - (WindowSize[Y] / 2), WindowSize[X], WindowSize[Y], Modes);
	if (!Window)
	{
		printf("Failed to create Window.");
		SDL_Quit();
		return false;
	}

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!Renderer)
	{
		printf("Failed to create Renderer.");
		SDL_DestroyWindow(Window);
		SDL_Quit();
		return false;
	}

	return true;
}