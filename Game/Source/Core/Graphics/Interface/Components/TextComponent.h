#pragma once
#include "../InterfaceComponent.h"
#include "../../../../Containers/Font.h"

#include <SDL_ttf.h>


// Text that can be drawn on the Interface.
class CTextComponent :public CInterfaceComponent
{
private:
	///Properties

	// A reference to the drawn font on the screen.
	CFont* Font;


public:
	/// Constructors

	// Constructor Initiates the font to be drawn on the screen.
	CTextComponent(SDL_Renderer* InRenderer);

	// Default Destructor.
	~CTextComponent();


	/// Functions

	// Draws the font onto the screen.
	virtual void Draw() override;


	/// Setters

	// Sets the font type that will be drawn to the screen.
	inline void SetFont(const std::string InFont) { Font->SetFont(InFont); }

	// Sets the display text of this font.
	inline void SetText(const std::string NewText) { Font->SetText(NewText); }

	// Sets the colour of the text for this font.
	inline void SetColour(SDL_Color NewColour) { Font->SetColour(NewColour); }

	// Sets the size of the text for this font.
	inline void SetFontSize(size_t NewSize) { Font->SetFontSize(NewSize); }


	/// Getters

	// Returns a reference to the created font class.
	inline CFont* GetFont() const { return Font; }

	// Returns the drawn text of this font.
	inline std::string GetText() const { return Font->GetText(); }

	// Returns the drawn colour of this font.
	inline SDL_Color GetColour() const { return Font->GetColour(); }

	// Returns the drawn size of this font.
	inline size_t GetFontSize() const { return Font->GetFontSize(); }
};