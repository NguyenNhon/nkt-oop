#include"qlysach.h"
#include"qlydocgia.h"
void main()
{
	Qly_sach *qly=new Qly_sach();
	int n;
	cout<<"nhap so sach: "<<endl;
	cin>>n;
	for(int i=0; i<n;i++)
	{
		int tuychon;
		do
		{
			cout<<"nhan 1 de nhap sgk!"<<endl;
			cout<<"nhan 2 de nhap sgt!"<<endl;
			cin>>tuychon;
		}while(tuychon!=1 && tuychon!=2);
		sach *s;
		if(tuychon==1) s= new sachGK();
		else s= new sachGT();
		s->nhap();
		qly->them(s);
	}
	qly->xuat();
}






	
