#include<iostream>
#include<conio.h>
 
#include "Qly_thuvien.h"
 
using namespace std;
 
 
int main()
{
        Qly_ThuVien quanLy;
        while (1)
        {
                system("cls");         
                int tuyChon;
 
                cout<<"1. Nhap sach moi!"<<endl;
                cout<<"2. Nhap doc gia moi!"<<endl;
                cout<<"3. Muon sach"<<endl;
                cout<<"4. In danh sach sach!"<<endl;
                cout<<"5. In danh sach doc gia!"<<endl;
                cout<<"6. Danh sach sach con!"<<endl;
                cout<<"7. Danh sach sach da cho muon!"<<endl;
                cout<<"8. Danh sach doc gia da muon!"<<endl;
                cout<<"9. Tra cuu doc gia!"<<endl;
                cout<<"10.Tra cuu sach!"<<endl;
                cout<<"11.Thoat chuong trinh!"<<endl;
               
                cin>>tuyChon;
                cin.ignore();
 
                switch (tuyChon)
                {
                case 1:
						quanLy.themSach();
                        break;
                case 2:
						quanLy.themDocGia();
                        break;
                case 3:
                        quanLy.MuonSach();
                        break;
                case 4:
                        quanLy.InDSSach();
                        break;
                case 5:
						quanLy.InDSDocGia();
                        break;
                case 6:
                        quanLy.InDSSachCon();
                        break;
                case 7:
                        quanLy.InDSSachDaMuon();
                        break;
                case 8:
                        quanLy.InDanhSachDocGiaMuonSach();
                        break;
                case 9:
                        quanLy.TraCuuDocGia();
                        break;
                case 10:
                        quanLy.TraCuuSach();
                        break;
                case 11:
                        cout<<"Nhan phim bat ki de thoat chuong trinh...."<<endl;
                        _getch();
                        return 0;
                }
 
                cout<<"Nhan phim bat ki de tiep tuc...."<<endl;
                _getch();
        }
        return 0;
}