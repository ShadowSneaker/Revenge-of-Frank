#pragma once
#include "../../../Core/Objects/WorldObject.h"
#include "../../../Core/Systems/Input.h"
#include "../../../Core/Graphics/Images/Animation.h"
#include "../../../Core/Physics/Colliders/AABB.h"


// The base entity type, This is an object that can move around on it's own.
class CEntity :public CWorldObject
{
private:
	/// Properties
	
	// Represents if the entity is dead.
	bool Dead;

	// The amount of time the Entity is invinsible after being attacked.
	float ImmuneTimer;
	
	// The direction this entity is currently moving in.
	float MoveDir;

protected:
	// The current amount of health of this entity.
	float Health;

	// The total amount of health this entity can have.
	float MaxHealth;

	// The amount of damage this entity does.
	float Damage;

	// Determines if this entity is currently immune.
	bool Immune;

	// The speed this entity moves.
	float MovementSpeed;

	// How high this entity can jump.
	float JumpStrength;

	// The Image, animation that this entity uses.
	CAnimation* Animation;

	// The collider of the image.
	CAABB* BoxCollider;

	// The amount of time this entity is immune.
	float ImmunityFrames;


public:
	/// Contrustors

	// Constructor, Default
	CEntity(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);

	// Destructor
	virtual ~CEntity() override;


	/// Functions

	// Runs every frame.
	virtual void Update() override;

	// Moves the entity left or right.
	void MoveHorizontal(float Value);

	// Makes the object jump.
	void Jump();

	// Reads the input of the user.
	virtual void ReadInput(CInput* Input) = 0;

	// Possesses this entity.
	void Posess();

	// Damages the entity based on an inputted damage amount.
	virtual float ApplyDamage(const float Damage) override;

	/// Setters


	/// Getters

	// Gets a reference of this entity's animation.
	inline CAnimation* GetAnimation() const { return Animation; }

	// Gets a reference to this entity's collision box.
	inline CAABB* GetBoxCollider() const { return BoxCollider; }
};