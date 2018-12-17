#pragma once
#include "../InterfaceComponent.h"
#include "../../../../Containers/Font.h"

#include <SDL_ttf.h>



class CTextComponent :public CInterfaceComponent
{
private:
	///Properties

	CFont* Font;


public:
	/// Constructors

	CTextComponent(SDL_Renderer* InRenderer);
	~CTextComponent();


	/// Functions

	virtual void Draw() override;


	/// Setters


	inline void SetFont(const std::string InFont) { Font->SetFont(InFont); }


	inline void SetText(const std::string NewText) { Font->SetText(NewText); }


	inline void SetColour(SDL_Color NewColour) { Font->SetColour(NewColour); }


	inline void SetFontSize(size_t NewSize) { Font->SetFontSize(NewSize); }


	/// Getters

	inline CFont* GetFont() const { return Font; }

	inline std::string GetText() const { return Font->GetText(); }


	inline SDL_Color GetColour() const { return Font->GetColour(); }


	inline size_t GetFontSize() const { return Font->GetFontSize(); }
};