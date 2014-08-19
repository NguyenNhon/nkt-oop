#ifndef TAP_HOP_DOC_GIA_H
#define TAP_HOP_DOC_GIA_H

#include "DocGia.h"

class TapHopDocGia
{
protected:
	DocGia* _docGia[MAX_READER];
	unsigned int _viTri;
	TapHopDocGia()
	{
		_viTri=0;
		for (int i=0; i<MAX_READER; ++i)
		{
			_docGia[i]=NULL;
		}
	}
public:
	static TapHopDocGia* tapHopDocGia;

	~TapHopDocGia()
	{
		for (int i = 0; i <_viTri ; i++)
		{
			delete _docGia[i];
			_docGia[i]=NULL;
		}
	}

	void ThemDocGia()
	{
		string ten;
		unsigned int tuoi;

		cout<<"Nhap Tuoi: ";
		cin>>tuoi;
		cin.ignore();
		cout<<"Nhap ten: ";
		getline(cin, ten);

		if(_viTri<MAX_READER-1)
		{
			_docGia[_viTri] = new DocGia(ten, tuoi);
			_viTri++;
		}
	}	

	DocGia* TimDocGia(int maDocGia)
	{
		for (int i = 0; i < _viTri; i++)
		{
			if(_docGia[i]->MaDocGia()==maDocGia)
				return _docGia[i];
		}
		return NULL;
	}

	void InDanhSach()
	{
		if(_viTri==0)
		{
			cout<<"Khong co doc gia!"<<endl;
		}
		else
		{
			for (int i = 0; i < _viTri; i++)
			{
				cout<<"Ma: "<<_docGia[i]->MaDocGia()<<" Ten: "<<_docGia[i]->Ten()<<" Tuoi: "<<_docGia[i]->Tuoi()<<endl;
			}
			cout<<endl;
		}
	}
};

TapHopDocGia* TapHopDocGia::tapHopDocGia=new TapHopDocGia();
#endif