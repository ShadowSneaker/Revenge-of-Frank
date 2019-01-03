#pragma once
#include "InterfaceComponent.h"
#include "../Renderer/Renderer.h"

#include <vector>


// Renders UI objects onto the screen.
class CUserInterface
{
private:
	/// Properties

	// A list of all components that needs to be drawn to the screen.
	std::vector<CInterfaceComponent*> Components;

	// A reference to the renderer.
	CRenderer* Renderer;


public:
	/// Constructors

	// Default Constructor. Setups a UI overlay.
	CUserInterface(CRenderer* InRenderer);

	// Deconstructor.
	~CUserInterface();


	/// Functions

	// Draws all the components onto the screen.
	void Draw();


	// Creates a component to be drawn on the screen.
	// @return - A reference of the created component.
	template <typename Type>
	Type* AddComponent()
	{
		return AddComponent<Type>(STransform(0, 0.0f, 1.0f));
	}


	// Creatse a component to be drawn on the screen.
	// @param Location - The position the component should be created at.
	// @return - A reference of the created component.
	template <typename Type>
	Type* AddComponent(SVector2i Location)
	{
		return AddComponent<Type>(STransform(Location, 0.0f, 1.0f));
	}


	// Creates a component to be drawn on the screen.
	// @param Location - The position the component should be created at.
	// @param Scale - The size the component should be crated with.
	// @return - A reference of the created component.
	template <typename Type>
	Type* AddComponent(SVector2i Location, SVector2 Scale)
	{
		return AddComponent<Type>(STransform(Location, 0.0f, Scale));
	}


	// Creates a component to be drawn on the screen.
	// @param Location - The position the component should be created at.
	// @param Rotation - The angle the component should be created with.
	// @return - A reference of the created component.
	template <typename Type>
	Type* AddComponent(SVector2i Location, float Rotation)
	{
		return AddComponent<Type>(STransform(Location, Rotation, 1.0f));
	}


	// Creates a component to be drawn on the screen.
	// @param Transform - The position, rotation and scale the component should be created with.
	// @return - A reference of the created component.
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