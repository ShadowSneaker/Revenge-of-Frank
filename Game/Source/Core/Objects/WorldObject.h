#pragma once
#include "../../Math/Transform.h"
#include "../Physics/Physics.h"
#include "../Graphics/Renderer/Renderer.h"


// The base information that is required to create an object.
struct OBJECT_CONSTRUCTOR_BASE
{
	/// Components

	// A reference to the Renderer
	CRenderer* Renderer;

	// A reference to the physics.
	CPhysics* Physics;

	// A reference to the world this object belongs to.
	class CWorld* World;

	/// Constructors

	// Constructor, Initiates the object constructor.
	OBJECT_CONSTRUCTOR_BASE(CRenderer* InRenderer, CPhysics* InPhysics, class CWorld* InWorld)
		:Renderer{ InRenderer }, Physics{ InPhysics }, World{ InWorld }
	{}
};


// The base object that can exist in the world.
class CWorldObject
{
private:
	/// Properties

	// The base information for a World Object to exist.
	OBJECT_CONSTRUCTOR_BASE Base;


protected:
	
	// Returns if this object is on the ground.
	bool Grounded;
	
	// A reference to the calculated DeltaTime.
	float* DeltaTime;

	// The velocity in the Y direction (used for jumping/falling).
	float VelY;

public:
	// Enabled when the object is being destroyed to avoid Crashes.
	bool IsPendingKill;
	
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

	// Destructor - Virtual so child objects can overwrite it and propperly delete their pointers.
	virtual ~CWorldObject();


	/// Functions

	// Runs Every Tick.
	virtual void Update() {}
	
	// Applies gravity to this object pusing it towards the ground.
	void ApplyGravity(class CCollider* Collider);

private:
	// Adjusts the location of the object until they are no longer colliding.
	void AdjustLocation(class CCollider* Collider, SHitInfo Hit);
public:

	// Function that is called whenever a collision has occurred.
	virtual void OnCollision(SHitInfo Info, std::string Tag) {}

	// Function that is called whenever a overlap collision has occurred.
	virtual void OnOverlap(SHitInfo Info, std::string Tag) {}


	/// Setters

	// Sets a reference to the calculated value of delta time.
	inline void SetDeltaTime(float* DT) { DeltaTime = DT; }

	// Applies damage to this object.
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

	// Compares the tag of this object with an inputted object's tag.
	inline bool CompareTag(std::string InTag) const { return (Tag == InTag); }
};