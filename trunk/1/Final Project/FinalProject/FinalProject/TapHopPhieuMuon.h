#ifndef TAP_HOP_PHIEU_MUON_H
#define  TAP_HOP_PHIEU_MUON_H

#include "PhieuMuonSach.h"
#include "TapHopDocGia.h"
#include "TapHopSach.h"

class TapHopPhieuMuon
{
protected:
	unsigned int _viTri;
	PhieuMuonSach* _phieuMuon[MAX_PHIEU_MUON];

	TapHopPhieuMuon()
	{
		_viTri=0;
		for (int i = 0; i < MAX_PHIEU_MUON; i++)
		{
			_phieuMuon[i]=NULL;
		}
	}

public:
	static TapHopPhieuMuon* tapHopPhieuMuon;

	~TapHopPhieuMuon()
	{
		for (int i = 0; i < _viTri; i++)
		{
			delete _phieuMuon[i];
			_phieuMuon[i]=NULL;
		}
	}

	void Them()
	{
		// Tim doc gia
		DocGia* docGia;
		do 
		{
			unsigned int maDocGia;
			cout<<"Nhap ma doc gia: ";
			cin>>maDocGia;
			docGia = TapHopDocGia::tapHopDocGia->TimDocGia(maDocGia);
		} while (docGia==NULL);

		// Danh sach sach
		unsigned int soLuong;
		do 
		{
			cout<<"Nhap so luong sach: ";
			cin>>soLuong;
		} while (soLuong<1 && soLuong>TapHopSach::tapHopSach->SoLuongSach());

		Sach** mangSach;
		mangSach=new Sach*[soLuong];

		for (int i = 0; i < soLuong; i++)
		{
			unsigned int maSach;
			do 
			{
				cout<<"Nhap ma sach: ";
				cin>>maSach;
				Sach* sach = TapHopSach::tapHopSach->TimSach(maSach);
				if(sach!=NULL)
				{
					mangSach[i]=sach;
					sach->ChoMuon();
					break;
				}
			} while (1);
		}

		_phieuMuon[_viTri] = new PhieuMuonSach("23",docGia,mangSach, soLuong);
		++_viTri;
	}

	unsigned int* DanhSachSachMuonTheoDocGia(unsigned int maDocGia, unsigned int &soLuong)
	{
		for (int i = 0; i < _viTri; i++)
		{
			unsigned int* ketQua=_phieuMuon[i]->DanhSachSach(maDocGia, soLuong);
			if(ketQua!=NULL)
			{
				return ketQua;
			}
		}
		return NULL;
	}

	void InDanhSachDocGiaMuon()
	{
		if(_viTri>0)
		{
			for (int i = 0; i < _viTri; i++)
			{
				cout<<"Ma: "<<_phieuMuon[i]->MaDocGia()<<endl;
			}
		}
		else 
		{
			cout<<"Khong co phieu muon!"<<endl;
		}
	}

	unsigned int DocGiaMuonSach(unsigned int maSach)
	{
		for (int i = 0; i < _viTri; i++)
		{
			if(_phieuMuon[i]->ChuaMaSach(maSach)==true)
				return _phieuMuon[i]->MaDocGia();
		}
		return -1;
	}
};

TapHopPhieuMuon* TapHopPhieuMuon::tapHopPhieuMuon = new TapHopPhieuMuon();

#endif