#include <iostream>

#include "GameManager.h"

using namespace std;

void Init()
{	
	GSetFont(4, 4, 100, GFontFamilys::MODERN);
	GSetNoScroolBar();
	srand(time(0));
}

void main()
{		
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	Init();

	while (1)
	{			
		GameManager::GetInstance()->GameRun();
	}
}