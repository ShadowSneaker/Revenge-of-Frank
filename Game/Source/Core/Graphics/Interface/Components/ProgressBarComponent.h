#pragma once
#include "ImageComponent.h"

// What direction the slider should move in.
enum ESliderDirection
{
	Right,
	Left,
	Up,
	Down
};


// Draws a bar on the screen that can be given a percentage value
// to overlap with a second image.
class CProgressBarComponent :public CInterfaceComponent
{
public:
	/// Properties

	// The minimum value the Value component can be.
	float Min;

	// The maximum value the Value component can be.
	float Max;

	// The current progress the bar is at.
	float Value;

	// The background image displayed on the screen.
	CImage* Background;

	// The foreground image displayed above the background image.
	CImage* Foreground;

	// The direction this slider should move in.
	ESliderDirection SliderDirection;


public:
	/// Constructors

	// Constructor, Initiates a progress bar drawn onto the screen.
	CProgressBarComponent(SDL_Renderer* InRenderer);

	// Destructor.
	~CProgressBarComponent();


	/// Functions

	// Draws the progress bar on the screen.
	virtual void Draw() override;


	/// Setters


	/// Getters


};

// A shortened name for the progress bar component.
typedef CProgressBarComponent CProgressBar;