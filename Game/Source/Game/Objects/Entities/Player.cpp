#include "Player.h"
#include "../../../Core/Graphics/Interface/Components/ProgressBarComponent.h"
#include "../../../Core/World/World.h"


CPlayer::CPlayer(OBJECT_CONSTRUCTOR_BASE Base, STransform InTransform)
	:CEntity::CEntity{ Base, InTransform }
{
	JumpStrength = 22.0f;

	Animation->SetAnimation("crow-man.bmp", 13, 1);
	Animation->RemoveBackground();
	Animation->Speed = 0.01f;
	Animation->Play();

	BoxCollider->Extents = Animation->GetCellSize();

	Transform.Scale = 2.0f;



	HealthBar = GetWorld()->GetUI()->AddComponent<CProgressBarComponent>(10);
	HealthBar->Transform.Scale = SVector2(1.0f, 0.25f);
	HealthBar->Foreground->SetColour(SDL_Color{ 0, 100, 0 });
	HealthBar->Min = 0.0f;
	HealthBar->Max = MaxHealth;
	HealthBar->Value = Health;


	Tag = "Player";
	CanReverse = true;
}


CPlayer::~CPlayer()
{
	//delete HealthBar;
}



void CPlayer::Update()
{
	CEntity::Update();

}


void CPlayer::ReadInput(CInput* Key)
{
	if (Key->KeyIsPressed(KEY_SPACE))
	{
		Jump();
	}

	if (Key->KeyIsPressed(KEY_D))
	{
		MoveHorizontal(1.0f);
	}

	if (Key->KeyIsPressed(KEY_A))
	{
		MoveHorizontal(-1.0f);
	}

	if (!Key->KeyIsPressed(KEY_A) && !Key->KeyIsPressed(KEY_D))
	{
		if (Animation->Playing)
		{
			Animation->SetFrame(0);
			Animation->Stop();
		}
	}

	if (Key->KeyIsPressed(KEY_G))
	{
		if (CanReverse)
		{
			CanReverse = false;
			GetPhysics()->ReverseGravity();

			Animation->FlipY = !Animation->FlipY;
		}
	}
	else
	{
		CanReverse = true;
	}
}


float CPlayer::ApplyDamage(float Damage)
{
	CEntity::ApplyDamage(Damage);
	HealthBar->Value = Health;
	return Health;
}