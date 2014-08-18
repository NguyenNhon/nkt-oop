#include"sachGK.h"

Sach_Giaokhoa::Sach_Giaokhoa()
{
	_loai=LoaiSach::SachGiaoKhoa;
}
Sach_Giaokhoa::~Sach_Giaokhoa(){}

void Sach_Giaokhoa::nhap()
{
		
		cout<<"nhap gia tien : ";
		cin>>gia_tien;
		fflush(stdin);
		cout<<"nhap ten tac gia :";
		getline(cin,tac_gia);
		do
		{
			cout<<"nhap tu 0 den 12 tuong uong voi lop mau giao den lop 12"<<endl;
			cout<<"SGK thuoc lop : ";
			cin>>lop;
		}while(lop<0 && lop>12);
		(Lop)lop;
		_dem++;
		_ma=_dem;
}
void Sach_Giaokhoa::xuat()
{
		cout<<"\tMa Sach : "<<_ma<<"\tLoai : "<<_loai<<"\tgia tien : "<<gia_tien<<"\ttac gia : "<<tac_gia<<"\tlop : "<<lop<<endl;
}