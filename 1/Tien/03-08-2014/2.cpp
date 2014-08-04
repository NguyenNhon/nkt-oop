#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

class TamGiac
{
private:
	int A, B, C;
public:
	
	TamGiac()
	{};

	~TamGiac()
	{
		/*cout << "Ham nay duoc goi truoc khi doi tuong bi huy!" << endl;*/
	}
	int GetA()
	{
		return this->A;
	}
	int  GetB()
	{
		return this->B;
	}
	int  GetC()
	{
		return this->C;
	}

	void SetTamGiac(int a,int b,int c)
	{
		
		if (a>=(b + c) || b>=(a + c) || c>=(a + b))
		{
			cout << "3 canh tren k the tao thanh 1 tam giac!\n";
		}
		else
		{
			A = a;
			B = b;
			C = c;
		}
	}
	void Nhap()
	{
		int a,b,c;
		cout<<"nhap cac canh tam giac:\n";
		cin>>a>>b>>c;
		SetTamGiac(a,b,c);
	}

	int ChuVi()
	{
		return this->A + this->B + this->C;
	}

	float DienTich()
	{
		float p= ChuVi()/float (2);
		 float s=sqrt(p*(p - GetA())*(p - GetB())*(p -GetC()));
		 return s;
	}
	void InTamGiac()
	{
		cout<< " a=" <<GetA() << " b=" << GetB() << " c=" << GetC() << "\n";
	}

};
class TapHopTamGiac
{
private:
	int soluong;
	TamGiac mang[20];
public:
	TapHopTamGiac()
	{
			soluong=0;
	}
	int GetSL()
	{
		return this->soluong;
	}

	void Add(TamGiac tg)
	{
		
		mang[soluong] = tg;
		soluong = soluong + 1;
	}
	
	int TongCV()
	{
		int tong = 0;
		for (int i = 0; i<soluong; i++)
		{
			tong = tong + this->mang[i].ChuVi();
		}
		return tong;
	}
	float TongDT()
	{
		float tong = 0;
		for (int i = 0; i<soluong; i++)
		{
			tong = tong + mang[i].DienTich();
		}
		return tong;
	}
	void SapXep()
	{
		for (int i = 0; i<soluong - 1; i++)
		for (int j = i + 1; j<soluong; j++)
		if (mang[i].ChuVi()>mang[j].ChuVi())
		{
			TamGiac tam = mang[i];
			mang[i] = mang[j];
			mang[j] = tam;
		}
	}
	void InTapHop()
	{
		for (int i = 0; i<soluong; i++)
			mang[i].InTamGiac();
	}
};
void main()
{
	TamGiac tg1;
	TapHopTamGiac th;
	int c;
	do
	{
		cout<<"de nhap du lieu nhap 1, thoat nhap 0 : ";
		cin>>c;
		if (c==1)
		{
			tg1.Nhap();
			th.Add(tg1);
		}

	}while(c!=0);

	cout<<"so luong tam giac: "<<th.GetSL();
	th.InTapHop();
	cout<<"tong dien tich:"<<th.TongDT()<<endl;
	cout<<"tong chu vi:"<<th.TongCV()<<endl;

	th.SapXep();
	th.InTapHop();
	
	/*tg1.InTamGiac();
	cout<<"chu vi :"<<tg1.ChuVi()<<endl;
	cout<<"dien tich:"<<tg1.DienTich()<<endl;*/
}