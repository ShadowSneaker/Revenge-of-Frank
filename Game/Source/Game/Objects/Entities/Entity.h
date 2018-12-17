#pragma once
#include "../../../Core/Objects/WorldObject.h"
#include "../../../Core/Systems/Input.h"
#include "../../../Core/Graphics/Images/Animation.h"
#include "../../../Core/Physics/Colliders/AABB.h"


class CEntity :public CWorldObject
{
private:
	/// Properties
	
	
	
	bool Dead;


	float ImmuneTimer;
	
	float MoveDir;

protected:
	float Health;
	float MaxHealth;

	float Damage;

	bool Immune;
	float MovementSpeed;
	float JumpStrength;

	CAnimation* Animation;

	CAABB* BoxCollider;

	float ImmunityFrames;




public:
	/// Contrustors

	CEntity(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);
	virtual ~CEntity() override;

	/// Functions

	virtual void Update() override;

	void MoveHorizontal(float Value);
	void Jump();

	virtual void ReadInput(CInput* Input) = 0;

	void Posess();


	virtual float ApplyDamage(const float Damage) override;

	/// Setters


	/// Getters

	inline CAnimation* GetAnimation() const { return Animation; }

	inline CAABB* GetBoxCollider() const { return BoxCollider; }
};