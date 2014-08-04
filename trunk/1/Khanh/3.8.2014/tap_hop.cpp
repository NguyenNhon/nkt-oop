#include<iostream>
using namespace std;

class tam_giac
{
private:
	float _a,_b,_c;
public:
	void input()
	{
		do
	{
		cout<<" nhap do dai 3 canh"<<endl;
		cin>>_a>>_b>>_c;
	}while(_a<=0 || _b<=0 ||_c<=0);
	setter();
	}

	void setter()
	{
		if((_a+_b<_c) || (_a+_c<_b) || (_c+_b<_a)) 
		exit(1);
	}

	float chu_vi()
	{ 
		return (float)_a+_b+_c;
	}

	float dien_tich()
	{	
		float p=(_a+_b+_c)/2;
		return (float)(sqrt(p*(p-_a)*(p-_b)*(p-_c)));
	}
	float out_1()
	{
		cout<<"do dai canh 1"<<endl;
		return _a;
	}
	float out_2()
	{
		cout<<"do dai canh 2"<<endl;
		return _b;
	}
	float out_3()
	{
		cout<<"do dai canh 3"<<endl;
		return _c;
	}
};
class taphop_tamgiac
{
private:
	tam_giac a[20];
	int n;
public:
	void array_input()
	{
		cout<<"nhap so tam giac"<<endl;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cout<<"nhap tam giac thu "<<i+1<<endl;
			a[i].input();
		}
	}

	void add()
	{
		cout<<"nhap tam giac thu :"<<n+1<<endl;
		a[n].input();
		n+=1;
	}

	void array_output()
	{
		for(int i=0; i<n; i++)
		{
			cout<<"tam giac thu :"<<i+1<<endl;
			cout<<a[i].out_1()<<endl;
			cout<<a[i].out_2()<<endl;
			cout<<a[i].out_3()<<endl;
		}
	}

	float tong_chuvi()
	{
		float p=0;
		for(int i=0; i<n; i++)
		{
			p+= a[i].chu_vi();
		}
		return p;
	}

	float tong_dientich()
	{
		float s=0;
		for(int i=0; i<n; i++)
		{
			s+= a[i].dien_tich();
		}
		return s;
	}
	void sapxep()
	{
		for(int i=0; i<n; i++)
		{
			if(a[i].chu_vi()>a[i+1].chu_vi())
			{
				a[n]=a[i];
				a[i]=a[i+1];
				a[i+1]=a[n];
			}
		}
	}

};

int main()
{
	taphop_tamgiac taphop;
	taphop.array_input();
	taphop.add();
	cout<<" tong chu vi: "<<endl;
	cout<<taphop.tong_chuvi()<<endl;
	cout<<" tong dien tich: "<<endl;
	cout<<taphop.tong_dientich()<<endl;
	cout<<"in tam giac"<<endl;
	taphop.array_output();
	cout<<"SAP XEP"<<endl;
	taphop.sapxep();
	taphop.array_output();
	
	return 0;
}