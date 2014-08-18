#include"qlydocgia.h"
Qly_docgia::Qly_docgia()
{
	this->sl=0;
	for(int i=0; i<sl; i++)
	{
		Qly[i]=NULL;
	}
}
Qly_docgia::~Qly_docgia()
{
	for(int i=0; i<sl; i++)
	{
		if(Qly[i]!=NULL)
		{		
			delete Qly[i];
			Qly[i]=NULL;
		}
	}
	delete[] Qly;
}
void Qly_docgia::them(docgia *d)
{
	if(sl<max) Qly[sl]= d;
	sl++;
}
void Qly_docgia::xuat()
{
	for(int i=0; i<sl; i++)
		Qly[i]->xuat();
}

