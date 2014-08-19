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
void Quanly_sach::xuat()
{
	for(int i=0;i<so_luong;i++)
		_mang[i]->xuat();
}
void Quanly_sach::DanhSachSachCon()
{
	
	cout<<"Danh sach cac sach chua muon : "<<endl;
	for(int i=0; i<so_luong; ++i)
		if(_mang[i]->Tinh_trang()==false)
		{
			_mang[i]->xuat();
		}
}
void Quanly_sach::DanhSachSachDaMuon()
{
	cout<<"Danh sach cac sach da muon : "<<endl;
	for(int i=0;i<so_luong;i++)
		if(_mang[i]->Tinh_trang()==true)
		{
			_mang[i]->xuat();
		}
}
void Quanly_sach::TimSach(unsigned int maSach)
{
	int dem=0;
	cout<<"ket qua : "<<endl;
	for(int i=0;i<so_luong;i++)
	{
		if(maSach==_mang[i]->_ma)
		{
			dem++;
			_mang[i]->xuat();
		}
	}
	if(dem==0) cout<<"khong tim thay sach "<<endl;
}
Quanly_sach* Quanly_sach::qly_sach = new Quanly_sach();