#ifndef SACH_H
#define SACH_H

#include"BienToanCuc.h"

class Sach
{
protected:
	unsigned int _maSach;
	unsigned int _giaTien;
	string _tenSach;
	eLoaiSach _loaiSach;
	eTinhTrang _tinhTrang;
	static unsigned int SoSach;
public:
	Sach(int gia, string tenSach)
	{
		SoSach+=1;

		_maSach=SoSach;
		_giaTien=gia;
		_tenSach=tenSach;
		_tinhTrang=eTinhTrang::eCon;
	}	

	int MaSach(){return _maSach;}
	int GiaTien(){return _giaTien;}
	string TenSach(){return _tenSach;}
	eLoaiSach LoaiSach(){return _loaiSach;}
	virtual void Xuat()
	{
		cout<<"Ma: "<<_maSach<<" Gia: "<<_giaTien<<" Tac gia: "<<_tenSach<<" ";
	}

	void ChoMuon()
	{
		_tinhTrang=eTinhTrang::eHet;
	}

	eTinhTrang TinhTrang(){return _tinhTrang;}
};
unsigned int Sach::SoSach = 0;

#endif
