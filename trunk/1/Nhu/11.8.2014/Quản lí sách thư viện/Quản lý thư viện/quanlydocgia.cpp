#include"quanlydocgia.h"

Qly_docgia::Qly_docgia()
{
	so_luong=0;
	for(int i=0;i<MAX_READER;i++)
		_mang[i]=NULL;
}
Qly_docgia::~Qly_docgia()
{
	for(int i=0;i<MAX_READER;i++)
		if(_mang[i] != NULL)
		{
			delete _mang[i];
			_mang[i]= NULL;
		}
	delete[] _mang;
}

void Qly_docgia::them(Doc_gia* docgia)
{
	if(so_luong < MAX_READER)
		_mang[so_luong] = docgia;
	so_luong++;
}