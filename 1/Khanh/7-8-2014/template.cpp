#include<iostream>
#include<math.h>

using namespace std;

enum LoaiHinh
{
	eHinhVuong,
	eHinhTamGiac
};
class HinhHoc
{
private:
	LoaiHinh _loai;
public:
	HinhHoc(){}
	~HinhHoc(){}
	virtual void Nhap(){};
	virtual void Xuat(){ cout<<"day la hinh hoc"<<endl;}
	virtual int chu_vi(){return 0;}
};

enum canh_tam_giac
{
	canh_a,
	canh_b,
	canh_c
};
class HinhTamGiac: public HinhHoc
{
private:
	unsigned int _a,_b,_c;
	bool kiem_tra(unsigned int _a,unsigned int _b,unsigned int _c)
	{
		if(_a+_b>_c || _b+_c >_a || _a+_c>_b)
			return true;
		else return false;
	}
public:
	HinhTamGiac()
	{
		_a=0;
		_b=0;
		_c=0;
	}
	~HinhTamGiac(){}
	void Nhap()
	{
		int a,b,c;
		cout<<"nhap canh thu nhat"<<endl;
		cin>>a;
		cout<<"nhap canh thu hai"<<endl;
		cin>>b;
		cout<<"nhap canh thu ba"<<endl;
		cin>>c;
		if( set(a,b,c) ==true) cout<<"khoi tao thanh cong"<<endl;
		else cout<<"khoi tao false"<<endl;
	}
	bool set(unsigned int a, unsigned int b, unsigned int c)
	{
		if(a>0 && b>0 && c>0 && kiem_tra(a,b,c)==true)
		{
			this->_a=a;
			this->_b=b;
			this->_c=c;
			return true;
		}
		else return false;
	}
	bool set(canh_tam_giac canh, unsigned int gia_tri)
	{
		if(gia_tri ==0) return false;
		switch(canh)
		{
		case canh_a:
			if(kiem_tra(gia_tri,_b,_c)==false)
				return false;
			this->_a=gia_tri;
			break;
		case canh_b:
			if(kiem_tra(_a,gia_tri,_c)==false)
				return false;
			this->_b=gia_tri;
			break;
		case canh_c:
			if(kiem_tra(_a,_b,gia_tri)==false)
				return false;
			this->_c=gia_tri;
			break;
		}
	}
	int Get(canh_tam_giac canh)
	{
		if(canh==canh_a) return _a;
		if(canh==canh_b) return _b;
		if(canh==canh_c) return _c;
	}
	int chu_vi()
	{
		if(_a==0 || _b==0 || _c==0) exit(1);
		return _a+_b+_c;
	}
	void Xuat()
	{
		cout<<"A: "<<_a<<"B: "<<_b<<" C: "<<_c<<endl;
	}
};
class HinhVuong: public HinhHoc
{
private:
	unsigned int _A;
public:
	HinhVuong(){}
	~HinhVuong(){}
	void Nhap()
	{
		unsigned int A;
		cout<<"Nhap canh hinh vuong"<<endl;
		cin>>A;
		if(set(A)==true) cout<<"success"<<endl;
		else cout<<"faled"<<endl;
	}
	bool set(unsigned int a)
	{
		if(a>0) 
		{
			this->_A=a;
			return true;
		}
		else return false;
	}
	int get()
	{
		return _A;
	}
	int chu_vi()
	{
		return 4*_A;
	}
	void Xuat()
	{
		cout<<"canh hv: "<<_A<<endl;

	}
};

class Tap_Hop
{
private:
	static const int MAX = 10;
	HinhHoc* _hinh[MAX]; // array contains 10 HinhHoc pointers
	int so_luong;
public:
	Tap_Hop()
	{
		this->so_luong=0;
		for(int i=0; i<MAX; i++)
			_hinh[i]=NULL;
	}
	~Tap_Hop()
	{
		for(int i=0; i<0; i++)
			if( _hinh[i] !=NULL)
			{
				delete _hinh[i];
				_hinh[i]=NULL;
			}
			delete[] _hinh;
	}
	void Them(HinhHoc *hinh)
	{
		if(so_luong<MAX) _hinh[so_luong]=hinh;
		so_luong++;
	}
	int GetTongChuVi()
	{
		int tong=0;
		for (int i = 0; i < so_luong; i++)
		{
			if(_hinh[i]!=NULL)
			{
				return tong+=_hinh[i]->chu_vi();
			}
		}
	}
	int GetSoLuongHinh()
	{
		return so_luong;
	}
	void Xuat()
	{
		for (int i = 0; i < so_luong; i++)
		{
			if(_hinh[i]!=NULL)
			{
				cout<<"hinh thu "<<i+1<<endl;
				_hinh[i]->Xuat();
			}
		}
	}
		
};

int main()
{
	Tap_Hop *tapHop=new Tap_Hop();

	unsigned int n;
	cout<<"So luong hinh hoc: "<<endl;
	cin>>n;

	int i=0;
	while (i<n)
	{
		int tuyChon;
		do{
			cout<<"Nhan 1 de nhap hinh vuong!"<<endl;
			cout<<"Nhan 2 de nhap hinh tam giac!"<<endl;
			cin>>tuyChon;
		}while (tuyChon !=1 && tuyChon !=2);

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
		i++;
	}

	cout<<"So luong hinh hoc: "<<tapHop->GetSoLuongHinh()<<endl;
	cout<<"Tong chu vi la: "<<tapHop->GetTongChuVi()<<endl;
	cout<<"Danh sach cac hinh: "<<endl;
	tapHop->Xuat();
	return 0;
}