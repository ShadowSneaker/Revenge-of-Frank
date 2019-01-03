#pragma once
#include <SDL.h>


// The value representation for what keys are pressed and released.
enum KEYS_PRESSED
{
	KEY_ESCAPE, KEY_D, KEY_A, KEY_SPACE, KEY_G, KEY_F, SIZE_OF_KEYS_PRESSED
};


// The input handler for the player.
// Reads the user input and enables/disables the bound keys.
class CInput
{
private:
	/// Properties

	// The current key that is pressed/released.
	SDL_Event* Event;

	// An array of all bound keys, each value represents if they are pressed or not.
	bool KeysPressed[SIZE_OF_KEYS_PRESSED];

public:
	/// Constructors

	// Constructor, Default
	CInput();

	// Destructor
	~CInput();


	/// Functions

	// Runs every frame.
	void Update();

	/// Setters


	/// Getters

	// Gets the current event.
	inline SDL_Event* GetEvent() const { return Event; }

	// Returns if a specific key is pressed.
	inline bool KeyIsPressed(KEYS_PRESSED Key) const { return KeysPressed[Key]; }
};