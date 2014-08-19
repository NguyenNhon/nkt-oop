#ifndef doc_gia
#define doc_gia

#include<iostream>
#include<string>
#include"bien_toan_cuc.h"

using namespace std;

class Doc_gia
{
private:
	string ho_ten;
	unsigned int tuoi;
	/*LoaiDocGia _loai_docgia;*/
public:
	unsigned int _ma;
	static unsigned int _dem;
	Doc_gia();
	~Doc_gia();
	void nhap();
	void xuat();
	LoaiDocGia Get_loai();
};
#endif