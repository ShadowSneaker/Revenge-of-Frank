#pragma once
#include "InterfaceComponent.h"
#include "../Renderer/Renderer.h"

#include <vector>


// Renders UI objects onto the screen.
class CUserInterface
{
private:
	/// Properties

	std::vector<CInterfaceComponent*> Components;

	CRenderer* Renderer;


public:
	/// Constructors

	// Default Constructor. Setups a UI overlay.
	CUserInterface(CRenderer* InRenderer);

	// Deconstructor.
	~CUserInterface();


	/// Functions

	void Draw();


	/*template <typename Type>
	Type* AddComponent();

	template <typename Type>
	Type* AddComponent(SVector2i Location);

	template <typename Type>
	Type* AddComponent(SVector2i Location, SVector2 Scale);

	template <typename Type>
	Type* AddComponent(SVector2i Location, float Rotation);

	template <typename Type>
	Type* AddComponent(STransform Transform);*/

	template <typename Type>
	Type* AddComponent()
	{
		return AddComponent<Type>(STransform(0, 0.0f, 1.0f));
	}


	template <typename Type>
	Type* AddComponent(SVector2i Location)
	{
		return AddComponent<Type>(STransform(Location, 0.0f, 1.0f));
	}


	template <typename Type>
	Type* AddComponent(SVector2i Location, SVector2 Scale)
	{
		return AddComponent<Type>(STransform(Location, 0.0f, Scale));
	}


	template <typename Type>
	Type* AddComponent(SVector2i Location, float Rotation)
	{
		return AddComponent<Type>(STransform(Location, Rotation, 1.0f));
	}


	template <typename Type>
	Type* AddComponent(STransform Transform)
	{
		Type* NewComponent = new Type(Renderer->GetRenderer());

		if (NewComponent)
		{
			//CInterfaceComponent* Comp = NewComponent;
			NewComponent->Transform = Transform;

			Components.push_back(NewComponent);
			return NewComponent;
		}

		delete NewComponent;
		return nullptr;
	}


	/// Setters


	/// Getters
};