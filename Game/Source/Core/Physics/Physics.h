#pragma once
#include "Colliders/Collider.h"

#include <vector>

// Forward Declared World Object.
class CWorldObject;


// The info used to store a collider.
struct SObjectType
{
public:
	/// Propperties

	// A reference to the object that owns the collider.
	CWorldObject* Object;

	// A reference to the collider that the object owns.
	CCollider* Collider;

	// A tag for the collider to be returned when the object is collided with.
	std::string Tag;


	/// Constructors.

	// Constructor, Default.
	SObjectType()
		:Object{ nullptr }, Collider{ nullptr }
	{}

	// Constructor, Initiates the ObjectType.
	SObjectType(CWorldObject* InObject, CCollider* InCollider, std::string FunctionTag)
		:Object{ InObject }, Collider{ InCollider }, Tag{ FunctionTag }
	{}
};


class CPhysics
{
private:
	/// Properties

	// A list of all the colliders in the level.
	std::vector<SObjectType> Objects;

	// A reference to the delta time.
	float* DeltaTime;

public:
	// The gravity value.
	float Gravity;

public:
	/// Constructors

	// Constructor, Default.
	CPhysics();


	/// Functions

	// Checks to see if any collider is colliding with the inputted collider.
	// @param Collider - The collider to be tested for collision.
	// @param NewLocation - The location the collider will be after move.
	// @param HitInfo - The Hit results found with the collision.
	// @param IgnoreSelf - Should the collider ignore itself along with all it's childeren.
	// @return - The Hit results found with the collider.
	const std::vector<SHitInfo> CheckCollisions(SObjectType Object, STransform NewLocation, std::vector<SHitInfo>& HitInfo, const bool IgnoreSelf = true);
	
	// Checks to see if any collider is colliding with the inputted collider.
	// @param Collider - The collider to be tested for collision.
	// @param HitInfo - The Hit results found with the collision.
	// @param IgnoreSelf - Should the collider ignore itself along with all it's childeren.
	// @return - The Hit results found with the collider.
	const SHitInfo CheckCollisions(CCollider* Collider, SHitInfo& HitInfo, const bool IgnoreSelf = true) const;

	// Reverses the gravity.
	inline void ReverseGravity() { Gravity *= -1.0f; }

	// Adds a collider to the list.
	void AddCollider(SObjectType Object) { Objects.push_back(Object); }

	// Removes a collider from the list.
	// @param - A reference to the collider to be destroyed.
	void DestroyCollider(CCollider* Collider);


	/// Setters

	// Sets the reference for delta time.
	inline void SetDeltaTime(float* DT) { DeltaTime = DT; }


	/// Getters

	// Returns the gravity direction.
	// 1 for up -1 for down.
	inline int GravityDirection() const { return (Gravity < 0.0f) ? 1 : -1; }
};