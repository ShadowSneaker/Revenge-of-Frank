#pragma once
#include <SDL.h>


enum KEYS_PRESSED
{
	KEY_ESCAPE, KEY_D, KEY_A, KEY_SPACE, KEY_G, SIZE_OF_KEYS_PRESSED
};


class CInput
{
private:
	/// Properties

	SDL_Event* Event;
	bool KeysPressed[SIZE_OF_KEYS_PRESSED];

public:
	/// Constructors

	CInput();
	~CInput();


	void Update();

	/// Setters


	/// Getters

	inline SDL_Event* GetEvent() const { return Event; }

	inline bool KeyIsPressed(KEYS_PRESSED Key) const { return KeysPressed[Key]; }
};