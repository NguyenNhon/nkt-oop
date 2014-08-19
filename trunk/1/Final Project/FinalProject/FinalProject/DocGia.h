#ifndef DOC_GIA_H
#define DOC_GIA_H

#include "BienToanCuc.h"

class DocGia
{
protected:
	eLoaiDocGia _loai;
	string _ten;
	unsigned int _tuoi;
	unsigned int _ma;
	static unsigned int Dem;
public:
	DocGia(string ten, unsigned int tuoi)
	{
		++Dem;
		_ma=Dem;

		_ten=ten;
		_tuoi=tuoi;
		if(tuoi<18)
			_loai=eLoaiDocGia::eThieuNhi;
		else if(tuoi<36)
			_loai=eLoaiDocGia::eThieuNien;
		else 
			_loai=eLoaiDocGia::eTrungNien;
	}

	void Xuat()
	{
		cout<<"Ma: "<<_ma<<" Ten: "<<_ten<<" Loai: "<<_loai<<endl;
	}

	int MaDocGia(){return _ma;}

	string Ten(){return _ten;}

	unsigned int Tuoi(){return _tuoi;}

	eLoaiDocGia Loai(){return _loai;}
};

unsigned int DocGia::Dem = 0;

#endif