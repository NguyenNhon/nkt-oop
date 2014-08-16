#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Helper.h"
#include "Snake.h"

class GameManager
{		
	Snake *snake;		

	void Update()
	{		
		snake->Update();
	}

	void Draw()
	{
		GClearBuffer();			
		GPutCharToBuffer('@',5,5,RED);
		snake->Draw();
		GFlushBuffer(); // ve toan bo ki tu len man hinh
	}
public:
	GameManager()
	{
		snake=Snake::GetInstance();
	}

	~GameManager()
	{
		delete snake;
		snake=NULL;
	}

	void GameRun()
	{
		while (1)
		{
			if(GIsElapsed(1000 / 10)) // ve 10 hinh tren giay
			{			
				if(GIsKeyDown(KEY_UP))
				{
					snake->SetDirection(GDirections::UP);
				}
				if(GIsKeyDown(KEY_DOWN))
				{
					snake->SetDirection(GDirections::DOWN);
				}
				if(GIsKeyDown(KEY_RIGHT))
				{
					snake->SetDirection(GDirections::RIGHT);
				}
				if(GIsKeyDown(KEY_LEFT))
				{
					snake->SetDirection(GDirections::LEFT);
				}

				Update();
				Draw();
			}	
		}
	}
};
#endif