#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Node.h"

using namespace std;

class Snake
{
private:
	unsigned int _score;
	vector<Node*> _body;	
	GDirections _direction;

	static Snake* _instance;
public:
	static Snake* GetInstance(){return +_instance;}

	Snake()
	{
		_direction=GDirections::RIGHT;
		_score=0;
		Node *node = new Node(Point2D(10, 10),'A', WHITE); // Head of snake
		_body.push_back(node);
	}
		
	void Update()
	{
		vector<Node*>::iterator it=_body.begin();
		while (it!=_body.end())
		{

			(*it)->Move(_direction);
			++it;
		}
	}

	void Draw()
	{
		vector<Node*>::iterator it=_body.begin();
		while (it!=_body.end())
		{
			
			(*it)->Draw();
			++it;
		}
	}

	void SetDirection(GDirections direction)
	{
		_direction=direction;
	}
};
Snake* Snake::_instance = new Snake();
#endif