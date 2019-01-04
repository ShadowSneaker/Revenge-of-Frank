#pragma once
#include "../../../../Core/Objects/WorldObject.h"


// A object that flies in a single direction and applies damage to the first entity it hits.
class CProjectile : public CWorldObject
{
private:
	/// Properties

	// A reference of the collider on this projectile.
	class CAABB* BoxCollider;

	// A reference of the image on this projectile.
	CSprite* Image;

public:
	// Determines how fast this projectile flies.
	float Speed;

	// Determines how much damage this projectile deals on contact.
	float Damage;

	// The Object that created the projectile.
	CWorldObject* Owner;


public:
	/// Constructors

	// Constructor, Default
	CProjectile(OBJECT_CONSTRUCTOR_BASE Base, STransform Transform);

	// Destructor
	virtual ~CProjectile() override;


	/// Functions 

	// Runs every frame.
	virtual void Update() override;

	// Called when this object's collider overlapped another collider.
	virtual void OnOverlap(SHitInfo Info, std::string Tag) override;


	/// Getters

	// Returns this projectiles image.
	inline CSprite* GetImage() const { return Image; }
};