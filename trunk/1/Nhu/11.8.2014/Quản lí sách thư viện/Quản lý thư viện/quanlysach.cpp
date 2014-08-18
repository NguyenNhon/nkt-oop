#include"quanlysach.h"

Quanly_sach::Quanly_sach()
{
	so_luong=0;
	for(int i=0;i<MAX_BOOK;i++)
		_mang[i]=NULL;
}
Quanly_sach::~Quanly_sach()
{
	for(int i=0;i<MAX_BOOK;i++)
		if(_mang[i] != NULL)
		{
			delete _mang[i];
			_mang[i]=NULL;
		}
	delete[] _mang;
}
void Quanly_sach::them(Sach *sach)
{
		if(so_luong<MAX_BOOK)
			_mang[so_luong]=sach;
		so_luong++;
}