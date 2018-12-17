#pragma once
#include "Colliders/Collider.h"

#include <vector>


class CWorldObject;


struct SObjectType
{
public:
	CWorldObject* Object;
	CCollider* Collider;
	std::string Tag;


	/// Constructors.

	SObjectType()
		:Object{ nullptr }, Collider{ nullptr }
	{}

	SObjectType(CWorldObject* InObject, CCollider* InCollider, std::string FunctionTag)
		:Object{ InObject }, Collider{ InCollider }, Tag{ FunctionTag }
	{}
};


class CPhysics
{
private:
	/// Properties

	std::vector<SObjectType> Objects;

	float* DeltaTime;

	

public:
	float Gravity;

public:
	/// Constructors

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

	void DestroyCollider(CCollider* Collider);


	/// Setters

	inline void SetDeltaTime(float* DT) { DeltaTime = DT; }


	/// Getters

	inline int GravityDirection() const { return (Gravity < 0.0f) ? 1 : -1; }

};