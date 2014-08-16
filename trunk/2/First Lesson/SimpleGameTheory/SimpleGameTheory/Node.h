#ifndef NODE_H
#define NODE_H

#include "Helper.h"
#include "Point2D.h"

class Node
{
protected:
	Point2D _position; // vi tri tren man hinh
	char _character; // Ki tu dung de the hien len man hinh
	GColors _color;
public:
	Node(Point2D pos, char character, GColors color = GColors::WHITE)
	{
		_position=pos;
		_character=character;
		_color=color;
	}

	void SetColor(GColors color)
	{
		_color=color;
	}

	virtual void Draw()
	{
		GPutCharToBuffer(_character, _position.X(), _position.Y(), _color);
	}

	virtual void Update()
	{
		
	}

	virtual void Move(GDirections direction)
	{
		_position.Move(direction, 1, 1);
	}
};
#endif