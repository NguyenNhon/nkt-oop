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
		while(_head != NULL)
		{
			delete _head;
			_head=NULL;
			_head->GetNext();
			_head->SetNext(_head);
		}
	}
	void InsertHead(Node *node)
	{
		Node *p=_head;
		if(_head==_tail==NULL)
		{
			_head=_tail=node;
		}
		else
		{
			node->SetNext(_head);
			_head=node;
		}
	}
	void InsertBack(Node *node)
	{
		if(_head==_tail==NULL)
		{
			_head=_tail=node;
		}
		else
		{
			_tail->SetNext(node);
			_tail=node;
		}
	}
	void Print()
	{
		Node *p;
		p=_head;
		while(p!=NULL)
		{
			cout<<p->Data()<<"\t";
			p->SetNext(p);
		}
		delete p;
		p=NULL;
	}
	void Sort()
	{
		Node *p,*q;
		p=_head;
		while(p->GetNext()!=NULL);
		{
			q=p->GetNext();
			if(p->Data()<q->Data())
			{
				Node *t;
				t=p;
				p=q;
				q=t;
			}
		}
	}
	void Find(int x)
	{
		int dem;
		Node *p=_head;
		while(p->GetNext()!=NULL)
		{
			if( p->Data()!=x)
			{
				dem++;
				p->SetNext(p);
			}
			else break;
		}
		if(dem==0) cout<<"khong tim thay"<<endl;
		else cout<<"tim thay node o vi tri: "<<dem<<endl;
	}
	void Delete(int x)
	{
		Node *q=NULL;
		Node *p=_head;
		while(p->GetNext()!=NULL)
		{
			if(p->Data()!=x)
			{
				q=p;
				p->SetNext(p);
			}
		}
		if(p!=NULL)
		{
			if(q!=NULL)
			{
				Xoasauq(q);
			}
			else Xoadau();
		}
	}
	void Xoasauq(Node *q)
	{
		Node *p;
		p=q->GetNext();
		q->SetNext(p->GetNext());
		delete p;
		p=NULL;
	}
	void Xoadau()
	{
		Node *p=_head;
		if(p!=NULL)
		{
			_head->SetNext(p->GetNext());
		}
		delete p;
		p=NULL;
	}
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