#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "khachhang.h"
using namespace std;

int KhachHang::count = 0; //so KhachHang

    void KhachHang::Nhap() {
            cout<<"\nNhap ma khach hang: "; cin>>this->maKhachHang;
            cout<<"\nNhap ten khach hang: "; cin.ignore(); getline(cin, this->tenKhachHang);
            cout<<"\nNhap dia chi: "; cin.ignore(); getline(cin, this->diaChi);
            cout<<"\nNhap so dien Thoai: "; cin>>this->dienThoai;
            cout<<"\nNhap ngay sinh : "; cin>>this->ngaySinh;
            cout<<"\nNhap gioi tinh : "; cin>>this->gioiTinh;
			fstream file("KhachHang.txt", ios::app);
            file<<this->maKhachHang<<"\t"<<this->tenKhachHang<<"\t"<<this->diaChi<<"\t"<<this->dienThoai<<"\t"<<this->ngaySinh<<"\t"<<this->gioiTinh<<"\n";
            file.close();        
            }
    void KhachHang::CreateKhachHang(vector<KhachHang> khachHang) {
            system("cls");
			khachHang.resize(count+10);
			khachHang[count++].Nhap();
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
	void KhachHang::setNgaySinh(string ns)
    {
    	ngaySinh=ns;
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
    string KhachHang::getNgaySinh(){
    return ngaySinh;
    }    
    string KhachHang::getGioiTinh(){
    return gioiTinh;
    }
    void KhachHang::ReadKhachHang(vector<KhachHang> khachHang)
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
            getline(file, input.diaChi, '\t');
            getline(file, input.dienThoai, '\t');
            getline(file, input.ngaySinh, '\t');
            getline(file, input.gioiTinh);
			khachHang.push_back(input);
            cout << "Thong tin khach hang " <<i+1<<":" << input.maKhachHang<< input.tenKhachHang << input.diaChi << input.dienThoai << input.ngaySinh << input.gioiTinh  << endl;
            i++;
        }
        count = i;
        file.close();
    }




