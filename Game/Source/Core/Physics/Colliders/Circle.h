#pragma once
#include "Collider.h"


class CCircle :public CCollider
{
private:
	/// Properties

	// The radius of the circle (how large the circle is)
	float Radius;


public:
	/// Constructors

	// Default Constructor
	CCircle();

	// Initiates the Circle with a parent transform and a radius.
	CCircle(STransform* Transform, float SetRadius);

	// Initiates the circle with a parent, location and a radius.
	CCircle(STransform* Transform, SVector2i CenterLocation, float SetRadius);


	// Circle to box collision.
	virtual bool CheckCollision(const class CAABB* Other) const override;

	// Circle to Circle collision
	virtual bool CheckCollision(const CCircle* Other) const override;

	// Ambigous collision check. Casts down to correct collider to check for collision.
	bool CheckCollision(const CCollider* Other) const;


	/// Setters

	// Sets the radius of this circle collider.
	inline void SetRadius(float NewRadius) { Radius = NewRadius; }

	/// Getters

	// Returns the location of the center of this circle collider in worldspace.
	inline SVector2i GetCenter() const { return Location + ((Owner) ? Owner->GetWorldLocation() : 0); }

	// Returns the radius after scaling (Note scale is determined by the highest scale component in the owner).
	inline float GetRadius() const { return Radius * ((Owner) ? Owner->GetWorldScale().MaxComp() : 1.0f); }
};