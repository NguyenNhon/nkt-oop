#include"sachGt.h"

sachGT::sachGT()
{
		loai= eLoaiSach::eSachGiaiTri;
		tinhtrang = eTinhTrang::con;
}
sachGT::~sachGT(){}
void sachGT::nhap()
{
	cout<<"nhap gia tien: "<<endl;
	cin>>giatien;
	cout<<"nhap ten tac gia: "<<endl;
	fflush(stdin);
	getline(cin, tacgia);
	do
	{
		cout<<"nhap linh vuc: "<<endl;
		cin>>i;
	}while(i<1 && i>3);
	eLinhVuc(i);
	++Dem;
	_ma=Dem;
}
void sachGT::xuat()
{
	cout<<"loai sach: "<<loai<<" linh vuc: "<<i<<" ma sach: "<<_ma<<" gia tien: "<<giatien<<" tac gia: "<<tacgia<<endl;
}
