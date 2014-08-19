#include"qlythuvien.h"
#include"qlysach.h"
void Qly_thuvien::themsach()
{
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
		Qly_sach::qlysach->them(s);
	}
}
void Qly_thuvien::themdocgia()
{
	int m;
	cout<<"nhap so docgia: "<<endl;
	cin>>m;
	for(int i=0; i<m;i++)
	{
		docgia *dg;
		dg=new docgia();
		dg->nhap();
		Qly_docgia::qlydocgia->them(dg);
	}
}
void Qly_thuvien::muon()
{
	int k;
	cout<<"nhap so phieumuon: "<<endl;
	cin>>k;
	for(int i=0; i<k;i++)
	{
		phieumuon *pm;
		pm= new phieumuon();
		pm->nhap();
		Qly_phieumuon::qlyphieumuon->them(pm);
	}
}
void Qly_thuvien::indanhsachsach()
{
	Qly_sach::qlysach->xuat();
}
void Qly_thuvien::indanhsachdocgia()
{
	Qly_docgia::qlydocgia->xuat();
}
void Qly_thuvien::indanhsachsachchuamuon()
{
	Qly_phieumuon::qlyphieumuon->sach_con();
}
void Qly_thuvien::indanhsachsachdamuon()
{
	Qly_phieumuon::qlyphieumuon->sach_het();
}
void Qly_thuvien::indanhsachdocgiadamuon()
{
	for(int i=0; i< Qly_docgia::qlydocgia->sl;i++)
		if( Qly_docgia::qlydocgia->Qly[i]->tinhtrang== etinhtrang::damuon) cout<<"cac doc gia da muon sach la: "<< Qly_docgia::qlydocgia->Qly[i]->_ma<<"\t";
}
void Qly_thuvien::tracuudocgia()
{
	int m;
	cout<<"nhap ma doc gia muon tra cuu: "<<endl;
	cin>>m;
	for(int i=0; i< Qly_docgia::qlydocgia->sl;i++)
	{
		if(m== Qly_docgia::qlydocgia->Qly[i]->_ma)
		{
			cout<<" thong tin doc gia can tim la: "<<endl;
			cout<<"ten: "<<Qly_docgia::qlydocgia->Qly[i]->ten<<" tuoi: "<< Qly_docgia::qlydocgia->Qly[i]->tuoi<<endl;
		}
	}
	for( int j=0; j< Qly_phieumuon::qlyphieumuon->sl; j++)
		if(m== Qly_phieumuon::qlyphieumuon->phieu[j]->ma_dg)
		{
			cout<<"ma cac sach da muon la: "<<endl;
			for(int k=0; k< Qly_phieumuon::qlyphieumuon->phieu[j]->sl_sach; k++)
				cout<<Qly_phieumuon::qlyphieumuon->phieu[j]->a[k]<<"\t";
		}
		else cout<<"chua muon sach nao!"<<endl;
}
void Qly_thuvien::tracuusach()
{
	int m;
	cout<<"nhap ma sach muon tra cuu: "<<endl;
	cin>>m;
	for(int i=0; i< Qly_sach::qlysach->sl;i++)
		if(m== Qly_sach::qlysach->qly[i]->_ma) 
		{
			cout<<"ten tac gia: "<< Qly_sach::qlysach->qly[i]->tacgia<<" the loai: "<<Qly_sach::qlysach->qly[i]->loai<<" tinh trang: "<<Qly_sach::qlysach->qly[i]->tinhtrang<<endl;
		}
		cout<<"ma doc gia muon sach la: "<<endl;
		for(int j=0; j<Qly_phieumuon::qlyphieumuon->sl;j++)
			for(int k=0; k< Qly_phieumuon::qlyphieumuon->phieu[j]->sl_sach;k++)
				if( m== Qly_phieumuon::qlyphieumuon->phieu[j]->a[k])
					cout<<Qly_phieumuon::qlyphieumuon->phieu[j]->ma_dg<<endl;
				else cout<<"chua co doc gia nao muon sach!"<<endl;
}


