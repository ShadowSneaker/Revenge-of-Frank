#pragma once
#include "../../Math/Transform.h"
#include "../Physics/Physics.h"
#include "../Graphics/Renderer/Renderer.h"

//class CRenderer;
//class CPhysics;


struct OBJECT_CONSTRUCTOR_BASE
{
	// Reference to the Renderer
	CRenderer* Renderer;

	CPhysics* Physics;

	class CWorld* World;


	OBJECT_CONSTRUCTOR_BASE(CRenderer* InRenderer, CPhysics* InPhysics, class CWorld* InWorld)
		:Renderer{ InRenderer }, Physics{ InPhysics }, World{ InWorld }
	{}
};


class CWorldObject
{
private:
	/// Properties

	// A reference to the created Renderer.
	//SDL_Renderer* Renderer;

	// The base information for a World Object to exist.
	OBJECT_CONSTRUCTOR_BASE Base;

	// A stored reference of the world.
	//class CWorld* World;


protected:
	// Returns if this object is on the ground.
	bool Grounded;
	
	// A reference to the calculated DeltaTime.
	float* DeltaTime;

	// The velocity in the Y direction (used for jumping/falling).
	float VelY;

public:
	// Enables/Disables this object.
	bool Active;
	
	// This object's position, rotation and scale.
	STransform Transform;

	// Allows this Object to react to gravity (Object requires a collider for gravity).
	bool EnableGravity;

	// A string to go with a object allowing objects to have unique names.
	std::string Tag;

public:

	/// Constructors

	// Constructor, Initiates the WorldObject with the vital info.
	CWorldObject(OBJECT_CONSTRUCTOR_BASE InBase, STransform InTransform);

	virtual ~CWorldObject();

	/// Functions

	// Runs Every Tick.
	virtual void Update() {}
	
	// Applies gravity to this object pusing it towards the ground.
	void ApplyGravity(class CCollider* Collider);

private:
	void AdjustLocation(class CCollider* Collider, SHitInfo Hit);
public:

	virtual void OnCollision(SHitInfo Info, std::string Tag) {}


	virtual void OnOverlap(SHitInfo Info, std::string Tag) {}


	/// Setters

	// Sets a reference to the calculated value of delta time.
	inline void SetDeltaTime(float* DT) { DeltaTime = DT; }

	// Sets a reference to the world.
	//inline void SetWorld(class CWorld* InWorld) { World = InWorld; }

	virtual float ApplyDamage(const float Damage) { return 0.0f; }


	/// Getters

	// Returns a reference to the world.
	inline class CWorld* GetWorld() const { return Base.World; }

	// Returns a reference to the renderer.
	CRenderer* GetRenderer() const { return Base.Renderer; }

	// Returns a reference to the physics object.
	CPhysics* GetPhysics() const { return Base.Physics; }

	// Returns if this object is on the ground.
	inline bool OnGround() { return Grounded; }

	// Compares the tag of this object with an inputted object;
	inline bool CompareTag(std::string InTag) const { return (Tag == InTag); }
};