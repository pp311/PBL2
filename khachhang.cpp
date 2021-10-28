#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include "khachhang.h"
using namespace std;

int KhachHang::count = 0; //so KhachHang

    void KhachHang::Nhap() {
            cout<<"\nNhap ma khach hang: "; cin>>this->maKhachHang;
            cout<<"\nNhap ten khach hang: "; cin.ignore(); getline(cin, this->tenKhachHang);
            cout<<"\nNhap nam sinh: "; cin>>this->namSinh;
            cout<<"\nNhap gioi tinh: "; cin>>this->gioiTinh;      
            cout<<"\nNhap so dien Thoai: "; cin>>this->dienThoai;
            cout<<"\nNhap dia chi: "; cin.ignore(); getline(cin, this->diaChi);
    }
    int KhachHang::CheckTonTai(vector<KhachHang>& khachHang, string maKhachHang) {
        for (int i = 0; i < count; i++) {
            if (khachHang[i].maKhachHang == maKhachHang) {
                return i;
            }
        }
        return -1;
    }
    //CreateKhachHang
    void KhachHang::AddKhachHang(vector<KhachHang>& khachHang) {
    NhapLai:
        khachHang.resize(count + 10);
        khachHang[count].Nhap();
        khachHang[count].WriteToFileKhachHang("khachhang.txt");
        count++;
        int chon;
        cout << "Them thanh cong!";
        cout << "\nBan co muon tiep tuc them?";
        cout << "\n 1. Co" << "\n 2. Khong" << endl;
        cin >> chon;
        if (chon == 1) goto NhapLai;
    }
    //ShowKhachHang
    void KhachHang::ShowKhachHang(vector<KhachHang>& khachHang) {
        cout << "\n\n\n\t";
        cout <<left << setw(15) << "Ma Khach Hang" << setw(20) << "Ten Khach Hang" << setw(15) << "Nam Sinh" 
            << setw(15) << "Gioi Tinh" << setw(15) << "So Dien Thoai" << setw(30) << "Dia Chi"<<endl;
        for (int i = 0; i < count; i++) {
            cout << "\t";
            cout << setw(15) << khachHang[i].maKhachHang;
           cout << setw(20) << khachHang[i].tenKhachHang;
            cout << setw(15) << khachHang[i].namSinh;
            cout << setw(15) << khachHang[i].gioiTinh;
           cout << setw(15) << khachHang[i].dienThoai;
            cout << setw(30) << khachHang[i].diaChi <<endl;
        }
        cout << "\n\n\n\t";
    }
    void KhachHang::Show1KhachHang(vector<KhachHang>& khachHang, string maKhachHang) {

        cout << "\n\n\n\t";
        cout << left << setw(15) << "Ma Khach Hang" << setw(20) << "Ten Khach Hang" << setw(10) << "Nam Sinh" << setw(10) << "GioiTinh" << setw(15) << "So Dien Thoai" << setw(30) << "Dia Chi" << endl;
        for (int i = 0; i < count; i++) {
            if (khachHang[i].maKhachHang == maKhachHang) {
                cout << "\t";
                cout << setw(15) << khachHang[i].maKhachHang;
                cout << setw(20) << khachHang[i].tenKhachHang;
                cout << setw(10) << khachHang[i].namSinh;
                cout << setw(10) << khachHang[i].gioiTinh;
                cout << setw(15) << khachHang[i].dienThoai;
                cout << setw(30) << khachHang[i].diaChi;
            }
        }
    }
    //ReadKhachHang
    void KhachHang::ReadKhachHang(vector<KhachHang>& khachHang)
    {
        fstream file("KhachHang.txt", ios::in);
        int i = 0;
		KhachHang input;
        while (!file.eof())
        {
            string temp;
            if(!getline(file, input.maKhachHang, '\t')) break;
            getline(file, input.tenKhachHang, '\t');
            getline(file, temp, '\t');
            input.namSinh = atoi(temp.c_str());
            getline(file, input.gioiTinh, '\t');
            getline(file, input.dienThoai, '\t');
            getline(file, input.diaChi);
			khachHang.push_back(input);       
            i++;
        }
        count = i;
        file.close();
    }
    //DeleteKhachHang
    void KhachHang::DeleteKhachHang(vector<KhachHang>& khachHang) {
        system("cls");
        string maKhachHang;
        int pos;
    NhapLai:
        cout << "Nhap ma khach hang can xoa: ";
        cin >> maKhachHang;
        pos = CheckTonTai(khachHang, maKhachHang);
        if (pos == -1) {
            cout << "Khach hang nay khong ton tai. Vui long nhap lai!";
            goto NhapLai;
        }
        else {
            Show1KhachHang(khachHang, maKhachHang);
            char c;
            cout << "Xac nhan xoa thong tin khach hang nay khoi he thong? <Y/N>";
            cin >> c;
            if (c == 'N' || c == 'n') goto NhapLai;
            for (int i = 0; i < count; i++) {
                if (khachHang[i].maKhachHang != maKhachHang) {
                    khachHang[i].WriteToFileKhachHang("khachhangtam.txt");
                }
                else {
                    khachHang.erase(khachHang.begin() + i, khachHang.begin() + i + 1);
                }
            }
            count--;
            remove("khachhang.txt");
            rename("khachhangtam.txt", "khachhang.txt");
            cout << "Xoa thanh cong!";
            int chon;
            cout << "\nBan co muon tiep tuc xoa?";
            cout << "\n 1. Co" << "\n 2. Khong" << endl;
            cout << "Lua chon: ";
            cin >> chon;
            if (chon == 1) goto NhapLai;
        }
    }
    void KhachHang::EditKhachHang(vector<KhachHang>& khachHang) {
        string maKhachHang;
        int pos;
    NhapLai1:
        cout << "\nNhap ma khach hang can chinh sua: ";
        cin >> maKhachHang;
        pos = CheckTonTai(khachHang, maKhachHang);
        if (pos == -1) {
            cout << "Khach hang nay khong ton tai. Vui long nhap lai!";
            goto NhapLai1;
        }
        else {
            int luaChon;
            string temp;
            int num;
        NhapLai2:
            system("cls");
            Show1KhachHang(khachHang, maKhachHang);
            cout << "\nChon thong tin can chinh sua:";
            cout << "\n1. Ten khach hang";
            cout << "\n2. Dia chi";
            cout << "\n3. Dien thoai";
            cout << "\n4. Nam sinh";
            cout << "\n5. Gioi tinh";
            cout << "\n-------------";
            cout << "\nNhap lua chon:";
            cin >> luaChon;
            switch (luaChon) {
            case 1:
                cout << "\nNhap ten khach hang:";
                cin >> temp;
                khachHang[pos].tenKhachHang = temp;
                break;
            case 2:
                cout << "\nNhap dia chi:";
                cin >> temp;
                khachHang[pos].diaChi = temp;
                break;
            case 3:
                cout << "\nNhap so dien thoai:";
                cin >> temp;
                khachHang[pos].dienThoai = temp;
                break;
            case 4:
                cout << "\nNhap nam sinh:";
                cin >> num;
                khachHang[pos].namSinh = num;
                break;
            case 5:
                cout << "\nNhap gioi tinh:";
                cin >> temp;
                khachHang[pos].gioiTinh = temp;
                break;
            default:
                cout << "\nSo khong hop le. Vui long nhap lai!";
                goto NhapLai2;
                break;
            }
            int chon;
            cout << "Sua doi thanh cong!";
            cout << "\nBan co muon tiep tuc chinh sua?";
            cout << "\n 1. Co" << "\n 2. Khong" << endl;
            cout << "Lua chon: ";
            cin >> chon;
            if (chon == 1) goto NhapLai2;
            for (int i = 0; i < count; i++) {
                khachHang[i].WriteToFileKhachHang("khachhangtam.txt");
            }
            remove("khachhang.txt");
            rename("khachhangtam.txt", "khachhang.txt");
        }
    }
    void KhachHang::WriteToFileKhachHang(string tenFile) {
        fstream file(tenFile, ios::app);
        file << this->maKhachHang << "\t" << this->tenKhachHang << "\t" <<  this->namSinh << "\t" << this->gioiTinh <<"\t" 
            << this->dienThoai << "\t" << this->diaChi << "\n";
        file.close();
    }
    void KhachHang::setMaKhachHang(string mkh)
    {
    	maKhachHang=mkh;
	}
	void KhachHang::setTenKhachHang(string tkh)
    {
    	tenKhachHang=tkh;
	}
	void KhachHang::setDiaChi(string dc)
    {
    	diaChi=dc;
	}
	void KhachHang::setDienThoai(string dt)
    {
    	dienThoai=dt;
	}
	void KhachHang::setNamSinh(int ns)
    {
    	namSinh=ns;
	}
	void KhachHang::setGioiTinh(string gt)
    {
    	gioiTinh=gt;
	}
    string KhachHang::getMaKhachHang(){
    return maKhachHang;
    }
    string KhachHang::getTenKhachHang(){
    return tenKhachHang;
    }
    string KhachHang::getDiaChi(){
    return diaChi;
    }
    string KhachHang::getDienThoai(){
    return dienThoai;
    }
    int KhachHang::getNamSinh(){
    return namSinh;
    }    
    string KhachHang::getGioiTinh(){
    return gioiTinh;
    }



