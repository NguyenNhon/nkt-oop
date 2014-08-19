#include"phieumuon.h"

unsigned int phieumuon::dem=0;
void phieumuon::nhap()
{
	++dem;
	_ma=dem;
	cout<<"nhap ngay muon sach: "<<ngay<<endl;
	fflush(stdin);
	getline(cin,ngay);
	cout<<"nhap ma doc gia muon sach: "<<endl;
	cin>>ma_dg;
	cout<<"nhap so sach muon: "<<endl;
	cin>>sl_sach;
	cout<<"nhap thu tu ma sach muon: "<<endl;
	for(int i=0; i<sl_sach; i++)
	{
		fflush(stdin);
		cin>>a[i];
		for(int j=0;j<Qly_sach::qlysach->sl; j++)
		{
			if(a[i]== Qly_sach::qlysach->qly[j]->_ma) 
			{
				if(Qly_sach::qlysach->qly[j]->tinhtrang== eTinhTrang::het) 
				{
					cout<<"sach da dc muon, xin vui long muon sach khac"<<endl ;
					i--;
					break;
				}
				else
				{
					Qly_sach::qlysach->qly[j]->tinhtrang= eTinhTrang::het;
					break;
				}
			}
			else
			{
				cout<<" ma sach ko ton tai, vui long kiem tra lai"<<endl;
				i--;
				break;
			}
		}

	}
}
void phieumuon::xuat()
{
	cout<<"ma phieu muon: "<<_ma<<" ngay muon: "<<ngay<<" ma docgia muon sach: "<<ma_dg<<endl;
	cout<<"ma sach docgia muon: "<<endl;
	for(int i=0; i<sl_sach;i++)
		cout<<a[i]<<"\t";
}
