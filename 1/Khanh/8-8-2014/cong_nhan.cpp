#include<iostream>
#include<string>
using namespace std;
enum loai_cong_nhan
{
	CNSX,
	CNKT,
	CNBH
};
class cong_nhan
{
public:
	loai_cong_nhan loai;
	string ten;
	int tuoi;
	virtual void nhap(){}
	virtual void xuat(){}
	virtual int luong(){return 0;}
	loai_cong_nhan get_loai() {return loai;}
};
class SX: public cong_nhan
{
private:
	int san_pham;
public:
	SX()
	{
		loai=loai_cong_nhan::CNSX;
	}
	~SX(){}
	void nhap()
	{
		fflush(stdin);
		cout<<"nhap ten nhan vien"<<endl;
		getline(cin,ten);
		cin.ignore();
		cout<<"nhap tuoi"<<endl;
		cin>>tuoi;
		cout<<"nhap so sp: "<<endl;
		cin>>san_pham;
	}
	int luong()
	{
		return san_pham*13;
	}	
	void xuat()
	{
		cout<<"ten: "<<endl;
		cout<<ten;
	}
};
class KT: public cong_nhan
{
private:
	int ngay_laodong;
public:
	KT()
	{
		loai=loai_cong_nhan::CNKT;
	}
	~KT(){}
	void nhap()
	{
		fflush(stdin);
		cout<<"nhap ten nhan vien"<<endl;
		getline(cin,ten);
		cin.ignore();
		cout<<"nhap tuoi"<<endl;
		cin>>tuoi;
		cout<<"nhap so ngay lao dong: "<<endl;
		cin>>ngay_laodong;
	}
	int luong()
	{
		return ngay_laodong*150;
	}
	void xuat()
	{
		cout<<"ten: "<<endl;
		cout<<ten;
	}
};
class BH: public cong_nhan
{
private:
	int ngay_laodong, hang_hoa;
public:
	BH()
	{
		loai=loai_cong_nhan::CNBH;
	}
	~BH(){}
	void nhap()
	{
		fflush(stdin);
		cout<<"nhap ten nhan vien"<<endl;
		getline(cin,ten);
		cin.ignore();
		cout<<"nhap tuoi"<<endl;
		cin>>tuoi;
		cout<<"nhap so ngay lao dong & so hang ban dc: "<<endl;
		cin>>ngay_laodong>>hang_hoa;
	}
	int luong()
	{
		return ngay_laodong*150 + hang_hoa*16;
	}
	void xuat()
	{
		cout<<"ten: "<<endl;
		cout<<ten;
	}
};
class tap_hop
{
private:
	static const int max=100;
	cong_nhan* congnhan[max];
	int so_luong;
public:
	tap_hop()
	{
		this->so_luong=0;
		for(int i=0;i<max;i++)
			congnhan[i]=NULL;
	}
	~tap_hop()
	{
		for(int i=0;i<max;i++)
			if(congnhan[i]!=NULL)
			{
				delete congnhan[i];
				congnhan[i]=NULL;
			}
		delete[] congnhan;
	}
	void them(cong_nhan *cn)
	{
		if(so_luong<max) congnhan[so_luong]=cn;
		so_luong++;
	}
	int tim(string s)
	{
		for(int i=0; i<so_luong; i++)
			if(s.compare(congnhan[i]->ten)==0) return i;
			return -1;
	}
	void xoa(string s)
	{
		for(int i=0; i<so_luong; i++)
		{
			if(s.compare(congnhan[i]->ten)==0)
			{
				while(i!=(so_luong-1))
				{
					congnhan[i]=congnhan[i+1];
					i++;
				}
				so_luong--;
			}
		}
	}
	void xuat()
	{
		for(int i=0; i<so_luong; i++)
		{
			cout<<"cong nhan thu: "<<i+1<<endl;
			cout<<congnhan[i]->ten<<endl;
			cout<<congnhan[i]->luong()<<" ngan dong"<<endl;
		}
	}
	int tong_luong()
	{
		int tong;
		for(int i=0; i<so_luong; i++)
		{
			return tong+= congnhan[i]->luong();
		}
	}
	void get_loai()
	{
		int a=0,b=0,c=0;
		for(int i=0; i<so_luong; i++)
		{
			if(congnhan[i]->loai==0) a++;
			else if(congnhan[i]->loai==1) b++;
			else c++;
		}
		cout<<"CSSX: "<<a<<"CNKT: "<<b<<"CNBH: "<<c<<endl;
	}
};
int main()
{
	tap_hop* taphop=new tap_hop();
	int n;
	cout<<"nhap so cong nhan: "<<endl;
	cin>>n;
	string s1,s2;
	int i=0;
	while(i<n)
	{
		int tuyChon;
		do
		{
			cout<<"Nhan 1 de nhap CNSX!"<<endl;
			cout<<"Nhan 2 de nhap CNKT!"<<endl;
			cout<<"Nhan 3 de nhap CNBH!"<<endl;
			cin>>tuyChon;
		}while (tuyChon !=1 && tuyChon !=2 && tuyChon !=3 );
		cong_nhan *cn;
		if(tuyChon ==1) cn=new SX();
		else if(tuyChon==2) cn= new KT();
		else cn=new BH();
		cn->nhap();
		taphop->them(cn);
		i++;
	}

	fflush(stdin);
	cout<<"nhap ten can tim"<<endl;
	getline(cin,s1);
	cout<<"vi tri tim thay: "<<taphop->tim(s1)<<endl;
	
	fflush(stdin);
	cout<<"nhap nhan vien can xoa"<<endl;
	getline(cin,s2);
	taphop->xoa(s2);
	cout<<"vi tri tim thay: "<<taphop->tim(s2)<<endl;

	cout<<"danh sach nhan vien: "<<endl;
	taphop->xuat();

	taphop->get_loai();
	return 0;
}

		