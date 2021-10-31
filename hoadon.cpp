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
        cout << "\n\n\t\t\t\t\t===== LAP HOA DON =====\n\n\t";
        NhapLaiMaHoaDon:
        cout << "\n\tNhap ma hoa don: ";
        cin >> this->maHoaDon;
        for (int i = 0; i < count; i++) {
            if (this->maHoaDon == hoaDon[i].maHoaDon) {
                cout << "\n\tMa hoa don nay da ton tai, vui long nhap lai!";
                goto NhapLaiMaHoaDon;
            }
        }
        NhapLaiMaKhachHang:
        cout << "\n\tNhap ma khach hang: ";
        cin >> this->maKhachHang;
        bool tonTai = false;
        for (int i = 0; i < KhachHang::count; i++) {
            if (this->maKhachHang == khachHang[i].maKhachHang) tonTai = true;
        }
        if (tonTai == false) {
            char ch;
            cout << "\n\tKhach hang nay khong ton tai trong he thong, ban co muon tao ho so moi? <Y/N>";
            cin >> ch;
            if (ch == 'Y' || ch == 'y') 
                KhachHang::AddKhachHang(khachHang, this->maKhachHang);
            else goto NhapLaiMaKhachHang;
        }
        cout << "\n\tNhap ngay ban: ";
        cin >> this->ngayBan;
        this->soSanPham = 0;
        //this->tongTien = 0;
        while (true) {
            NhapLaiMaMay:
            cout << "\n\tNhap ma san pham: ";
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
                cout << "\n\tMa may nay khong ton tai, vui long nhap lai!\n\t";
                system("pause");
                goto NhapLaiMaMay;
            }
            NhapLaiSoLuong:
            cout << "\n\tNhap so luong mua: ";
            cin >> this->soLuong[this->soSanPham];
                if (mayTinh[i].soLuong < this->soLuong[this->soSanPham]) {
                    int luaChon;
                    cout << "\n\tSo luong may tinh tron kho khong du!\n\tSo luong con hien tai: " << mayTinh[i].soLuong;
                    cout << "\n\t1. Nhap lai so luong\n\t2.Chon may khac";
                    cout << "\n\t-------\n\tLua chon: ";
                NhapLaiLuaChon:
                    cin >> luaChon;
                    if (luaChon == 1) goto NhapLaiSoLuong;
                    else if (luaChon == 2) goto NhapLaiMaMay;
                    else {
                        cout << "\n\tKhong hop le! Vui long nhap lai lua chon: ";
                        goto NhapLaiLuaChon;
                    }
                }

                mayTinh[i].soLuong -= this->soLuong[this->soSanPham];  //tru vao kho
                for (int i = 0; i < MayTinh::count; i++) {
                    mayTinh[i].WriteToFileMayTinh("maytinhtam.txt");
                }
                remove("maytinh.txt");
                rename("maytinhtam.txt", "maytinh.txt");
            //this->tongTien += this->donGia[this->soSanPham] * this->soLuong[this->soSanPham];
            this->soSanPham++;
            char c;
            cout << "\n\tMua tiep? <Y/N>";
            cin >> c;
            if (c == 'N' || c == 'n')
                break;
        }
        this->TinhTien();
        cout << "\n\tTao hoa don thanh cong!\n\t";
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
        cout << "\n\n\t" << "TONG CONG: " << this->tongTien << " VND"<<"\n\n\t";
    }
    void HoaDon::ShowHoaDon(vector<HoaDon>& hoaDon, vector<KhachHang>& khachHang, vector<MayTinh>& mayTinh) {
        Start:
        system("cls");
        string maHoaDon;
        cout << "\n\n\t\t\t\t\t===== DANH SACH HOA DON =====\n\n\t";
        cout << left << setw(15) << "Ma Hoa Don" << setw(25) << "Ma Khach Hang" << setw(25) << "Ngay Ban" << setw(20) << "Tong tien"<<endl;
        char prev = cout.fill('-');
        cout.width(80);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        for (int i = 0; i < count; i++) {
            cout << "\t";
            cout << setw(15) << hoaDon[i].maHoaDon;
            cout << setw(25) << hoaDon[i].maKhachHang;
            cout << setw(25) << hoaDon[i].ngayBan;
            hoaDon[i].TinhTien();
            cout << setw(20) << hoaDon[i].tongTien<<endl;
        }
        cout << "\n\n\tNhap ma hoa don de xem chi tiet: ";
        cin >> maHoaDon;
        int pos = CheckTonTai(hoaDon, maHoaDon);
        if (pos == -1) {
            cout << "\n\tMa hoa don nay khong ton tai.";
        }
        for (int i = 0; i < count; i++) {
            if (maHoaDon == hoaDon[i].maHoaDon) hoaDon[i].ShowChiTietHoaDon(hoaDon, khachHang, mayTinh);
        }
        char ch;
        cout << "\n\n\tTiep tuc xem? <Y/N>";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') goto Start; 
    }
    void HoaDon::Show1HoaDon(vector<HoaDon>& hoaDon, string maHoaDon) {
        cout << endl<<"\t";
        cout << left << setw(15) << "Ma Hoa Don" << setw(25) << "Ma Khach Hang" << setw(25) << "Ngay Ban" << setw(20) << "Tong tien"<<endl;
        char prev = cout.fill('-');
        cout.width(80);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        for (int i = 0; i < count; i++) {
            if (hoaDon[i].maHoaDon == maHoaDon) {
                cout << "\t";
                cout << setw(15) << hoaDon[i].maHoaDon;
                cout << setw(25) << hoaDon[i].maKhachHang;
                cout << setw(25) << hoaDon[i].ngayBan;
                hoaDon[i].TinhTien();
                cout << setw(20) << hoaDon[i].tongTien << endl;
            }
        }
        cout << "\n\n\t";
    }
    void HoaDon::TinhTien() {
        this->tongTien = 0;
        for (int i = 0; i < this->soSanPham; i++) {
               this->tongTien += this->donGia[i] * this->soLuong[i];    
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
    int HoaDon::CheckTonTai(vector<HoaDon>& hoaDon, string maHoaDon) {
        for (int i = 0; i < count; i++) {
            if (hoaDon[i].maHoaDon == maHoaDon) {
                return i;
            }
        }
        return -1;
    }
    void HoaDon::DeleteHoaDon(vector<HoaDon>& hoaDon) {
        string maHoaDon;
        int pos;
    NhapLai:
        system("cls");
        cout << "\n\n\t\t\t\t\t===== XOA THONG TIN HOA DON =====\n\n\t";
        cout << "\n\tNhap ma hoa don can xoa: ";
        cin >> maHoaDon;
        pos = CheckTonTai(hoaDon, maHoaDon);
        if (pos == -1) {
            cout << "\n\tMa hoa don nay khong ton tai. Vui long nhap lai!\n\t";
            system("pause");
            goto NhapLai;
        }
        else {
            Show1HoaDon(hoaDon, maHoaDon);
            char c;
            cout << "\n\tXac nhan xoa thong tin hoa don nay khoi he thong? <Y/N>";
            cin >> c;
            if (c == 'N' || c == 'n') return;
        }
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
        cout << "\n\tXoa thanh cong!";
        int chon;
        cout << "\n\tBan co muon tiep tuc xoa?";
        cout << "\n\t 1. Co" << "\n 2. Khong" << endl;
        cout << "\n\tLua chon: ";
        cin >> chon;
        if (chon == 1) goto NhapLai;
    }
    void HoaDon::EditHoaDon(vector<HoaDon>& hoaDon) {
        HoaDon input;
        string maHoaDon;
        int pos;
    NhapLai1:
        system("cls");
        cout << "\n\n\t\t\t\t\t===== CHINH SUA THONG TIN HOA DON =====\n\n\t";
        cout << "\n\tNhap ma hoa don can chinh sua: ";
        cin >> maHoaDon;
        pos = CheckTonTai(hoaDon, maHoaDon);
        if (pos == -1) {
            cout << "\n\tMa hoa don nay khong ton tai. Vui long nhap lai!\n\t";
            system("pause");
            goto NhapLai1;
        }
        else {
            int luaChon;
            string temp;
        NhapLai2:
            system("cls");
            cout << "\n\n\t\t\t\t\t===== CHINH SUA THONG TIN HOA DON =====\n\n\t";
            Show1HoaDon(hoaDon, maHoaDon);
            cout << "\n\tChon thong tin can chinh sua:";
            cout << "\n\t1. Ma khach hang";
            cout << "\n\t2. Ngay ban";
            cout << "\n\t-------------";
            cout << "\n\tNhap lua chon: ";
            cin >> luaChon;
            switch (luaChon) {
            case 1:
                cout << "\n\tNhap ma khach hang:";
                cin >> temp;
                hoaDon[pos].maKhachHang = temp;
                break;
            case 2:
                cout << "\n\tNhap dia chi:";
                cin >> temp;
                hoaDon[pos].ngayBan = temp;
                break;
            default:
                cout << "\n\tSo khong hop le. Vui long nhap lai!\n\t";
                system("pause");
                goto NhapLai2;
                break;
            }
            for (int i = 0; i < count; i++) {
                hoaDon[i].WriteToFileHoaDon("hoadontam.txt");
            }
            remove("hoadon.txt");
            rename("hoadontam.txt", "hoadon.txt");
            int chon;
            cout << "\n\tSua doi thanh cong!";
            cout << "\n\tBan co muon tiep tuc chinh sua?";
            cout << "\n\t 1. Tiep tuc chinh sua thong tin hoa don hien tai" << "\n\t 2. Chinh sua thong tin cua hoa don khac" << "\n\t 3. Thoat" << endl;
            cout << "\tLua chon: ";
            cin >> chon;
            if (chon == 1) goto NhapLai2;
            else if (chon == 2) goto NhapLai1;
        }
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



