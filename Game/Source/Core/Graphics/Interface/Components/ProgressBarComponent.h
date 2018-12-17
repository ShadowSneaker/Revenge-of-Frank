#pragma once
#include "ImageComponent.h"


enum ESliderDirection
{
	Right,
	Left,
	Up,
	Down
};


class CProgressBarComponent :public CInterfaceComponent
{
public:
	/// Properties

	float Min;

	float Max;

	float Value;

	CImage* Background;

	CImage* Foreground;


	ESliderDirection SliderDirection;


public:
	/// Constructors

	CProgressBarComponent(SDL_Renderer* InRenderer);

	~CProgressBarComponent();


	/// Functions

	virtual void Draw() override;


private:
	
public:

	/// Setters


	/// Getters


};

typedef CProgressBarComponent CProgressBar;