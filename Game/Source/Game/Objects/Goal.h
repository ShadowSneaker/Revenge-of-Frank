#pragma once
#include "../../Core/Objects/WorldObject.h"


class CGoal :public CWorldObject
{
private:
	/// Properties
	CSprite* Image;

	class CAABB* BoxCollider;

	bool Won;

public:
	/// Constructors
	CGoal(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);
	virtual ~CGoal() override;


	/// Functions

	virtual void OnOverlap(SHitInfo Info, std::string Tag) override;

	void TestFunction(SHitInfo Info) {}

	/// Setters



	/// Getters

};