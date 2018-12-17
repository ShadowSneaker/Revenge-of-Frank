#pragma once
#include "../../../Math/Transform.h"



enum EColliderType
{
	Box,
	Circle,
	Point,
	Line
};


struct SHitInfo
{
	class CWorldObject* HitObject;

	class CCollider* Collider;

	bool Hit;
};


class CCollider
{
protected:
	/// Properties

	// The format type this collider is (IE: Box collider, Circle Collider, etc).
	EColliderType Type;

	// A referance to the owner's transform.
	STransform* Owner;

public:
	// The relative location of this collider.
	SVector2i Location;

	// Should this object be overlapable.
	bool Overlap;

public:
	/// Constructors

	// Default constructor.
	CCollider();

	// Constructor, Initiates the collider with an owner.
	CCollider(STransform* Transform);

	// Constructor, INitiates the collider with an owner and a location.
	CCollider(STransform* Transform, SVector2i InLocation);


	/// Functions

	// Overrided function used to calculate this collider with a AABB collider.
	// @param Other - A reference to the AABB collider that this collider will test collisions against.
	// @return - Returns true if the colliders are colliding.
	virtual bool CheckCollision(const class CAABB* Other) const { return false; }

	// Overrided function used to calculate this collider with a Circle collider.
	// @param Other - A reference to the circle collider that this collider will test collisions against.
	// @return - Returns true if the colliders are colliding.
	virtual bool CheckCollision(const class CCircle* Other) const { return false; }

	// Ambigous collision check. Casts down to correct collider to check for collision.
	bool CheckCollision(const CCollider* Other) const;


	/// Setters

	// Sets the owner transform of this collider.
	inline void SetOwner(STransform* Transform) { Owner = Transform; }

	inline void SetType(EColliderType NewType) { Type = NewType; }

	/// Getters

	// Gets the type of collider this collider is.
	inline EColliderType GetType() const { return Type; }

	inline SVector2i GetWorldLocation() const { return Location + ((Owner) ? Owner->GetWorldLocation() : 0); }

};


