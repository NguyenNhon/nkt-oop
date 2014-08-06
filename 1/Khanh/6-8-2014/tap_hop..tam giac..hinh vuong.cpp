//Sr a...e lam xong lau oy mak quen nop :D//

#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
enum canh_tam_giac
{
	canh_a,
	canh_b,
	canh_c
};
class tam_giac
{
private:
	unsigned int _a,_b,_c;
	bool kt_dieu_kien(unsigned int _a, unsigned int _b, unsigned int _c)
	{
		if(_a+_b<_c || _b+_c<_a || _a+_c<_b)
			return false;
		return true;
	}
public:
	tam_giac()
	{
		_a=0;
		_b=0;
		_c=0;
	}

	tam_giac(unsigned int a, unsigned int b, unsigned int c)
	{
		if( set(a,b,c) == false) exit(1);
	}

	bool set(unsigned int a, unsigned int b, unsigned int c)
	{
		if(a>0 && b>0 && c>0 && kt_dieu_kien(a,b,c)==true)
		{
			this->_a=a;
			this->_b=b;
			this->_c=c;
			return true;
		}
		else return false;
	}

	int get_canh(canh_tam_giac canh)
	{
		if(canh==canh_a) return _a;
		if(canh==canh_b) return _b;
		if(canh==canh_c) return _c;
	}

	int tinh_chuvi()
	{
		if(_a==0 ||_b==0 || _c==0) exit(1);
		return _a+ _b +_c;
	}

	float tinh_dientich()
	{
		float p= this->tinh_chuvi()/2;
		return sqrt(p*(p-_a)*(p-_b)*(p-_c));
	}

	bool Set(canh_tam_giac canh, unsigned int gia_tri)
	{
		if(gia_tri==0)
			return false;

		switch (canh)
		{
		case canh_a:
			if(kt_dieu_kien(gia_tri, _b, _c)==false)
				return false;
			this->_a=_a;
			break;
		case canh_b:
			if(kt_dieu_kien(_b, gia_tri, _c)==false)
				return false;
			this->_b=gia_tri;
			break;
		case canh_c:
			if(kt_dieu_kien(_a, _b, gia_tri)==false)
				return false;
			this->_c=gia_tri;
			break;
		}
	}
	void Xuat_tamgiac()
	{
		cout<<"A: "<<_a<<"B: "<<_b<<" C: "<<_c<<endl;
	}
};
class hinh_vuong
{
	enum canh_hinh_vuong
	{
		canh_A
	};
private:
	unsigned int _a;
public:
	hinh_vuong()
	{
		_a=0;
	}

	hinh_vuong(unsigned int a)
	{
		set(a);
	}

	bool set(unsigned int a)
	{
		if (a>0) 
		{
			this->_a=a;
			return true;
		}
		else return false;
	}
	int get_canh()
	{
		return _a;
	}

	int tinh_chuvi()
	{
		if(_a==0) exit(1);
		else return 4*_a;
	}
	int tinh_dientich()
	{
		return _a*_a;
	}

	bool set(canh_hinh_vuong canh, unsigned int gia_tri)
	{
		if( gia_tri==0) return false;
		if(gia_tri>0) 
		{
			this->_a=gia_tri;
			return true;
		}
	}
	void Xuat_hinhvuong()
	{
		cout<<"canh hv: "<<_a<<endl;

	}
};

class Tap_hop
{
private:
	static const int MAX=20;
	tam_giac** _mang;
	hinh_vuong** mang;
	int so_luong;
public:
	Tap_hop()
	{
		this->so_luong=0;
		this->_mang= new tam_giac*[MAX];
		this->mang=new hinh_vuong*[MAX];
		for(int i=0; i<MAX; i++)
		{
			this->_mang[i]=NULL;
		}
		for(int j=0;j<MAX;j++)
		{
			this->mang[j]=NULL;
		}
	}
	~Tap_hop()
	{
		for(int i=0; i<so_luong; i++)
		{
			if(this->_mang!=NULL)
			{
				delete _mang[i];
				_mang[i]=NULL;
			}
		}
		delete[]_mang;

		for(int j=0; j<so_luong; j++)
		{
			if(this->mang[j]!=NULL)
			{
				delete mang[j];
				mang[j]=NULL;
			}
		}
		delete[] mang;
	}

	void them(tam_giac* tamgiac)
	{
		if(so_luong <MAX) _mang[so_luong]=tamgiac;
		so_luong++;
	}
	void them(hinh_vuong* hinhvuong)
	{
		if(so_luong <MAX) mang[so_luong]=hinhvuong;
		so_luong++;
	}
	int get_soluong()
	{
		return so_luong;
	}

	void Xuat()
	{
		for (int i = 0; i < so_luong; i++)
		{
			if(_mang[i]!=NULL)
			{
				_mang[i]->Xuat_tamgiac();
			}
		}
		for (int j = 0; j < so_luong; j++)
		{
			if(mang[j]!=NULL)
			{
				mang[j]->Xuat_hinhvuong();
			}
		}
	}

	int tinh_chu_vi()
	{
		int tong=0;
		for (int i = 0; i < so_luong; i++)
		{
			if(_mang[i]!=NULL)
			{
				tong+=_mang[i]->tinh_chuvi();
			}
		}

		for (int j = 0; j < so_luong; j++)
		{
			if(mang[j]!=NULL)
			{
				tong+=mang[j]->tinh_chuvi();
			}
		}

		return tong;
	}

	float tinh_dien_tich()
		{
		float Tong=0;
		for (int i = 0; i < so_luong; i++)
		{
			if(_mang[i]!=NULL)
			{
				Tong+=_mang[i]->tinh_dientich();
			}
		}

		for (int j = 0; j < so_luong; j++)
		{
			if(mang[j]!=NULL)
			{
				Tong+=mang[j]->tinh_dientich();
			}
		}

		return Tong;
	}
};

int main()
{
	Tap_hop* tap_hop= new Tap_hop();
	tap_hop->them(new tam_giac(2,3,5));
	tap_hop->them(new tam_giac(3,4,5));
	tap_hop->them(new tam_giac(5,6,7));

	tap_hop->them(new hinh_vuong(3));
	tap_hop->them(new hinh_vuong(4));
	tap_hop->them(new hinh_vuong(5));

	cout<<"So luong hinh trong tap hop: "<<tap_hop->get_soluong()<<endl;
	cout<<"Danh sach hinh trong tap hop: "<<endl;
	tap_hop->Xuat();

	cout<<"Tong chu vi: "<<tap_hop->tinh_chu_vi()<<endl;

	cout<<"Tong dien tich:"<<tap_hop->tinh_dien_tich()<<endl;

           
	return 0;
}



















