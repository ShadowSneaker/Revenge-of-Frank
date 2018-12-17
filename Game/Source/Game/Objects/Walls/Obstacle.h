#pragma once
#include "../../../Core/Objects/WorldObject.h"
#include "../../../Core/Graphics/Images/Sprite.h"
#include "../../../Core/Physics/Colliders/AABB.h"


class CObstacle :public CWorldObject
{
private:
	/// Properties

	CSprite* Image;

	CAABB* BoxCollider;


public:
	/// Constructors

	CObstacle(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);
	virtual ~CObstacle() override;

	/// Functions



	/// Setters


	/// Getters

	inline CImage* GetImage() const { return Image; }


	inline CAABB* GetCollider() const { return BoxCollider; }
};