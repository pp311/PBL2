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
        NhapLaiNgayBan:
        cout << "\n\tNhap ngay ban: ";
        cin >> this->ngayBan;
        if (check(this->ngayBan) == -1) {
            cout<<"Ngay ban khong hop le. Vui long nhap lai!";
            goto NhapLaiNgayBan;
        }
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
            cout << "\n\t" <<setw(15)<< this->maMay[i] << setw(15) << this->soLuong[i]<< setw(20) << MoneyFormat(this->donGia[i]);
        }
        cout << "\n\n\t" << "TONG CONG: " << MoneyFormat(this->tongTien)<<"\n\n\t";
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
            cout << setw(20) << MoneyFormat(hoaDon[i].tongTien)<<endl;
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
    void HoaDon::ThongKeHoaDon(vector<HoaDon>& hoaDon) {
        string d1, d2; int tongDoanhThu = 0;
        NhapLaiNgay:
        cout << "\n\n\tNhap ngay bat dau : "; cin >> d1;
        cout << "\n\tNhap ngay ket thuc: "; cin >> d2;
        if (sosanh(d2, d1) == 0 || check(d1) == -1 || check(d2) == -1) {
            cout << "\n\tNgay khong hop le. Vui long nhap lai!";
            goto NhapLaiNgay;
        }
        else {
            cout << endl << "\t";
            cout << left << setw(15) << "Ma Hoa Don" << setw(25) << "Ma Khach Hang" << setw(25) << "Ngay Ban" << setw(20) << "Tong tien" << endl;
            char prev = cout.fill('-');
            cout.width(80);
            cout << "\t-";
            cout.fill(prev);
            cout << endl;
            for (int i = 0; i < count; i++) {
                if (sosanh(d2, hoaDon[i].ngayBan) == 1 && sosanh(hoaDon[i].ngayBan, d1) == 1) {
                    cout << "\t";
                    cout << setw(15) << hoaDon[i].maHoaDon;
                    cout << setw(25) << hoaDon[i].maKhachHang;
                    cout << setw(25) << hoaDon[i].ngayBan;
                    hoaDon[i].TinhTien();
                    cout << setw(20) << MoneyFormat(hoaDon[i].tongTien) << endl;
                    tongDoanhThu += hoaDon[i].tongTien;
                }
            }
            cout << "\n" << "\tTong doanh thu tu ngay " << d1 << " den ngay " << d2 << " la :" << MoneyFormat(tongDoanhThu);
            cout << "\n\n\t";
            system("pause");
        }
    }
    void HoaDon::Show1HoaDon(vector<HoaDon>& hoaDon) {
        cout << endl<<"\t";
        cout << left << setw(15) << "Ma Hoa Don" << setw(25) << "Ma Khach Hang" << setw(25) << "Ngay Ban" << setw(20) << "Tong tien"<<endl;
        char prev = cout.fill('-');
        cout.width(80);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        cout << "\t";
        cout << setw(15) << this->maHoaDon;
        cout << setw(25) << this->maKhachHang;
        cout << setw(25) << this->ngayBan;
        this->TinhTien();
        cout << setw(20) << MoneyFormat(this->tongTien) << endl;
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
            hoaDon[pos].Show1HoaDon(hoaDon);
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
            hoaDon[pos].Show1HoaDon(hoaDon);
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
    void HoaDon::tach(string d, int a[3]) {
        string day = d.substr(0, 2);
        string month = d.substr(3, 2);
        string year = d.substr(6, 4);
        a[2] = stoi(day);
        a[1] = stoi(month);
        a[0] = stoi(year);
    }
    int HoaDon::check(string d) {
        int ngaymax;
        int a[3];
        tach(d, a);
        if (a[0] < 0 || a[1] < 0 || a[1]> 12 || a[2] < 0 || a[2]> 31)
            return -1;
        else {
            switch (a[1]) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                ngaymax = 31;
                break;
            case 2:
                if ((a[0] % 4 == 0 && a[0] % 100 != 0) || (a[0] % 400 == 0))
                    ngaymax = 29;
                else
                    ngaymax = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                ngaymax = 30;
                break;
            }
            if (a[2] <= ngaymax) return 1;
            else return -1;
        }
    }
    int HoaDon::sosanh(string d1, string d2) {
        int i;
        int a[3], b[3];
        tach(d1, a);
        tach(d2, b);
        if (a[0] > b[0]) return 1;
        if (a[0] = b[0]) {
            if (a[1] > b[1]) return 1;
            if (a[1] = b[1]) {
                if (a[2] >= b[2]) return 1;
                else return 0;
            }
            else return 0;
        }
        return 0;
    }
    string HoaDon::MoneyFormat(int donGia) {
        string s = to_string(donGia);
        int n = s.length() - 3;
        while (n > 0) {
            s.insert(n, ",");
            n -= 3;
        }
        s += " VND";
        return s;
    }