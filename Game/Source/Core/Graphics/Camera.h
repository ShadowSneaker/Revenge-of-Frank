#pragma once
#include "SDL/SDL_Setup.h"
#include "../../Math/Transform.h"


// The camera that the player will see the world through.
class CCamera
{
private:
	/// Properties

	// The offset the camera should be at when focusing on a target.
	SVector2i Offset;

	// A reference to the delta time.
	float* DeltaTime;

public:
	// The transform of the camera.
	STransform Transform;

	// A reference to the SDL Setup.
	CSDL_Setup* SDL_Setup;

	// The object that the camera should look at.
	class CWorldObject* FollowObject;

	// The speed the camera can lerp to the follow object.
	float MaxSpeed;

	// Should the camera snap to the object instead of lerping?
	bool SnapToObject;


public:
	/// Constructors

	// Constructor, Initiates the camera.
	CCamera(CSDL_Setup* Setup);


	/// Functions

	// Runs every frame.
	void Update();


	/// Setters

	// Sets the reference for DeltaTime.
	inline void SetDeltaTime(float* DT) { DeltaTime = DT; }

	// Sets the offset the camera should be at.
	inline void SetOwnerOffset(SVector2i InOffset);

	/// Getters

};