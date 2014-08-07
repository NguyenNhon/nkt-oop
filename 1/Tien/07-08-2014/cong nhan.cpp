#include <iostream>
#include <string.h>

using namespace std;

enum LoaiCN
{
	CNSX,
	CNBH,
	CNKT
};
class CongNhan
{
protected:
	char *ten;
	unsigned tuoi,luong;
	LoaiCN lcn;
public:
	virtual int Luong()
	{
		return 0;
	}
	char *GetName()
	{
		return ten;
	}
	virtual void Nhap()
	{
		cout<<"Nhap Thong Tin Cong Nhan";
	}
};
class CongNhanSX:public::CongNhan
{
private:
	int sosp;
public:
	CongNhanSX()
	{
		lcn=CNSX;
	}
	int Luong()
	{
		return sosp*13;
	}
	 void Nhap()
	{
		cout<<"Nhap Thong Tin Cong Nhan";
		cout<<"ten: ";
		ten=new char[20];
		cin>>*ten;
		cout<<"tuoi: ";
		cin>>tuoi;
		cout<<"so san pham: ";
		cin>>sosp;
	}
};
class CongNhanKT:public::CongNhan
{
	private:
	int songayld;
public:
	CongNhanKT()
	{
		lcn=CNKT;
	}
	int Luong()
	{
		return songayld*150;
	}
	 void Nhap()
	{
		cout<<"Nhap Thong Tin Cong Nhan";
		cout<<"ten: ";
		ten=new char[20];
		cin>>*ten;
		cout<<"tuoi: ";
		cin>>tuoi;
		cout<<"so ngay lao dong: ";
		cin>>songayld;
	}
};

class CongNhanBH:public::CongNhan
{
	private:
	int songayld,sohang;
public:
	CongNhanBH()
	{
		lcn=CNBH;
	}
	int Luong()
	{
		return songayld*150+sohang*16;
	}
	void Nhap()
	{
		cout<<"Nhap Thong Tin Cong Nhan";
		cout<<"ten: ";
		ten=new char[20];
		cin>>*ten;
		cout<<"tuoi: ";
		cin>>tuoi;
		cout<<"so ngay lao dong: ";
		cin>>songayld;
		cout<<"so hang ban duoc";
		cin>>sohang;
	}
};

class CongTy:public::CongNhan
{
private:
	CongNhan *cn[100];
	unsigned int sl;
public:
	CongTy()
	{
		sl=0;
	}
	~CongTy()
	{}

	void Add(CongNhan *a)
	{
		cn[sl]=a;
		sl++;
	}
	int FindName(char t[])
	{
		for(int i=0;i<sl;i++)
		{
			if(strcmp(t,cn[i]->GetName())==1)
				return i;
		}
		return -1;
	}
	void Del(int i)
	{
		for(i;i<sl;i++)
			cn[i]=cn[i+1];
	}
	int tongluong()
	{
		int tong=0;
		for(int i=0;i<sl;i++)
			tong+=cn[i]->Luong();
		return tong;
	}
	void SoLuongTungLoai()
	{
		unsigned int a,b,c;
		for(int i=1;i<sl;i++)
		{
			switch(cn[i]->)
		}
	}
};
void main()
{
	
}