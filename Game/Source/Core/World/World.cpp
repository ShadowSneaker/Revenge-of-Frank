#include "World.h"
#include "../../Game/Objects/Entities/Player.h"
#include "../../Game/Objects/Entities/Enemies/Enemy.h"
#include "../../Game/Objects/Walls/Obstacle.h"
#include "../../Game/Objects/Goal.h"
#include "../../Game/Objects/Background.h"


CWorld::CWorld(CSDL_Setup* Setup)
	:SDL_Setup{ Setup }
{
	Quit = false;

	PossessedObject = nullptr;

	Input = new CInput();
	Physics = new CPhysics();

	Camera = new CCamera(SDL_Setup);
	Camera->SetDeltaTime(&DeltaTime);
	
	Renderer = new CRenderer(SDL_Setup, Camera);

	UI = new CUserInterface(Renderer);

	FileReader = new CFileReader();
	if (!LoadLevel("Level1.txt"))
	{
		Quit = true;
	}
}


CWorld::~CWorld()
{
	ClearLevel();
	
	//delete Physics;
	delete FileReader;
	delete Input;
	delete UI;
	delete Camera;
	delete Renderer;
}


void CWorld::GameLoop()
{
	CurrentFrameTime = SDL_GetPerformanceCounter();
	LastFrameTime = 0;
	DeltaTime = 0.0f;

	while (!Quit && Input->GetEvent()->type != SDL_QUIT)
	{
		GetDeltaTime();

		Input->Update();
		if (PossessedObject)
		{
			PossessedObject->ReadInput(Input);
		}

		Update();

		Graphics();
	}
}


void CWorld::Update()
{
	Camera->Update();

	for (size_t i = 0; i < Objects.size(); ++i)
	{
		if (Objects[i]->Active)
			Objects[i]->Update();
	}
}


void CWorld::Graphics()
{
	SDL_RenderClear(SDL_Setup->GetRenderer());

	Renderer->DrawImages();
	UI->Draw();

	SDL_RenderPresent(SDL_Setup->GetRenderer());
}


void CWorld::GetDeltaTime()
{
	LastFrameTime = CurrentFrameTime;
	CurrentFrameTime = SDL_GetPerformanceCounter();
	DeltaTime = float((CurrentFrameTime - LastFrameTime) / float(SDL_GetPerformanceFrequency()));
}


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
		//NewObject->SetWorld(this);
		NewObject->SetDeltaTime(&DeltaTime);

		Objects.push_back(NewObject);

		return NewObject;
	}

	delete NewObject;
	return nullptr;
}


void CWorld::DestroyObject(CWorldObject* Object)
{
	if (Object == PossessedObject)
	{
		PossessedObject = nullptr;
	}


	for (size_t i = 0; i < Objects.size(); ++i)
	{
		if (Objects[i] == Object)
		{
			delete Objects[i];
			Objects.erase(Objects.begin() + i);
		}
	}
}


bool CWorld::LoadLevel(std::string LevelName)
{
	if (OpenLevel != "")
	{
		ClearLevel();
		Camera->FollowObject = nullptr;
		Camera->SetOwnerOffset(0);
		Camera->Transform.Location = 0;

		Physics = new CPhysics();
	}

	OpenLevel = LevelName;

	CPlayer* Player;

	std::vector<std::string> FileContents = FileReader->ReadFileContents(LevelFileLocation + LevelName.c_str());
	if (FileContents.size() > 0)
	{
		for (size_t i = 0; i < FileContents.size(); ++i)
		{
			for (size_t j = 0; j < FileContents[i].size(); ++j)
			{
				SVector2i SpawnLocation{ int(j * GridSize), int(i * GridSize) };
				switch (FileContents[i][j])
				{
				case 'w':
					SpawnObject<CObstacle>(SpawnLocation);
					break;


				case 'p':
					Player = SpawnObject<CPlayer>(SpawnLocation);

					PossessedObject = Player;

					Camera->FollowObject = Player;
					Camera->SetOwnerOffset(Player->GetAnimation()->GetCellSize() * Player->Transform.Scale.ToInt() / 2);
					break;
				

				case 'g':
					SpawnObject<CGoal>(SpawnLocation);
					break;

				case 'b':
					SpawnObject<CBackground>(0);
					break;


				case 'e':
					CEnemy* Enemy = SpawnObject<CEnemy>(SpawnLocation);
					Enemy->SetPlayerRef(PossessedObject);
					break;
				}
			}
		}
		return true;
	}
	return false;
}


void CWorld::ClearLevel()
{
	PossessedObject = nullptr;
	while (!Objects.empty())
	{
		if (Objects[Objects.size() - 1])
		{
			delete Objects[Objects.size() - 1];
		}
		Objects.pop_back();
	}

	delete Physics;
}