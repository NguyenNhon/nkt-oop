#include"docgia.h"
unsigned int docgia::Dem=0;
docgia::docgia()
{
	tinhtrang= etinhtrang::chuamuon;
}
docgia::~docgia(){}
void docgia::nhap()
	{
		cout<<"nhap ten doc gia: "<<endl;
		fflush(stdin);
		getline(cin,ten);
		cout<<"nhap tuoi cho doc gia: "<<endl;
		cin>>tuoi;
		if(tuoi >=6 && tuoi<=18) loai= eLoaiDocGia::eThieuNhi;
		else if(tuoi>=19 && tuoi<=35) loai= eLoaiDocGia::eThieuNien;
		else loai= eLoaiDocGia::eTrungNien;
		++Dem;
		_ma=Dem;
	}
void docgia::xuat()
	{
		cout<<"ten doc gia: "<<ten<<" tuoi: "<<tuoi<<" loai doc gia: "<<loai<<" ma doc gia: "<<_ma<<endl;
	}
	