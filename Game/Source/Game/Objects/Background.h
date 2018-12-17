#pragma once
#include "../../Core/Objects/WorldObject.h"


class CBackground :public CWorldObject
{
private:
	CSprite* Image;

public:
	CBackground(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform);
	virtual ~CBackground() override;

	inline CSprite* GetImage() const { return Image; }
};