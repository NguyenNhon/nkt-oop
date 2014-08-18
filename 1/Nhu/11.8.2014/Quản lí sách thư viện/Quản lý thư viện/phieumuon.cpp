#include"phieumuon.h"

Phieu_muon::Phieu_muon(){}

Phieu_muon::~Phieu_muon(){}

int Phieu_muon::_dem=0;

void Phieu_muon::nhap()
{
	_dem++;
	_ma=_dem;
	cout<<"nhap ngay muon sach : ";
	cin.ignore();
	getline(cin,ngay);
	cout<<"nhap ma doc gia : ";
	cin>>ma_docgia;
	cout<<"nhap ma sach : ";
	cin>>ma_sach;
	for(int i=0;i<MAX_BORROW_BOOK;i++)
		_mang[i]=ma_sach;
}

void Phieu_muon::xuat()
{
	cout<<"Ma phieu muon : "<<_ma<<"\tNgay muon : "<<ngay<<"\tMa doc gia : "<<ma_docgia;
	cout<<"Cac ma sach da muon : "<<endl;
	for(int i=0;i<MAX_BORROW_BOOK;i++)
		cout<<_mang[i]<<endl;
}