#pragma once
#include "../../Core/Objects/WorldObject.h"


// Simply an image attached to a world object.
class CBackground :public CWorldObject
{
private:
	/// Properties

	// The image of the background.
	CSprite* Image;

public:
	/// Constructors

	// Constructor, Default
	CBackground(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);

	// Destructor
	virtual ~CBackground() override;


	/// Getters

	// Returns the image of the background.
	inline CSprite* GetImage() const { return Image; }
};