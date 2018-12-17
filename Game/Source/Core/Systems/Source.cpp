#include "Setup.h"


int main(int argc, char **argv)
{
	CSetup* Setup;
	Setup = new CSetup();
	Setup->Init();
	delete Setup;
	return 1;
}