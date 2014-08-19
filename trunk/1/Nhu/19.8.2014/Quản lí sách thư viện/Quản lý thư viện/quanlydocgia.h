#ifndef qly_docgia
#define qly_docgia

#include"docgia.h"
#include"qlyphieumuon.h"

class Qly_docgia
{
private:
	Qly_docgia();
	Doc_gia* _mang[MAX_READER];
public:
	int so_luong;
	~Qly_docgia();
	static Qly_docgia* quanly_docgia;
	void them(Doc_gia* docgia);
	void xuat();
	void Tim_docgia(unsigned int maDocGia);
	void Docgia_muonsach();
};

#endif