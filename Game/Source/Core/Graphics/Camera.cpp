#include "Camera.h"
#include "../Objects/WorldObject.h"
#include "../../Math/MathStatics.h"


CCamera::CCamera(CSDL_Setup* Setup)
	:SDL_Setup{ Setup }
{
	SetOwnerOffset(0);

	MaxSpeed = 4.0f;
	SnapToObject = false;
}


void CCamera::Update()
{
	if (FollowObject)
	{
		if (SnapToObject || !DeltaTime) 
		{
			Transform.Location = FollowObject->Transform.Location + Offset;
		}
		else
		{
			SVector2i LerpAmount;
			LerpAmount[X] = int(Lerp((float)Transform.Location[X] - Offset[X], (float)FollowObject->Transform.Location[X], MaxSpeed * *DeltaTime));
			LerpAmount[Y] = int(Lerp((float)Transform.Location[Y] - Offset[Y], (float)FollowObject->Transform.Location[Y], MaxSpeed * *DeltaTime));

			Transform.Location = LerpAmount + Offset;
		}
	}
}


void CCamera::SetOwnerOffset(SVector2i InOffset)
{
	Offset = (SDL_Setup->WindowSize / -2) + InOffset;
}