#include"docgia.h"

unsigned int Doc_gia::_dem=0;

Doc_gia::Doc_gia(){}
Doc_gia::~Doc_gia(){}

void Doc_gia::nhap()
{
	cout<<"\tNhap ho va ten doc gia : ";
	getline(cin,ho_ten);
	cout<<"nhap tuoi :";
	cin>>tuoi;
	++_dem;
	_ma=_dem;
}
LoaiDocGia Doc_gia::Get_loai()
{
	if(6<=tuoi && tuoi<=18)
		return LoaiDocGia::ThieuNhi;
	else if(19<tuoi && tuoi<=35)
		return LoaiDocGia::ThieuNien;
	else if(36<tuoi && tuoi<=50)
		return LoaiDocGia::TrungNien;
}