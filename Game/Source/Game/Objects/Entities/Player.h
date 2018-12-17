#pragma once
#include "Entity.h"


class CPlayer :public CEntity
{
private:
	/// Properties

	bool CanReverse;

	class CProgressBarComponent* HealthBar;

public:
	/// Constructors

	CPlayer(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);
	virtual ~CPlayer() override;

	/// Functions

	virtual void ReadInput(CInput* Input) override;

	virtual void Update() override;

	virtual float ApplyDamage(float Damage) override;

	/// Setters


	/// Getters
};