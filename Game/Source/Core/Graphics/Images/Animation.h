#pragma once
#include "Sprite.h"


// Add loop boolean variable.
// If looping is false only play through once (if playing is set to true).
// if Looping is true, continuously play the animation.


class CAnimation :public CSprite
{
private:
	/// Properties

	// The total amount of images per row/column.
	SVector2i CellSize;

	// The current frame that is being displayed to the screen.
	int FrameIndex;

	// The total amount of frames the animation has.
	size_t TotalFrames;

	// The current cell that is being displayed to the screen.
	SDL_Rect Cell;

	// The current timer value before swapping images.
	float Timer;
	
	//float AnimationSpeed;

	// Determines if the animation should be playing backwards.
	bool Reversed;

public:
	// Determins if the animation should be playing.
	bool Playing;

	// The time between each frame (Time in seconds).
	float Speed;

	// Determines if the the animation should loop.
	bool Loop;


public:
	/// Constructors

	// Base Constructor, Sets up an animation.
	// @param Renderer - A reference to the renderer to draw on.
	CAnimation(SDL_Renderer* Renderer);

	// Constructor, Displays an animation on the screen with a set animation count.
	// @param Renderer - A reference to the renderer to draw on.
	// @param FilePath - The file path to for the sprite (starts in Content/Sprites/).
	CAnimation(SDL_Renderer* Renderer, std::string FilePath);

	// Deconstructor.
	~CAnimation();


	/// Functions

	// Runs every frame, updates the timers and sets the current frame.
	// @param - The current frame's DeltaTime.
	virtual void Update(float DeltaTime);

	// Draws the current frame on the screen.
	virtual void Draw() override;

	// Continues the animation from the current frame.
	void Play();

	// Stops the animation on the current frame.
	void Stop();

	// Reverses the animation on the current frame.
	void Reverse();

	// Plays the animation from the start.
	void PlayFromStart();

	// Plays the animation in reverse from the end.
	void ReverseFromEnd();


	/// Setters

	// Sets the current frame index.
	// @param Frame - The specific frame to display.
	// @param UpdateImage - Should the image instantly change to the new frame.
	void SetFrame(size_t Frame, bool UpdateImage = true);

	// Sets how many frames are in the animation.
	// @param - How many columns are in the animation.
	// @param - How many rows are in the animation.
	void SetCellCount(size_t Columns, size_t Rows);

	// Sets the animation page.
	// @param InFilePath - The filepath of the image to be set to.
	// @param Columns - How many cell columns there should be in this animation.
	// @param Rows - How many cell rows there should in this animation.
	// @param ChangeImageSize - Should the image size be allowed to change.
	virtual void SetAnimation(std::string InFilePath, size_t Columns, size_t Rows, bool ChangeImageSize = true);
	

	/// Getters

	// Gets how large each cell is (in pixels).
	inline SVector2i GetCellSize() { return SVector2i{ Cell.w, Cell.h }; }

	inline const SVector2i GetCellCenter();
};