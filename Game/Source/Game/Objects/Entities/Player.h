#pragma once
#include "Entity.h"


// The default character the user controlls.
class CPlayer :public CEntity
{
private:
	/// Properties

	// A buffer so when the user presses the reverse gravity key it doesn't run every frame.
	bool CanReverse;

	// A reference to a progress bar on the UI representing as the player's healthbar.
	class CProgressBarComponent* HealthBar;

	// The current cooldown on the user's fire ability.
	float FireCD;

	// The cooldown on the user's fire ability.
	float MaxFireCD;




public:
	/// Constructors

	// Constructor, Default.
	CPlayer(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);

	// Destructor
	virtual ~CPlayer() override;

	/// Functions

	// Reads the users inputs to control the entity.
	virtual void ReadInput(CInput* Input) override;

	// Runs every frame.
	virtual void Update() override;

	// Applies damage to this entity based off the inputted damge.
	// @return - returns how much HP the entity has left after the damage.
	virtual float ApplyDamage(float Damage) override;

	// Fires a projectile in the direction the player is facing.
	void Fire();

	/// Setters


	/// Getters
};