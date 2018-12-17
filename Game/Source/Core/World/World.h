#pragma once
#include "../Graphics/SDL/SDL_Setup.h"
//#include "../../Game/Objects/Walls/Obstacle.h"
//#include "../../Game/Objects/Entities/Enemies/Enemy.h"
#include "../Graphics/Interface/UserInterface.h"
#include "../Graphics/Camera.h"
#include "../Systems/FileReader.h"
#include "../Systems/Input.h"
#include "../Physics/Physics.h"

#include <vector>


class CWorld
{
private:
	/// Properties

	CFileReader* FileReader;

	CInput* Input;

	CSDL_Setup* SDL_Setup;

	CRenderer* Renderer;

	CUserInterface* UI;

	CCamera* Camera;

	CPhysics* Physics;
	
	//size_t ActiveCount;

	// A list of all objects spawned in the world.
	std::vector<class CWorldObject*> Objects;

	//CObjectList List;
	class CEntity* OBJ;


	bool Quit;



	// The time recived for the last frame.
	Uint64 LastFrameTime;

	// The time recieved for the current frame.
	Uint64 CurrentFrameTime;

	// How long it took to run the frame.
	float DeltaTime;

	const size_t GridSize = 64;

	const std::string LevelFileLocation = "Content/Levels/";

	std::string OpenLevel;


public:
	class CEntity* PossessedObject;


public:
	/// Constructors

	CWorld(CSDL_Setup* Setup);
	~CWorld();


	/// Functions

	void GameLoop();

	void Update();

	void Graphics();

	template <typename Type>
	Type* SpawnObject();

	template <typename Type>
	Type* SpawnObject(SVector2i Location);

	template <typename Type>
	Type* SpawnObject(SVector2i Location, float Rotation);

	template <typename Type>
	Type* SpawnObject(SVector2i Location, SVector2 Scale);

	template <typename Type>
	Type* SpawnObject(STransform Transform);

	void DestroyObject(class CWorldObject* Object);

	bool LoadLevel(std::string LevelName);

private:
	void ClearLevel();
public:

	inline void QuitGame() { Quit = true; }


	/// Getters

	inline std::vector<CWorldObject*> GetObjects() const { return Objects; }

	inline CCamera* GetCamera() const { return Camera; }

	 CUserInterface* GetUI() const { return UI; }

private:
	// Sets the new value of DeltaTime.
	void GetDeltaTime();

public:
};