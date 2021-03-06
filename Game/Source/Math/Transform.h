#pragma once
#include "Vector.h"

// Stores the location, rotation and scale of an object in the world.
struct STransform
{
private:
	/// Properties

	// The parent's transform, used to get worldspace.
	STransform* Parent;

	// A reference to this transform's child - should be an array/vector.
	STransform* Child;

public:
	// The Object's Relative Location.
	SVector2i Location;

	// The Object's Relative Rotation.
	float Rotation;

	// The Object's Relative Scale.
	SVector2 Scale;


public:
	/// Constructors

	// Default Constructor.
	STransform();

	// Inits all components of the Transform.
	STransform(SVector2i InLocation, float InRotation, SVector2 InScale);

	~STransform();

	/// Functions

	// Combines two Transforms together.
	STransform Merge(const STransform& Other) const;


	/// Getters

	// This Object's components in worldspace.
	STransform GetWorldTransform() { return Merge(*Parent); }

	// This Object's Location in worldspace.
	SVector2i GetWorldLocation() { return Location + ((Parent) ? Parent->GetWorldLocation() : 0); }

	// This Object's Rotation in worldspace.
	float GetWorldRotation() { return Rotation + ((Parent) ? Parent->GetWorldRotation() : 0.0f); }

	// This object's scale in worldspace.
	SVector2 GetWorldScale() { return Scale * ((Parent) ? Parent->GetWorldScale() : 1.0f); }

	// Returns this object's parent transform reference.
	STransform* GetParent() const { return Parent; }
	
	/// Setters

	// Sets the parent of this Transform (used to get worldspace).
	inline void SetParent(STransform* Transform) { Parent = Transform; Parent->Child = this; }
	// Assuming the parent has 2 or more childeren, the child variable will be overridden and will only have a pointer to the last added child.
};