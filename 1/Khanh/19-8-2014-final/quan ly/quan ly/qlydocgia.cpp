#include"qlydocgia.h"
Qly_docgia *Qly_docgia::qlydocgia=new Qly_docgia();
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
void Qly_docgia::tinhtrangdocgia()
{
	for(int i=0; i<sl; i++)
		for(int j=0; j< Qly_phieumuon::qlyphieumuon->sl;j++)
			if(Qly[i]->_ma==Qly_phieumuon::qlyphieumuon->phieu[j]->ma_dg) Qly_docgia::Qly[i]->tinhtrang= etinhtrang::damuon;
}
