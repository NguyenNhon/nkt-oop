#include"quanlydocgia.h"

Qly_docgia::Qly_docgia()
{
	so_luong=0;
	for(int i=0;i<MAX_READER;i++)
		_mang[i]=NULL;
}
Qly_docgia::~Qly_docgia()
{
	for(int i=0;i<MAX_READER;i++)
		if(_mang[i] != NULL)
		{
			delete _mang[i];
			_mang[i]= NULL;
		}
	delete[] _mang;
}

void Qly_docgia::them(Doc_gia* docgia)
{
	if(so_luong < MAX_READER)
		_mang[so_luong] = docgia;
	so_luong++;
}

void Qly_docgia::xuat()
{
	for(int i=0;i<so_luong;i++)
		_mang[i]->xuat();
}
void Qly_docgia::Docgia_muonsach()
{
	for(int i=0;i<so_luong;i++)
		for(int j=0;j<Qly_phieumuon::qly_phieumuon->so_luong;j++)
			if(_mang[i]->_ma==Qly_phieumuon::qly_phieumuon->_mang[j]->ma_docgia)
				_mang[i]->xuat();
}
void Qly_docgia::Tim_docgia(unsigned int maDocGia)
{
	cout<<"Ket qua :"<<endl;
	int dem=0;
	for(int i=0;i<so_luong;i++)
		if(maDocGia==_mang[i]->_ma)
		{
			dem++;
			_mang[i]->xuat();
		}
	if(dem==0) cout<<"khong tim thay doc gia"<<endl;
}

Qly_docgia* Qly_docgia::quanly_docgia=new Qly_docgia();