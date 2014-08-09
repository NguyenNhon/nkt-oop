#include <iostream>
#include <string>

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
	string ten;
	unsigned tuoi,luong;
	LoaiCN lcn;
public:
	virtual int Luong()
	{
		return 0;
	}
	LoaiCN GetLoai()
	{
		return lcn;
	}
	string GetName()
	{
		return ten;
	}
	virtual void Nhap()
	{
		cout<<"Nhap Thong Tin Cong Nhan";
	}
	void Xuat()
	{
		fflush(stdin);
		cout<<"\n Ten :"<<ten<<endl;
		cout<<"\n Tuoi :"<<tuoi<<endl;
		cout<<"\n luong :"<<Luong()<<endl;

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
		cout<<"Nhap Thong Tin Cong Nhan\n";
		cout<<"ten: ";
		/*ten=new char[20];*/
		cin>>ten;
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
		cout<<"Nhap Thong Tin Cong Nhan\n";
		cout<<"ten: ";
		/*ten=new char[20];*/
		cin>>ten;
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
		cout<<"Nhap Thong Tin Cong Nhan\n";
		cout<<"ten: ";
		/*ten=new char[20];*/
		cin>>ten;
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
	int FindName(string t)
	{
		for(int i=0;i<sl;i++)
		{
			if(t.compare(cn[i]->GetName())==0)
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
		unsigned int a=0,b=0,c=0;
		for(int i=1;i<sl;i++)
			switch(cn[i]->GetLoai())
			{
			case CNSX:a++;break;
			case CNKT:b++;break;
			case CNBH:c++;break;
			}
		cout<<"co "<<a<<" cnsx\n";
		cout<<"co "<<b<<" cnkt\n";
		cout<<"co "<<c<<" cnbh\n";
	}
	void XuatCN()
	{
		for(int i=0;i<sl;i++)
			cn[i]->Xuat();	

	}
	int GetSL()
	{return sl;}
};
void main()
{
	CongTy *ct=new CongTy();
	CongNhan *cn;
	int c;
	do
	{
		cout<<"1/Cong Nhan SX\n2/Cong Nhan KT\n3/ Cong Nhan BH\n -1/ dung nhap\n";
		cin>>c;
		switch(c)
		{
		case 1: cn=new CongNhanSX();break;
		case 2: cn=new CongNhanKT();break;
		case 3: cn=new CongNhanBH();break;
		}
		if(c!=-1)
		{
		cn->Nhap();
		ct->Add(cn);
		}

	}while(c!=-1);

	ct->XuatCN();
	ct->SoLuongTungLoai();
	cout<<"tong luong cong ty phai tra: "<<ct->tongluong();
	ct->Del(ct->FindName("a"));
	ct->XuatCN();


}