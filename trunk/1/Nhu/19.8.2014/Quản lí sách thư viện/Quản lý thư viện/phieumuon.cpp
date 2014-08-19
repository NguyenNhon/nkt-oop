#include"phieumuon.h"

Phieu_muon::Phieu_muon()
{
	so_luong=0;
	for(int i=0;i<MAX_BORROW_BOOK;i++)
		_mang[i]=NULL;
}

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
	cout<<"nhap so sach muon : ";
	cin>>so_luong;
	for(int i=0;i<so_luong;i++)
	{
		cout<<"nhap ma sach : ";
		cin>>ma_sach;
		_mang[i]=ma_sach;
	}
}

void Phieu_muon::xuat()
{
	cout<<"Ma phieu muon : "<<_ma<<"\tNgay muon : "<<ngay<<"\tMa doc gia : "<<ma_docgia;
	cout<<"Cac ma sach da muon : "<<endl;
	for(int i=0;i<so_luong;i++)
		cout<<_mang[i]<<endl;
}

void Phieu_muon::Sach_da_muon()
{
	for(int i=0; i<so_luong; ++i)
		for(int j=0;j<Quanly_sach::qly_sach->so_luong;j++)
			if(_mang[i]==Quanly_sach::qly_sach->_mang[j]->_ma)
				Quanly_sach::qly_sach->_mang[j]->ChoMuon();		
}
