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
    }
    void HoaDon::CreateHoaDon(vector<HoaDon>& hoaDon)
    {
        system("cls");
		hoaDon.resize(count + 10);
		hoaDon[count].Nhap();
        hoaDon[count].WriteToFileHoaDon("hoadon.txt");
        count++;
    }
    void HoaDon::DeleteHoaDon(vector<HoaDon>& hoaDon) {
        string maHoaDon;
        cout << "Nhap ma hoa don can xoa: ";
        cin >> maHoaDon;
        for (int i = 0; i < count; i++) {
            if (hoaDon[i].maHoaDon != maHoaDon) {
                hoaDon[i].WriteToFileHoaDon("hoadontam.txt");
            }
            else {
                hoaDon.erase(hoaDon.begin() + i, hoaDon.begin() + i + 1);
            }
        }
        count--;
        remove("hoadon.txt");
        rename("hoadontam.txt", "hoadon.txt");
    }
    void HoaDon::EditHoaDon(vector<HoaDon>& hoaDon) {
        HoaDon input;
        cout << "Nhap thong tin hoa don can chinh sua: ";
        input.Nhap();
        for (int i = 0; i < count; i++) {
            if (hoaDon[i].maHoaDon != input.maHoaDon) {
                hoaDon[i].WriteToFileHoaDon("hoadontam.txt");
            }
            else {
                hoaDon[i] = input;
                input.WriteToFileHoaDon("khachhangtam.txt");
            }
        }
        remove("hoadon.txt");
        rename("hoadontam.txt", "hoadon.txt");
    }
    void HoaDon::WriteToFileHoaDon(string tenFile) {
		fstream file(tenFile, ios::app);
		file << this->maHoaDon << "\t" << this->maKhachHang << "\t" << this->ngayBan << "\t" << this->tongTien << "\n";
		file.close();
    }
    void HoaDon::ReadHoaDon(vector<HoaDon>& hoaDon)
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



