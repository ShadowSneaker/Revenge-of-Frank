#pragma once
#include "../../../Core/Objects/WorldObject.h"
#include "../../../Core/Graphics/Images/Sprite.h"
#include "../../../Core/Physics/Colliders/AABB.h"


// A standard wall class with a collider.
class CObstacle :public CWorldObject
{
private:
	/// Properties

	// the Image of the obstacle.
	CSprite* Image;

	// The box collider for the obstacle.
	CAABB* BoxCollider;


public:
	/// Constructors

	// Constructor, Default
	CObstacle(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);

	// Destructor
	virtual ~CObstacle() override;

	/// Functions



	/// Setters


	/// Getters

	// Returns the image of this obstacle.
	inline CImage* GetImage() const { return Image; }

	// Returns the box collider on this obstacle.
	inline CAABB* GetCollider() const { return BoxCollider; }
};