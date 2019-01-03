#pragma once
#include "../Entity.h"


// The base Entity that is controlled by AI.
class CEnemy :public CEntity
{
private:
	/// Properties

	// A reference to the player.
	CEntity* PlayerRef;

	// The agro range of this enemy.
	class CCircle* CircleCollider;

	// The attack range of this enemey.
	class CCircle* AttackRange;

	// Represents if the enemy is attempting to attack the player.
	bool IsAgro = false;


public:
	/// Constructors

	// Constructor, Default
	CEnemy(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);

	// Destructor.
	virtual ~CEnemy() override;


	/// Functions

	// Runs every frame.
	virtual void Update() override;

	// A required empty function incase the object is possessed (should probably change it to a default function instead of null function.
	virtual void ReadInput(CInput* Input) override {};

	// Runs when a object overlaps this object's collider.
	virtual void OnOverlap(SHitInfo Info, std::string Tag) override;
 
	/// Setters

	// Sets the reference for the player.
	inline void SetPlayerRef(CEntity* Player) { PlayerRef = Player; }

	/// Getters
};