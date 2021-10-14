#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "hoadon.h" 
using namespace std;

int HoaDon::count = 0; //so HoaDon
    void HoaDon::Nhap()
    {
        cout << "\nNhap ma hoa don: ";
        cin >> this->maHoaDon;
        cout << "\nNhap ma khach hang: ";
        cin >> this->maKhachHang;
        cout << "\nNhap ngay ban : ";
        cin >> this->ngayBan;
        cout << "\nNhap tongTien : ";
        cin >> this->tongTien;
		fstream file("HoaDon.txt", ios::app);
		file << this->maHoaDon << "\t" << this->maKhachHang << "\t" << this->ngayBan << "\t" << this->tongTien << "\n";
		file.close();
    }
    void HoaDon::CreateHoaDon(vector<HoaDon> hoaDon)
    {
        system("cls");
        if(hoaDon.size() == hoaDon.capacity()) {
			hoaDon.reserve (hoaDon.size() + 10);
		}
		hoaDon[count++].Nhap();
    }
    void HoaDon::setMaHoaDon(string mhd ){
    	maHoaDon=mhd;
	}
    void HoaDon::setMaKhachHang(string mkh){
    	maKhachHang=mkh;
	}
    void HoaDon::setNgayBan(string nb){
    	ngayBan=nb;
	}
    void HoaDon::setTongTien(int tt) {
    	tongTien=tt;
	}
    string HoaDon::getMaHoaDon(){
		return maHoaDon;
    }
    string HoaDon::getMaKhachHang(){
		return maKhachHang;
    }
    string HoaDon::getNgayBan(){
		return ngayBan;
    }
	int HoaDon::getTongTien(){
		return tongTien;
    }       
    void HoaDon::ReadHoaDon(vector<HoaDon> hoaDon)
    {
        system("cls");
        fstream file("hoaDon.txt", ios::in);
        int i = 0;
		HoaDon input;
        while (!file.eof())
        {
            string temp;
            if(!getline(file, input.maHoaDon, '\t')) break;
            getline(file, input.maKhachHang, '\t');
            getline(file, input.ngayBan, '\t');
            getline(file, temp);
            input.tongTien = atoi(temp.c_str());
			hoaDon.push_back(input);
            cout << "hoa don "<<i+1<<":" << input.maHoaDon << " " << input.maKhachHang << " " << input.ngayBan << " " << input.tongTien << endl;
            i++;
        }
        count = i;
        file.close();
    }




