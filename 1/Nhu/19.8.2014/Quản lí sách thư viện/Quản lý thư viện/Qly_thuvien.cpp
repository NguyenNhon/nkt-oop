#include"Qly_thuvien.h"

Qly_ThuVien::Qly_ThuVien(){};
Qly_ThuVien::~Qly_ThuVien(){};
void Qly_ThuVien::themSach()
{
	int n,tuychon;
	do
	{
		cout<<"nhap so luong sach muon them : ";
		cin>>n;
	}while(n<0 && n>100);
	for(int i=0;i<n;i++)
	{
		do
		{
			cout<<"chon 1 de nhap sach giao khoa "<<endl;
			cout<<"chon 2 de nhap sach giai tri "<<endl;
			cin>>tuychon;
		}while(tuychon != 1 && tuychon != 2);
		Sach* s;
		if(tuychon == 1)
			s=new Sach_Giaokhoa();
		else 
			s=new Sach_Giaitri();
		s->nhap();
		Quanly_sach::qly_sach->them(s);
	}
}
void Qly_ThuVien::themDocGia()
{
	int n;
	do
	{
		cout<<"nhap so luong doc gia muon them : ";
		cin>>n;
	}while(n<0 && n>100);
	for(int i=0;i<n;i++)
	{
		Doc_gia *dg=new Doc_gia();
		dg->nhap();
		Qly_docgia::quanly_docgia->them(dg);
	}
}
void Qly_ThuVien::MuonSach()
{
	int n;
	do
	{
		cout<<"nhap so luong phieu muon muon them : ";
		cin>>n;
	}while(n<0 && n>100);
	for(int i=0;i<n;i++)
	{
		Phieu_muon *pm=new Phieu_muon();
		pm->nhap();
		Qly_phieumuon::qly_phieumuon->them(pm);
	}
}
void Qly_ThuVien::InDSSach()
{
	Quanly_sach::qly_sach->xuat();
}
void Qly_ThuVien::InDSDocGia()
{
	Qly_docgia::quanly_docgia->xuat();
}
void Qly_ThuVien::InDSSachCon()
{
	Qly_phieumuon::qly_phieumuon->KiemTra();
	Quanly_sach::qly_sach->DanhSachSachCon();
}
void Qly_ThuVien::InDSSachDaMuon()
{
	Qly_phieumuon::qly_phieumuon->KiemTra();
	Quanly_sach::qly_sach->DanhSachSachDaMuon();
}
void Qly_ThuVien::InDanhSachDocGiaMuonSach()
{
	Qly_docgia::quanly_docgia->Docgia_muonsach();
}
void Qly_ThuVien::TraCuuDocGia()
{
	 unsigned int maDocGia;
     do
     {
		cout<<"Nhap ma doc gia: ";
	    cin>>maDocGia;
     }while (maDocGia<0);
	 Qly_docgia::quanly_docgia->Tim_docgia(maDocGia); 
}
void Qly_ThuVien::TraCuuSach()
{
	 unsigned int maSach;
     do
     {
		cout<<"Nhap ma sach: ";
        cin>>maSach;
     }while (maSach<0);
	 Quanly_sach::qly_sach->TimSach(maSach);
}

