#include "Transform.h"


STransform::STransform()
	:Parent{ nullptr }, Location{ 0 }, Rotation{ 0.0f }, Scale{ 1.0f }
{}


STransform::STransform(SVector2i InLocation, float InRotation, SVector2 InScale)
	: Parent{ nullptr }, Location{ InLocation }, Rotation{ InRotation }, Scale{ InScale }
{}


STransform::~STransform()
{
	Parent = nullptr;
	Child = nullptr;
}


STransform STransform::Merge(const STransform& Other) const
{
	return STransform
	{
		Location + Other.Location,
		Rotation + Other.Rotation,
		Scale * Other.Scale
	};
}