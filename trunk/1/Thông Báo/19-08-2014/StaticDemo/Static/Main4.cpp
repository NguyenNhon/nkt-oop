#include<iostream>
#include<conio.h>

using namespace std;

class Node
{
private:
	Node* _next;
	int _data;
public:
	Node(int data)
	{
		_next=NULL;
		_data=data;
	}

	~Node()
	{
		if(_next!=NULL)
		{
			delete _next;
			_next=NULL;
		}
	}

	void SetNext(Node *node)
	{
		_next=node;
	}
	Node* GetNext(){return _next;}
	int Data(){return _data;}
};

class LinkedList
{
private:
	Node* _head;
	Node* _tail;
public:
	LinkedList()
	{
		_head=NULL;
		_tail=NULL;
	}

	~LinkedList()
	{
		// Bat buoc phai viet ham nay
	}

	void InsertBack(Node *node){}
	void Print(){}

	void Sort(){}
	void Find(int x){};
	void Delete(int x){};
	void InsertHead(Node *node){};
};

int main()
{
	LinkedList list;

	list.InsertBack(new Node(5));
	list.InsertBack(new Node(1));	
	list.InsertBack(new Node(3));
	list.InsertBack(new Node(7));
	list.InsertHead(new Node(4));
	
	list.Sort();
	list.Print();
	
	list.Find(5);
	list.Delete(4);
	list.Print();

	_getch();
	return 0;
}