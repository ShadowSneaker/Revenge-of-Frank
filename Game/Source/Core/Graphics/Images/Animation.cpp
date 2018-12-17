#include "Animation.h"


CAnimation::CAnimation(SDL_Renderer* Renderer)
	:CSprite::CSprite{ Renderer }, Playing{ false }, Loop{ true }
{
	Cell.x = 0;
	Cell.y = 0;
	TotalFrames = 0;
	FrameIndex = 0;
	SetCellCount(1, 1);
	Timer = 0.0f;
	Speed = 0.01f;
}


CAnimation::CAnimation(SDL_Renderer* Renderer, std::string FilePath)
	:CSprite::CSprite{ Renderer, FilePath }, Playing{ false }, Loop{ true }
{
	Cell.x = 0;
	Cell.y = 0;
	SetCellCount(1, 1);
	TotalFrames = 1;
	FrameIndex = 0;
	Timer = 0.0f;
	Speed = 0.01f;
}


CAnimation::~CAnimation()
{

}


void CAnimation::Update(float DeltaTime)
{
	if (Playing)
	{
		if (Timer < Speed)
		{
			Timer += DeltaTime;
		}
		else
		{
			Timer = 0.0f;
			
			if (Reversed)
			{
				--FrameIndex;

				if (FrameIndex < 0)
				{
					if (Loop)
					{
						FrameIndex = TotalFrames;
					}
					else
					{
						SetFrame(0);
						Stop();
					}

				}
			}
			else
			{
				++FrameIndex;

				if (FrameIndex > int(TotalFrames))
				{
					if (Loop)
					{
						FrameIndex = 0;
					}
					else
					{
						SetFrame(TotalFrames);
						Stop();
					}
				}
			}

			Draw();
		}
	}
}


void CAnimation::Draw()
{
	SDL_Point Center = GetCellCenter().ToPoint();

	SVector2i Point = RotateAroundParent(GetCellCenter());

	SDL_Rect Rect;
	Rect.x = Point[X] + Transform.GetWorldLocation()[X] + -Camera->GetWorldLocation()[X];
	Rect.y = Point[Y] + Transform.GetWorldLocation()[Y] + -Camera->GetWorldLocation()[Y];
	Rect.w = int(Cell.w * Transform.GetWorldScale()[X]);
	Rect.h = int(Cell.h * Transform.GetWorldScale()[Y]);

	Cell.x = (Cell.w * FrameIndex);
	// Do Y calculation here.

	SDL_RenderCopyEx(GetRenderer(), GetTexture(), &Cell, &Rect, Transform.GetWorldRotation(), &Center, GetFlip());
}


void CAnimation::Play()
{
	if (GetTexture() && TotalFrames > 0)
	{
		Reversed = false;
		Playing = true;
	}
}


void CAnimation::Stop()
{
	Playing = false;
}


void CAnimation::Reverse()
{
	if (GetTexture() && TotalFrames > 0)
	{
		Reversed = !Reversed;
		Playing = true;
	}
}


void CAnimation::PlayFromStart()
{
	if (GetTexture() && TotalFrames > 0)
	{
		FrameIndex = 0;
		Reversed = false;
		Playing = true;
	}
}


void CAnimation::ReverseFromEnd()
{
	if (GetTexture() && TotalFrames > 0)
	{
		FrameIndex = TotalFrames;
		Reversed = true;
		Playing = true;
	}
}


void CAnimation::SetFrame(size_t Frame, bool UpdateImage)
{
	FrameIndex = Frame;

	if (UpdateImage)
	{
		Draw();
	}
}


void CAnimation::SetCellCount(size_t Columns, size_t Rows)
{
	CellSize[X] = Columns;
	CellSize[Y] = Rows;

	//if (CellSize > 0)
	//{
		Cell.w = GetImageSize()[X] / CellSize[X];
		Cell.h = GetImageSize()[Y] / CellSize[Y];
	//}
	TotalFrames = Columns - 1;
}


void CAnimation::SetAnimation(std::string InFilePath, size_t Columns, size_t Rows, bool ChangeImageSize)
{
	ImageName = InFilePath;

	SetImage(InFilePath, ChangeImageSize);

	SetCellCount(Columns, Rows);
	TotalFrames = CellSize[X] - 1;
	// y count as well.
}


inline const SVector2i CAnimation::GetCellCenter()
{
	SVector2i Result;
	Result[X] = int(CellSize[X] * Transform.GetWorldScale()[X]) / 2;
	Result[Y] = int(CellSize[Y] * Transform.GetWorldScale()[Y]) / 2;
	return Result;
}