#pragma once
#include "Collider.h"


// A Axis Aligned Bounding Box.
class CAABB :public CCollider
{
public:
	/// Components

	// The furthest X and Y extents of this collider.
	SVector2i Extents;

	// The scale of this collider.
	SVector2 Scale;

public:
	/// Constructors

	// Constructor, Default.
	CAABB();

	// Constructor, Initiates the AABB at a specific transform.
	// @param Transform - The parent transform.
	CAABB(STransform* Transform);

	// Constructor, Initiates the AABB at a specific transform with default extents.
	// @param Transform - The parent transform.
	// @param InExtents - How large the AABB is in width/height.
	CAABB(STransform* Transform, SVector2i InExtents);

	// Constructor, Initiates the AABB at a specific transform with default extents.
	// @param Transform - The parent transform.
	// @param Location - the location this AABB will be created at.
	// @param InExtents - How large the AABB is in width/height.
	CAABB(STransform* Transform, SVector2i Location, SVector2i InExtents);


	/// Functions

	// Test collision between this (AABB) and a AABB Collider.
	virtual bool CheckCollision(const CAABB* Other) const override;

	// Test collision between this (AABB) and a Circle Collider.
	virtual bool CheckCollision(const class CCircle* Other) const override;

	// Test collision between this (AABB) and an Ambiguous Collider.
	// This will find the collider type of the other collider and use the appropriate collisition detection.
	bool CheckCollision(const CCollider* Other) const;


	/// Setters


	/// Getters

	// Gets the Box Collider's minimum extents in the worldspace.
	inline const SVector2 GetMinExtent() const { return Location.ToFloat() + ((Owner) ? Owner->GetWorldLocation().ToFloat() : 0.0f); }

	// Gets the Box Colliders's maximum extents in the worldspace.
	inline const SVector2 GetMaxExtent() const { return Extents.ToFloat() * (Scale * ((Owner) ? Owner->GetWorldScale() : 1.0f)) + ((Owner) ? Owner->GetWorldLocation().ToFloat() : 0.0f); }
};