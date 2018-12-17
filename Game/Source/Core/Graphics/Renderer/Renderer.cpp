#include "Renderer.h"

#include <algorithm>



CRenderer::CRenderer(CSDL_Setup* SDL_Setup, CCamera* InCamera)
	:Setup{ SDL_Setup }, Camera{ InCamera }
{}


CRenderer::~CRenderer()
{
	while (!Images.empty())
	{
		if (Images[Images.size() - 1])
		{
			delete Images[Images.size() - 1];
		}
		Images.pop_back();
	}
}


void CRenderer::DrawImages()
{
	std::sort(Images.begin(), Images.end(), IMAGE_ZORDER());

	for (size_t i = 0; i < Images.size(); ++i)
	{
		if (Images[i])
		{
			if (Images[i]->Enable)
			{
				Images[i]->Draw();
			}
		}
		else
		{
			Images.erase(Images.begin() + i);
		}
	}
}


void CRenderer::AddImage(CImage* Image)
{
	Images.push_back(Image);
}


void CRenderer::DestroyImage(CImage* Image)
{
	for (size_t i = 0; i < Images.size(); ++i)
	{
		if (Images[i] == Image)
		{
			delete Images[i];
			Images.erase(Images.begin() + i);
			return;
		}
	}

	delete Image;
}