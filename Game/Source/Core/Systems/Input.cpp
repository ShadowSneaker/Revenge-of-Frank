#include "Input.h"


CInput::CInput()
{
	Event = new SDL_Event();
}


CInput::~CInput()
{
	delete Event;
}


void CInput::Update()
{
	while (SDL_PollEvent(Event) != NULL)
	{
		if (Event->type == SDL_KEYDOWN)
		{
			SDL_Keycode KeyPressed = Event->key.keysym.sym;

			switch (KeyPressed)
			{
			case SDLK_ESCAPE:
				KeysPressed[KEY_ESCAPE] = true;
				break;

			case SDLK_d:
				KeysPressed[KEY_D] = true;
				break;


			case SDLK_a:
				KeysPressed[KEY_A] = true;
				break;

			case SDLK_SPACE:
				KeysPressed[KEY_SPACE] = true;
				break;

			case SDLK_g:
				KeysPressed[KEY_G] = true;
				break;

			case SDLK_f:
				KeysPressed[KEY_F] = true;
				break;
			}
		}
		else if (Event->type == SDL_KEYUP)
		{
			SDL_Keycode KeyPressed = Event->key.keysym.sym;

			switch (KeyPressed)
			{
			case SDLK_d:
				KeysPressed[KEY_D] = false;
				break;

			case SDLK_a:
				KeysPressed[KEY_A] = false;
				break;

			case SDLK_SPACE:
				KeysPressed[KEY_SPACE] = false;
				break;

			case SDLK_g:
				KeysPressed[KEY_G] = false;
				break;

			case SDLK_f:
				KeysPressed[KEY_F] = false;
				break;
			}
		}
	}
}