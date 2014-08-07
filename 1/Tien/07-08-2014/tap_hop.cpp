#include<iostream>

using namespace std;

enum LoaiHinh
{
	eHinhHoc,
	eHinhVuong,
	eHinhTamGiac
};
class HinhHoc
{
protected:
	LoaiHinh loai;
public:
	HinhHoc()
	{
		loai=eHinhHoc;
	}
	bool Setter(int tichcanh)
	{
		if(tichcanh==0)
			return false;
		return true;
	}
	virtual int GetCanh(char d)
	{
		return d;
	};
	virtual int ChuVi()
	{
		return 0;
	}
	virtual void Nhap()
	{
		cout<<"Nhap";	
	}
	LoaiHinh getloai()
	{
	 return loai;
	}
};

class HinhTamGiac: public HinhHoc
{
private :
	unsigned int A,B,C;
public:
	HinhTamGiac()
	{
		loai=eHinhTamGiac;
	}
	void Nhap()
	{
		do{
			cout<<"nhap do dai 3 canh"<<endl;
				cin>>A>>B>>C;
			if(SetterTamGiac()==false)
				cout<<"3 canh vua nhap khong the tao thanh 1 tam giac, vui long nhap lai"<<endl;
			
		}while(SetterTamGiac()==false);
		
	}
	int GetCanh(char d)
	{
		switch(d)
		{
		case 'a':return A;
		case 'b':return B;
		case 'c':return C;
		}
	}

	bool SetterTamGiac()
	{
		if(Setter(A*B*C)==false)
			return false;
		else
			if(A>=(B+C)||B>=(A+C)||C>=(A+B))
				return false;
		return true;
	}
	int ChuVi()
	{
		return	A+B+C;
	}
	LoaiHinh getloai()
	{
	 return loai;
	}
};
class HinhVuong: public HinhHoc
{
private:
	unsigned int a;
public:
	HinhVuong()
	{
		loai=eHinhVuong;
	}
	void Nhap()
	{
		
		do{
			cout<<"nhap do dai canh "<<endl;
			cin>>a;
			if(Setter(a)==false)
				cout<<"vui long nhap canh a>0"<<endl;

		}while(Setter(a)==false);
	}
	int GetCanh()
	{
		return a;
	}
	int ChuVi()
	{
		return a*4;
	}
	LoaiHinh getloai()
	{
	 return loai;
	}
};

class Tap_Hop: public HinhHoc
{
private:
	static const int MAX = 10;
	HinhHoc* hinh[MAX]; // array contains 10 HinhHoc pointers
	unsigned int soluong;
public:
	Tap_Hop()
	{
		soluong=0;
	}
	~Tap_Hop()
	{}
	void Them(HinhHoc *h)
	{
		hinh[soluong]=h;
		soluong++;
	}
	void Xuat()
	{
		for(int i=0;i<soluong;i++)
			cout<<hinh[i]->getloai()<<endl;
	}
	int GetSoLuongHinh()
	{
		return soluong;
	}
	int GetTongChuVi()
	{
		int tong=0;
		for(int i=0;i<soluong;i++)
			tong+=hinh[i]->ChuVi();
		return tong;
	}
};

int main()
{
	Tap_Hop *tapHop=new Tap_Hop();

	unsigned int n;
	cout<<"So luong hinh hoc: "<<endl;
	cin>>n;

	int i=0;
	while (i++<n)
	{
		int tuyChon;
		do{
			cout<<"Nhan 1 de nhap hinh vuong!"<<endl;
			cout<<"Nhan 2 de nhap hinh tam giac!"<<endl;
			cin>>tuyChon;
		}while (tuyChon != 1 && tuyChon !=2);

		HinhHoc *hinh;
		if(tuyChon==1)
		{
			hinh=new HinhVuong();			
		}else
		{
			hinh=new HinhTamGiac();
		}
		hinh->Nhap();

		tapHop->Them(hinh);
	}

	cout<<"So luong hinh hoc: "<<tapHop->GetSoLuongHinh()<<endl;
	cout<<"Tong chu vi la: "<<tapHop->GetTongChuVi()<<endl;
	cout<<"Danh sach cac hinh: "<<endl;
	tapHop->Xuat();

	delete tapHop;
	tapHop = NULL;
	return 0;
}