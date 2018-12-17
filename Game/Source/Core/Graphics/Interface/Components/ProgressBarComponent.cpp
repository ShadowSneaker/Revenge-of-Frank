#include "ProgressBarComponent.h"
#include "../../../../Math/MathStatics.h"


CProgressBarComponent::CProgressBarComponent(SDL_Renderer* InRenderer)
	:CInterfaceComponent::CInterfaceComponent(InRenderer)
{
	Min = 0.0f;
	Max = 1.0f;
	Value = 0.0f;

	SliderDirection = ESliderDirection::Right;

	Background = new CImage(InRenderer, "UI/Image.bmp");
	Background->Transform.SetParent(&Transform);
	Foreground = new CImage(InRenderer, "UI/Image.bmp");
	Foreground->Transform.SetParent(&Transform);
}


CProgressBarComponent::~CProgressBarComponent()
{
	delete Background;
	delete Foreground;
}


void CProgressBarComponent::Draw()
{
	Background->Draw();

	Clamp(Min, Max, Value);

	switch (SliderDirection)
	{
	case Right:
		Foreground->FlipX = false;
		Foreground->Transform.Scale[X] = Percent(Min, Max, Value);
		break;


	case Left:
		// Flip the image to have the pivot on the other size.
		Foreground->Transform.Scale[X] = Percent(Min, Max, Value);
		break;


	case Up:

		break;


	case Down:
		Foreground->Transform.Scale[Y] = (Value / Max);

		break;
	}

	// Get percentage
	//Foreground->Transform.Scale[X] = (Value / Max);

	Foreground->Draw();
}