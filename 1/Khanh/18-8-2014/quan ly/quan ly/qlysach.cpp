#include"qlysach.h"
Qly_sach::Qly_sach()
	{
		this->sl=0;
		for(int i=0;i<sl;i++)
		{
			qly[i]=NULL;
		}
	}
Qly_sach::~Qly_sach()
	{
		for(int i=0; i<sl; i++)
		{
			if(qly[i]!=NULL) 
			{
				delete qly[i];
				qly[i]=NULL;
			}
		}
		delete[] qly;
	}
void Qly_sach::them(sach *s)
	{
		if(sl<max) qly[sl]=s;
		sl++;
	}
void Qly_sach::xuat()
	{
		for(int i=0; i<sl; i++)
			qly[i]->xuat();
	}