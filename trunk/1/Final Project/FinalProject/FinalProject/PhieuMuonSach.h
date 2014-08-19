#ifndef PHIEU_MUON_SACH_H
#define PHIEU_MUON_SACH_H

#include "DocGia.h"
#include "Sach.h"

class PhieuMuonSach
{
protected:
	unsigned int _ma;
	DocGia* _docGia;
	Sach* _sach[MAX_BORROW_BOOK];
	unsigned int _soLuongSach;
	string _ngayMuon;

	static unsigned int Dem;
public:
	PhieuMuonSach(string ngay, DocGia* docGia, Sach* sach[], int soLuong)
	{
		Dem++;
		_ma=Dem;

		_ngayMuon=ngay;
		_docGia=docGia;
		_soLuongSach=soLuong;
		for (int i=0; i<soLuong; ++i)
		{
			_sach[i]=sach[i];
		}
	}

	unsigned int* DanhSachSach(unsigned int maDocGia, unsigned int &soLuong)
	{
		if(_docGia->MaDocGia()==maDocGia)
		{
			unsigned int *result=new unsigned int[_soLuongSach];

			for (int i = 0; i < _soLuongSach; i++)
			{
				result[i]=_sach[i]->MaSach();
			}
			soLuong=_soLuongSach;
			return result;
		}
		soLuong=0;
		return NULL;
	}

	unsigned int MaDocGia(){return _docGia->MaDocGia();}

	bool ChuaMaSach(unsigned int maSach)
	{
		for (int i = 0; i < _soLuongSach; i++)
		{
			if(_sach[i]->MaSach()==maSach)
				return true;
		}
		return false;
	}
};
unsigned int PhieuMuonSach::Dem = 0;
#endif