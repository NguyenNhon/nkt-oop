#include"sachGk.h"

sachGK::sachGK()
{
	loai = eLoaiSach::eSachGiaoKhoa;
	tinhtrang = eTinhTrang::con;
}
void sachGK::nhap()
	{
		cout<<"nhap gia tien: "<<endl;
		cin>>giatien;
		cout<<"nhap ten tac gia: "<<endl;
		fflush(stdin);
		getline(cin, tacgia);
		do
		{
			cout<<" xep lop cho sach GK: "<<endl;
			cin>>i;
		}while(i<0 && i>12);
		eLop(i);
		++Dem;
		_ma=Dem;
	}
void sachGK::xuat()
	{
		cout<<"loai sach: "<<loai<<" lop: "<<i<<" ma sach: "<<_ma<<" gia tien: "<<giatien<<" tac gia: "<<tacgia<<endl;
	}