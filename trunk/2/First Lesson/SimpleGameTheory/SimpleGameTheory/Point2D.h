#ifndef POINT_2D_H
#define POINT_2D_H

#include "Helper.h"

class Point2D
{
protected:
	int _x;
	int _y;

public:
	Point2D(int x=0, int y=0)
	{
		_x=x;
		_y=y;
	}

	void Set(int x, int y)
	{
		_x=x;
		_y=y;
	}

	void SetX(int val)
	{
		_x=val;
	}

	void SetY(int val)
	{
		_y=val;
	}

	int X(){return _x;}

	int Y(){return _y;}

	void Move(GDirections direction, int dX, int dY)
	{
		switch (direction)
		{
		case GDirections::DOWN:
			_y+=dY;
			break;
		case GDirections::UP:
			_y-=dY;
			break;
		case GDirections::RIGHT:
			_x+=dX;
			break;;
		case  GDirections::LEFT:
			_x-=dX;
			break;
		}
	}
};
#endif 