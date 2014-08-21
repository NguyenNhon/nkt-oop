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
		Node* p;
		while(_head != NULL)
		{
			p=_head;
			_head=_head->GetNext();
			p->SetNext(NULL);
			delete p;
		}
	}

	void InsertHead(Node *node)
	{
		node->SetNext(_head);
		_head=node;

	}
	void InsertBack(Node *node)
	{
		if(_head != NULL)
		{
			_tail->SetNext(node);
			_tail=node;
		}
		else 
			InsertHead(node);
	}
	void Print()
	{
		Node *p;
		p=_head;
		cout<<"danh sach lien ket don : "<<endl;
		while(p != NULL)
		{
			cout<<_head->Data()<<"\t";
			p=p->GetNext();
		}
	}

	void Sort()
	{
		Node *p,*k,*temp;
		temp=NULL;
		for(p=_head;p->GetNext()!= NULL;p=p->GetNext())
			for(k=p->GetNext();k != NULL; k=k->GetNext())
			{
				if(p->Data() > k->Data())
				{
					temp= p;
					p=k;
					k=temp;
				}
			}
	}

	void Find(int x)
	{
		Node *p;
		p=_head;
		int dem=0;
		while(p != NULL)
		{
			if(p->Data()==x)
				break;
			else
			{
				dem++;
				p=p->GetNext();
			}
		}
		if(p==NULL) 
		{
			cout<<"khong tim thay x"<<endl;
		}
		else 
		{
			cout<<"da tim thay tai vi tri : "<<dem<<endl;
			
		}
	
	}

	void DeleteAfterK(Node *k)
	{
		Node *p;
		if(k!= NULL)
		{
			p=k->GetNext();
			if(p!= NULL)
			{
				k->SetNext(p->GetNext());
				p->SetNext(NULL);
				if(p==_tail) _tail=k;
				delete p;
			}
		}
	}
	void DeleteHead()
	{
		Node *p;
		p=_head;
		if(_head != NULL)
		{
			_head=_head->GetNext();
			p->SetNext(NULL);
			delete p;
		}
	}
	void Delete(int x)
	{
		Node *p,*k;
		k=NULL;
		for(p=_head;p!= NULL;p=p->GetNext())
		{
			if(p->Data()!=x)
				k=p;
			else 
				break;
		}
		if(p==NULL) cout<<"khong tim thay de xoa"<<endl;
		else
		{
			if(k==NULL)
				DeleteHead();
			else 
				DeleteAfterK(k);
		}
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