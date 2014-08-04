#include<iostream>
using namespace std;

class tam_giac
{
private:
	float _a,_b,_c;
public:
	//contructor
	tam_giac(float a, float b, float c)
	{
		setter(a,b,c);
	}
	//destructor
	~tam_giac()
	{
		cout<<"the end"<<endl;
	}
	float getter_1()
	{
		cout<<"do dai canh 1"<<endl;
		return _a;
	}
	float getter_2()
	{
		cout<<"do dai canh 2"<<endl;
		return _b;
	}
	float getter_3()
	{
		cout<<"do dai canh 3"<<endl;
		return _c;
	}
	void setter(float a, float b, float c)
	{
		if((a+b<c) && (a+c<b) && (c+b<a)) 
		{
			_a=a;
			_b=b;
			_c=c;
		}
		else exit(1);
		
	}
};
int main()
{
	float a,b,c;
	do
	{
		cout<<" nhap do dai 3 canh"<<endl;
		cin>>a>>b>>c;
	}while(a<=0 || b<=0 ||c<=0);
	tam_giac tamgiac(a,b,c);
	cout<<tamgiac.getter_1()<<endl;
	cout<<tamgiac.getter_2()<<endl;
	cout<<tamgiac.getter_3()<<endl;

	return 0;
}