#pragma once
#include "../Graphics/SDL/SDL_Setup.h"
#include "../Graphics/Interface/UserInterface.h"
#include "../Graphics/Camera.h"
#include "../Systems/FileReader.h"
#include "../Systems/Input.h"
#include "../Physics/Physics.h"

#include "../../Game/Objects/Walls/Obstacle.h"

#include <vector>


// The primary class to hold all information for the currently loaded world.
// This class reads a file and based off the contents of that file it loads in a world
// and handles the all world events.
// Stores all the objects that are loaded in the world.
class CWorld
{
private:
	/// Properties

	// A reference to the created File reader.
	CFileReader* FileReader;

	// A reference to the created input handler.
	CInput* Input;

	// A reference to the created setup for SDL.
	CSDL_Setup* SDL_Setup;

	// A reference to the created renderer.
	CRenderer* Renderer;

	// A reference to the created User Interface.
	CUserInterface* UI;

	// A reference to the main camera in the level.
	CCamera* Camera;

	// A reference to the Physics Engine.
	CPhysics* Physics;

	// A list of all objects spawned in the world.
	std::vector<class CWorldObject*> Objects;

	// A value determining if the user is attempting to quit.
	bool Quit;

	// The time recived for the last frame.
	Uint64 LastFrameTime;

	// The time recieved for the current frame.
	Uint64 CurrentFrameTime;

	// How long it took to run the frame.
	float DeltaTime;

	// How large the standard grid size is for placing level objects.
	const size_t GridSize = 64;

	// The default file location for loading levels.
	const std::string LevelFileLocation = "Content/Levels/";

	// The currently running level name.
	std::string OpenLevel;


public:
	// The object that the user currently controls.
	class CEntity* PossessedObject;


public:
	/// Constructors

	// Constructor, Default
	CWorld(CSDL_Setup* Setup);

	// Destructor
	~CWorld();


	/// Functions

	// The main game loop.
	void GameLoop();

	// Called every frame, used to update all objects in the level.
	void Update();

	// Called every frame, used to draw all images in the level.
	void Graphics();

	// Spawns an object in the world.
	// @return - Returns a reference of the spawned object.
	template <typename Type>
	Type* SpawnObject();

	// Spawns an object in the world.
	// @param Location - The location this object should be spawned.
	// @return - Returns a reference of the spawned object.
	template <typename Type>
	Type* SpawnObject(SVector2i Location);

	// Spawns an object in the world.
	// @param Location - The location this object should be spawned.
	// @param Rotation - The rotation this object should be spawned with.
	// @return - Returns a reference of the spawned object.
	template <typename Type>
	Type* SpawnObject(SVector2i Location, float Rotation);

	// Spawns an object in the world.
	// @param Location - The location this object should be spawned.
	// @param Scale - The size this object should be spawned with.
	// @return - Returns a reference of the spawned object.
	template <typename Type>
	Type* SpawnObject(SVector2i Location, SVector2 Scale);

	// Spawns an object in the world.
	// @param Transform - The location, rotation and scale this object should be spawned with.
	// @return - Returns a reference of the spawned object.
	template <typename Type>
	Type* SpawnObject(STransform Transform);

	// Removes an object from the world.
	// @param Object - A reference of the object to be destroyed.
	void DestroyObject(class CWorldObject* Object);

	// Reads a file to load in the contents into the game.
	// @param LevelName - The name of the file to be loaded (Should end in .txt).
	// @return - Returns if this level was successfully loaded.
	bool LoadLevel(std::string LevelName);

private:
	// Removes all objects from the level, Used for cleanup and level transitioning.
	void ClearLevel();
public:

	// Closes the game.
	inline void QuitGame() { Quit = true; }


	/// Getters

	// Returns a list of all objects that are currently in the world.
	inline std::vector<CWorldObject*> GetObjects() const { return Objects; }

	// Returns the reference of the main camera.
	inline CCamera* GetCamera() const { return Camera; }

	// Returns the name of the currently loaded level.
	inline std::string LoadedLevel() const { return OpenLevel; }
	
	// Returns a reference of the UserInterface.
	CUserInterface* GetUI() const { return UI; }

private:
	// Sets the new value of DeltaTime.
	void GetDeltaTime();

public:
};



template <typename Type>
Type* CWorld::SpawnObject()
{
	return SpawnObject<Type>(STransform());
}


template <typename Type>
Type* CWorld::SpawnObject(SVector2i Location)
{
	return SpawnObject<Type>(STransform(Location, 0.0f, 1.0f));
}


template <typename Type>
Type* CWorld::SpawnObject(SVector2i Location, float Rotation)
{
	return SpawnObject<Type>(STransform(Location, Rotation, 1.0f));
}


template <typename Type>
Type* CWorld::SpawnObject(SVector2i Location, SVector2 Scale)
{
	return SpawnObject<Type>(STransform(Location, 0.0f, Scale));
}


template <typename Type>
Type* CWorld::SpawnObject(STransform Transform)
{
	Type* NewObject = new Type(OBJECT_CONSTRUCTOR_BASE{ Renderer, Physics, this }, Transform);
	if (NewObject)
	{
		NewObject->SetDeltaTime(&DeltaTime);

		Objects.push_back(NewObject);

		return NewObject;
	}

	delete NewObject;
	return nullptr;
}