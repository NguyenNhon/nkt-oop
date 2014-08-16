#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Helper.h"

class GameManager
{
	GPoint2D matran[4];
	int _vX;
	int _vY;

	static GameManager* instance;

	GameManager()
	{
		matran[0].x=1;
		matran[0].y=1;
		matran[1].x=2;
		matran[1].y=1;
		matran[2].x=1;
		matran[2].y=2;
		matran[3].x=2;
		matran[3].y=2;

		_vX=1;
		_vY=1;
	}

	void Update()
	{
		// Thay doi vi tri 
		for (int i = 0; i < 4; i++)
		{			
			matran[i].x+=_vX;
			matran[i].y+=_vY;
		}
		if(matran[0].x<0 || matran[3].x>250)
			_vX=-_vX;
		if(matran[0].y<0 || matran[3].y>100)
			_vY=-_vY;
	}

	void Draw()
	{
		GClearBuffer();		

		// ve cac diem len man hinh
		for (int i = 0; i < 4; i++)
		{
			// Ve ki tu gi, o vi tri nao, mau sau la gi
			GPutCharToBuffer('*', matran[i].x, matran[i].y, GColors::GREEN); 
		}

		GFlushBuffer(); // ve toan bo ki tu len man hinh
	}
public:

	static GameManager* GetInstance(){return instance;}	

	void GameRun()
	{
		while (1)
		{
			if(GIsElapsed(1000 / 60)) // ve 60 hinh tren giay
			{			
				Update();
				Draw();
			}	
		}
	}
};

GameManager* GameManager::instance=new GameManager();
#endif