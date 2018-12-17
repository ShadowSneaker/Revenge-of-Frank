#include "UserInterface.h"


CUserInterface::CUserInterface(CRenderer* InRenderer)
	:Renderer{ InRenderer }
{
	// Add default UI components here.
}


CUserInterface::~CUserInterface()
{
	while (!Components.empty())
	{
		delete Components[Components.size() - 1];
		Components.pop_back();
	}
}


void CUserInterface::Draw()
{
	for (size_t i = 0; i < Components.size(); ++i)
	{
		Components[i]->Draw();
	}
}