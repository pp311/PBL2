#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include "hoadon.h" 
#include "khachhang.h"
#include "maytinh.h"
using namespace std;

int HoaDon::count = 0; //so HoaDon
    void HoaDon::Nhap(vector<HoaDon>& hoaDon, vector<KhachHang>& khachHang, vector<MayTinh>& mayTinh)
    {
        NhapLaiMaHoaDon:
        cout << "\nNhap ma hoa don: ";
        cin >> this->maHoaDon;
        for (int i = 0; i < count; i++) {
            if (this->maHoaDon == hoaDon[i].maHoaDon) {
                cout << "\nMa hoa don nay da ton tai, vui long nhap lai!";
                goto NhapLaiMaHoaDon;
            }
        }
        NhapLaiMaKhachHang:
        cout << "\nNhap ma khach hang: ";
        cin >> this->maKhachHang;
        bool tonTai = false;
        for (int i = 0; i < KhachHang::count; i++) {
            if (this->maKhachHang == khachHang[i].maKhachHang) tonTai = true;
        }
        if (tonTai == false) {
            char ch;
            cout << "\nKhach hang nay khong ton tai trong he thong, ban co muon tao ho so moi? <Y/N>";
            cin >> ch;
            if (ch == 'Y' || ch == 'y') 
                KhachHang::AddKhachHang(khachHang);
            else goto NhapLaiMaKhachHang;
        }
        cout << "\nNhap ngay ban: ";
        cin >> this->ngayBan;
        this->soSanPham = 0;
        while (true) {
            NhapLaiMaMay:
            cout << "\nNhap ma san pham: ";
            cin >> this->maMay[this->soSanPham];
            int i = 0;
            bool tonTai = false;
            for (i ; i < MayTinh::count; i++) {
                if (this->maMay[this->soSanPham] == mayTinh[i].maMay) {
                    this->donGia[this->soSanPham] = mayTinh[i].giaBan;
                    tonTai = true;
                    break;
                }
            }
            if (tonTai == false) {
                cout << "\nMa may nay khong ton tai, vui long nhap lai!";
                goto NhapLaiMaMay;
            }
            NhapLaiSoLuong:
            cout << "\nNhap so luong mua: ";
            cin >> this->soLuong[this->soSanPham];
                if (mayTinh[i].soLuong < this->soLuong[this->soSanPham]) {
                    int luaChon;
                    cout << "\nSo luong may tinh tron kho khong du!\nSo luong con hien tai: " << mayTinh[i].soLuong;
                    cout << "\n1. Nhap lai so luong\n2.Chon may khac";
                    cout << "\n-------\nLua chon: ";
                NhapLaiLuaChon:
                    cin >> luaChon;
                    if (luaChon == 1) goto NhapLaiSoLuong;
                    else if (luaChon == 2) goto NhapLaiMaMay;
                    else {
                        cout << "\nKhong hop le! Vui long nhap lai lua chon: ";
                        goto NhapLaiLuaChon;
                    }
                }

                mayTinh[i].soLuong -= this->soLuong[this->soSanPham];  //tru vao kho
                for (int i = 0; i < MayTinh::count; i++) {
                    mayTinh[i].WriteToFileMayTinh("maytinhtam.txt");
                }
                remove("maytinh.txt");
                rename("maytinhtam.txt", "maytinh.txt");
            this->tongTien += this->donGia[this->soSanPham] * this->soLuong[this->soSanPham];
            this->soSanPham++;
            char c;
            cout << "\nMua tiep? <Y/N>";
            cin >> c;
            if (c == 'N' || c == 'n')
                break;
        }
        this->TinhTien();
        cout << "\nTao hoa don thanh cong!\n";
        system("pause");
    }
    void HoaDon::ShowChiTietHoaDon(vector<HoaDon>& hoaDon, vector<KhachHang>& khachHang, vector<MayTinh>& mayTinh) {
        string tenSP;
        cout << "\n\n";
        cout << "\t\t\tTHONG TIN HOA DON";
        cout << "\n\t\t\t----------------";
        cout << "\n\tMa hoa don: " << this->maHoaDon;
        cout << "\t\tNgay ban: " << this->ngayBan;
        cout << "\n\tMa khach hang: " << this->maKhachHang;
        cout << "\n\tHo va ten khach hang: ";
        for (int i = 0; i < KhachHang::count; i++) {
            if (this->maKhachHang == khachHang[i].maKhachHang)
            {
                cout << khachHang[i].tenKhachHang;
                break;
            }
        }
        cout << "\n\n\t\t---Danh sach san pham---";
        cout << "\n\t"<<setw(15)<<"Ma May"<<setw(15)<<"So Luong"<<setw(20)<<"Thanh Tien";
        for (int i = 0; i < this->soSanPham; i++) {
            cout << "\n\t" <<setw(15)<< this->maMay[i] << setw(15) << this->soLuong[i]<< setw(20) << this->donGia[i];
        }
        cout << "\n\n\t" << "TONG CONG: " << this->tongTien << " VND";
    }
    void HoaDon::ShowHoaDon(vector<HoaDon>& hoaDon, vector<KhachHang>& khachHang, vector<MayTinh>& mayTinh) {
        Start:
        system("cls");
        cout << "\n\n\t";
        string maHoaDon;
        cout << left << setw(15) << "Ma Hoa Don" << setw(15) << "Ma Khach Hang" << setw(15) << "Ngay Ban" << setw(20) << "Tong tien";
        for (int i = 0; i < count; i++) {
            cout << "\n\t";
            cout << setw(15) << hoaDon[i].maHoaDon;
            cout << setw(15) << hoaDon[i].maKhachHang;
            cout << setw(15) << hoaDon[i].ngayBan;
            hoaDon[i].TinhTien();
            cout << setw(20) << hoaDon[i].tongTien;
        }
        cout << "\n\nNhap ma hoa don de xem chi tiet:";
        cin >> maHoaDon;
        for (int i = 0; i < count; i++) {
            if (maHoaDon == hoaDon[i].maHoaDon) hoaDon[i].ShowChiTietHoaDon(hoaDon, khachHang, mayTinh);
        }
        char ch;
        cout << "\n\nTiep tuc xem? <Y/N>";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') goto Start; 
    }
    void HoaDon::TinhTien() {
        this->tongTien = 0;
        for (int i = 0; i < this->soSanPham; i++) {
               this->tongTien += this->donGia[i] * this->soLuong[i];
               break;          
        }
    }
    void HoaDon::AddHoaDon(vector<HoaDon>& hoaDon, vector<KhachHang>& khachHang, vector<MayTinh>& mayTinh)
    {
        system("cls");
		hoaDon.resize(count + 10);
		hoaDon[count].Nhap(hoaDon, khachHang, mayTinh);
        hoaDon[count].WriteToFileHoaDon("hoadon.txt");
        hoaDon[count].ShowChiTietHoaDon(hoaDon, khachHang, mayTinh);
        system("pause");
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
      //  input.Nhap();
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
		file << this->maHoaDon << "\t" << this->maKhachHang << "\t" << this->ngayBan <<"\t"<< this->soSanPham << "\n";
        for (int i = 0; i < this-> soSanPham; i++) {
            file << this->maMay[i] << "\t" << this->soLuong[i]<<"\t"<<this->donGia[i]<<"\n";
        }
 		file.close();
    }
    void HoaDon::ReadHoaDon(vector<HoaDon>& hoaDon)
    {
        system("cls");
        fstream file("hoaDon.txt", ios::in);
        int demSoHoaDon = 0;
		HoaDon input;
        string temp;
        while (!file.eof())
        {
            if(!getline(file, input.maHoaDon, '\t')) break;
            getline(file, input.maKhachHang, '\t');
            getline(file, input.ngayBan, '\t');
            getline(file, temp);
            input.soSanPham = atoi(temp.c_str());
            for (int i = 0; i < input.soSanPham; i++) {
                getline(file, input.maMay[i], '\t');
                getline(file, temp, '\t');
                input.soLuong[i] = atoi(temp.c_str());
                getline(file, temp);
                input.donGia[i] = atoi(temp.c_str());
            }
            input.tongTien = 0;
			hoaDon.push_back(input);
            demSoHoaDon++;
        }
        count = demSoHoaDon;
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



