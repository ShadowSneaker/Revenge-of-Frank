#pragma once
#include "../../Core/Objects/WorldObject.h"


// The object that completes the level.
class CGoal :public CWorldObject
{
private:
	/// Properties

	// The image representing the goal.
	CSprite* Image;

	// The collider the player must collide with in order to beat the level.
	class CAABB* BoxCollider;

	// Determines if the player has won.
	bool Won;

public:
	/// Constructors

	// Constructor, Default
	CGoal(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);

	// Destructor
	virtual ~CGoal() override;


	/// Functions

	// Triggers when a object overlaps this collider.
	virtual void OnOverlap(SHitInfo Info, std::string Tag) override;


	/// Setters



	/// Getters

};