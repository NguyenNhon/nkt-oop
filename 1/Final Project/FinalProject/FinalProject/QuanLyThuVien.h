#ifndef QUAN_LY_THU_VIEN_H
#define QUAN_LY_THU_VIEN_H

#include "TapHopSach.h"
#include "TapHopPhieuMuon.h"
#include "TapHopDocGia.h"

class QuanLyThuVien
{ 	
public:
	QuanLyThuVien()
	{

	}

	void ThemSach()
	{
		TapHopSach::tapHopSach->ThemSach();
	}
	void ThemDocGia()
	{
		TapHopDocGia::tapHopDocGia->ThemDocGia();
	}
	void MuonSach()
	{
		TapHopPhieuMuon::tapHopPhieuMuon->Them();
	}
	void InDanhSachSach()
	{
		TapHopSach::tapHopSach->InDanhSach();
	}
	void InDanhSachDocGia()
	{
		TapHopDocGia::tapHopDocGia->InDanhSach();
	}
	void InDanhSachSachCon()
	{
		TapHopSach::tapHopSach->InSachChuaMuon();
	}
	void InDanhSachSachDaMuon()
	{
		TapHopSach::tapHopSach->InDanhSachDaMuon();
	}
	void InDanhSachDocGiaMuonSach()
	{
		TapHopPhieuMuon::tapHopPhieuMuon->InDanhSachDocGiaMuon();
	}
	void TraCuuDocGia()
	{
		// Tim doc gia
		unsigned int maDocGia;
		do
		{
			cout<<"Nhap ma doc gia: ";
			cin>>maDocGia;
		}while (maDocGia<0);
		DocGia* docGia=TapHopDocGia::tapHopDocGia->TimDocGia(maDocGia);
		if(docGia==NULL)
		{
			cout<<"Khong tim thay doc gia!"<<endl;
			return;
		}
		cout<<"Ten: "<<docGia->Ten()<<" Tuoi: "<<docGia->Tuoi()<<endl;		

		// Tim danh sach sach doc gia da muon
		unsigned int soLuong=0;
		unsigned int* danhSachSach=TapHopPhieuMuon::tapHopPhieuMuon->DanhSachSachMuonTheoDocGia(maDocGia, soLuong);
		if(danhSachSach!=NULL)
		{
			cout<<"Danh sach sach da muon!"<<endl;
			for (int i = 0; i < soLuong; i++)
			{
				cout<<danhSachSach[i]<<" ";
			}
			cout<<endl;			
		}
		else 
		{
			cout<<"Tac gia chua muon sach!"<<endl;
		}
	}

	void TraCuuSach()
	{
		// Tim sach
		unsigned int maSach;
		do
		{
			cout<<"Nhap ma sach: ";
			cin>>maSach;
		}while (maSach<0);
		Sach* sach=TapHopSach::tapHopSach->TimSach(maSach);
		if(sach==NULL)
		{
			cout<<"Khong tim thay sach!"<<endl;
			return;
		}
		cout<<"Ma: "<<sach->MaSach()<<" Ten: "<<sach->TenSach()<<" Gia: "<<sach->GiaTien()<<endl;		

		if(sach->TinhTrang()==eTinhTrang::eCon)
		{
			cout<<"Sach chua cho muon!"<<endl;
			return;
		}

		// Tim  doc gia da muon
		unsigned int maDocGia=TapHopPhieuMuon::tapHopPhieuMuon->DocGiaMuonSach(maSach);
		if(maDocGia!=-1)
		{
			cout<<"Ma Doc gia muon: "<<maDocGia<<endl;			
		}
		else 
		{
			cout<<"Khong tim thay doc gia da muon!"<<endl;
		}
	}
};
#endif