#pragma once
#include "../InterfaceComponent.h"
#include "../../Images/Image.h"


class CImageComponent :public CInterfaceComponent
{
private:
	/// Properties
	CImage* Image;

public:
	/// Constructors
	CImageComponent(SDL_Renderer* InRenderer);


	/// Functions

	virtual void Draw() override;

	/// Setters
	inline void SetImage(const std::string FilePath, bool ChangeImageSize = true) { Image->SetImage(FilePath, ChangeImageSize); }

	/// Getters

	inline CImage* GetImage() const { return Image; }
};