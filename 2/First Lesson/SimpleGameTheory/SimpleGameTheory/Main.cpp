#include <iostream>

#include "GameManager.h"

using namespace std;

void Init()
{	
	//GSetFont(8, 8, 500, GFontFamilys::MODERN);
	//GSetNoScroolBar();
	srand(time(0));
}

void main()
{		
	Init();
	GameManager game;
	while (1)
	{			
		game.GameRun();
	}
}