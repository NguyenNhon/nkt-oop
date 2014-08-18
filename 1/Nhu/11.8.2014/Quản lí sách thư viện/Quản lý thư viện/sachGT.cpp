#include"sachGT.h"

Sach_Giaitri::Sach_Giaitri()
{
	_loai=LoaiSach::SachGiaiTri;
}
Sach_Giaitri::~Sach_Giaitri()
{}
void Sach_Giaitri::nhap()
{
		cout<<"nhap gia tien : ";
		cin>>gia_tien;
		fflush(stdin);
		cout<<"nhap ten tac gia :";
		getline(cin,tac_gia);
		do
		{
			cout<<"Nhap linh vuc cua sach"<<endl;
			cout<<"1.My thuat\n2.Am nhac\n3.Truyen"<<endl;
			cin>>lv;
		}while(lv<1 && lv>3);
		(LinhVuc)lv;
		_dem++;
		_ma=_dem;
}
void Sach_Giaitri::xuat()
{
		cout<<"\tMa sach : "<<_ma<<"\tLoai : "<<_loai<<"\tgia tien : "<<gia_tien<<"\ttac gia : "<<tac_gia<<"\tlinh vuc : "<<lv<<endl;
}