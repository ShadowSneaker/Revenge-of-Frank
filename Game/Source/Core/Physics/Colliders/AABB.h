#pragma once
#include "Collider.h"


class CAABB :public CCollider
{
public:

	SVector2i Extents;


	SVector2 Scale;

	bool Debug = true;
public:
	CAABB();

	CAABB(STransform* Transform);
	CAABB(STransform* Transform, SVector2i InExtents);
	CAABB(STransform* Transform, SVector2i Location, SVector2i InExtents);


	/// Functions

	// Test collision between this (AABB) and a AABB Collider.
	virtual bool CheckCollision(const CAABB* Other) const override;

	// Test collision between this (AABB) and a Circle Collider.
	virtual bool CheckCollision(const class CCircle* Other) const override;

	bool CheckCollision(const CCollider* Other) const;


	/// Setters


	/// Getters

	// Gets the Box Collider's minimum extents in the worldspace.
	inline const SVector2 GetMinExtent() const { return Location.ToFloat() + ((Owner) ? Owner->GetWorldLocation().ToFloat() : 0.0f); }

	// Gets the Box Colliders's maximum extents in the worldspace.
	inline const SVector2 GetMaxExtent() const { return Extents.ToFloat() * (Scale * ((Owner) ? Owner->GetWorldScale() : 1.0f)) + ((Owner) ? Owner->GetWorldLocation().ToFloat() : 0.0f); }
};