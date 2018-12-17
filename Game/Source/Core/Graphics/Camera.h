#pragma once
#include "SDL/SDL_Setup.h"
#include "../../Math/Transform.h"


class CCamera
{
private:
	/// Properties

	SVector2i Offset;

	float* DeltaTime;

public:

	STransform Transform;

	CSDL_Setup* SDL_Setup;

	class CWorldObject* FollowObject;

	float MaxSpeed;

	bool SnapToObject;


public:
	/// Constructors

	CCamera(CSDL_Setup* Setup);


	/// Functions

	void Update();


	/// Setters

	inline void SetDeltaTime(float* DT) { DeltaTime = DT; }

	inline void SetOwnerOffset(SVector2i InOffset);

	/// Getters

};