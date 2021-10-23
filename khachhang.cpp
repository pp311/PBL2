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
            cout<<"\nNhap nam sinh : "; cin>>this->namSinh;
            cout<<"\nNhap gioi tinh : "; cin>>this->gioiTinh;      
            cout<<"\nNhap so dien Thoai: "; cin>>this->dienThoai;
            cout<<"\nNhap dia chi: "; cin.ignore(); getline(cin, this->diaChi);
            }
    //CreateKhachHang
    void KhachHang::AddKhachHang(vector<KhachHang>& khachHang) {
            system("cls");
			khachHang.resize(count+10);
			khachHang[count].Nhap();
            khachHang[count].WriteToFileKhachHang("khachhang.txt");
            count++;
    }
    //ShowKhachHang
    void KhachHang::ShowKhachHang(vector<KhachHang>& khachHang) {
        cout << left << setw(15) << "Ma Khach Hang" << setw(20) << "Ten Khach Hang" << setw(10) << "Nam Sinh" 
            << setw(10) << "Gioi Tinh" << setw(15) << "So Dien Thoai" << setw(30) << "Dia Chi\n";
        for (int i = 0; i < count; i++) {
            cout << setw(15) << khachHang[i].maKhachHang;
            cout << setw(20) << khachHang[i].tenKhachHang;
            cout << setw(10) << khachHang[i].namSinh;
            cout << setw(10) << khachHang[i].gioiTinh;
            cout << setw(15) << khachHang[i].dienThoai;
            cout << setw(30) << khachHang[i].diaChi;
        }
    }
    //ReadKhachHang
    void KhachHang::ReadKhachHang(vector<KhachHang>& khachHang)
    {
        system("cls");
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
            //cout << "Thong tin khach hang " <<i+1<<":" << input.maKhachHang<< input.tenKhachHang << input.diaChi << input.dienThoai << input.ngaySinh << input.gioiTinh  << endl;
            i++;
        }
        count = i;
        file.close();
    }
    //DeleteKhachHang
    void KhachHang::DeleteKhachHang(vector<KhachHang>& khachHang) {
        string maKhachHang;
        cout << "Nhap ma khach hang can xoa: ";
        cin >> maKhachHang;
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
    }
    void KhachHang::EditKhachHang(vector<KhachHang>& khachHang) {
        KhachHang input;
        cout << "Nhap thong tin may tinh can chinh sua: ";
        input.Nhap();
        for (int i = 0; i < count; i++) {
            if (khachHang[i].maKhachHang != input.maKhachHang) {
                khachHang[i].WriteToFileKhachHang("maytinhtam.txt");
            }
            else {
                khachHang[i] = input;
                input.WriteToFileKhachHang("khachhangtam.txt");
            }
        }
        remove("khachhang.txt");
        rename("khachhangtam.txt", "khachhang.txt");
    }
    void KhachHang::WriteToFileKhachHang(string tenFile) {
        fstream file(tenFile, ios::app);
        file << this->maKhachHang << "\t" << this->tenKhachHang << "\t" << this->diaChi << "\t" << this->dienThoai << "\t" << this->namSinh << "\t" << this->gioiTinh << "\n";
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



