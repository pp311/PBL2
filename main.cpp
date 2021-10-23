using namespace std;
#include "khachhang.h"
#include "maytinh.h"
#include "hoadon.h"
#include "thongtinhoadon.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
vector<MayTinh> mayTinh;
vector<HoaDon> hoaDon;
vector<KhachHang> khachHang;
void tiepTuc() {
    system("pause");
    system("cls");
}
void LietKeThongTin() {
    while (true) {
        system("cls");
        int key = 0;
        cout << "CHUONG TRINH QUAN LY CUA HANG BAN MAY TINH \n";
        cout << "*********LIET KE THONG TIN***********\n";
        cout << "* 1. Liet ke may tinh               *\n";
        cout << "* 2. Liet ke hoa don                *\n";
        cout << "* 3. Liet ke khach hang             *\n";
        cout << "* 4. Liet ke kho                    *\n";
        cout << "* 5. Quay lai                       *\n";
        cout << "*************************************\n";
        nhapLai:
        cout << "\nNhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            MayTinh::ShowMayTinh(mayTinh);
            tiepTuc();
            break;
        case 2:
            system("cls");
            //HoaDon::ShowHoaDon(hoaDon);
            tiepTuc();
            break;
        case 3:
            system("cls");
            KhachHang::ShowKhachHang(khachHang);
            tiepTuc();
            break;
        case 4:
            system("cls");
            MayTinh::ShowKho(mayTinh);
            tiepTuc();
            break;
        case 5:
            return;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nXin vui long chon lai!";
            goto nhapLai;
        }
    }
}
void ThemThongTin() {
    while (true) {
        system("cls");
        int key;
        cout << "CHUONG TRINH QUAN LY CUA HANG BAN MAY TINH \n";
        cout << "*********THEM THONG TIN***********\n";
        cout << "* 1. Them thong tin may tinh     *\n";
        cout << "* 2. Them thong tin khach hang   *\n";
        cout << "* 3. Them thong tin kho          *\n";
        cout << "* 4. Quay lai                    *\n";
        cout << "**********************************\n";
        nhapLai:
        cout << "\nNhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            MayTinh::AddMayTinh(mayTinh);
            tiepTuc();
            break;
        case 2:
            system("cls");
            KhachHang::AddKhachHang(khachHang);
            tiepTuc();
            break;
        case 3:
            system("cls");
            MayTinh::AddKho(mayTinh);
            tiepTuc();
            break;
        case 4:
            return;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nXin vui long chon lai!";
            goto nhapLai;
        }
    }
}
void ChinhSuaThongTin() {
start:
    while (true) {
        system("cls");
        int key;
        cout << "CHUONG TRINH QUAN LY CUA HANG BAN MAY TINH \n";
        cout << "*********CHINH SUA THONG TIN***********\n";
        cout << "* 1. Chinh sua thong tin may tinh     *\n";
        cout << "* 2. Chinh sua thong tin hoa don      *\n";
        cout << "* 3. Chinh sua thong tin khach hang   *\n";
        cout << "* 4. Quay lai                         *\n";
        cout << "***************************************\n";
    nhapLai:
        cout << "\nNhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            MayTinh::EditMayTinh(mayTinh);
            tiepTuc();
            goto start;
            break;
        case 2:
            //HoaDon::ChinhSuaThongTinHoaDon(hoaDon);
            break;
        case 3:
            KhachHang::EditKhachHang(khachHang);
            break;
        case 4:
            return;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nXin vui long chon lai!";
            goto nhapLai;
        }
    }
}
void XoaThongTin() {
    while (true) {
        system("cls");
        int key;
        cout << "CHUONG TRINH QUAN LY CUA HANG BAN MAY TINH \n";
        cout << "*********XOA THONG TIN***********\n";
        cout << "* 1. Xoa thong tin may tinh     *\n";
        cout << "* 2. Xoa thong tin hoa don      *\n";
        cout << "* 3. Xoa thong tin khach hang   *\n";
        cout << "* 4. Quay lai                   *\n";
        cout << "*********************************\n";
    nhapLai:
        cout << "\nNhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            MayTinh::DeleteMayTinh(mayTinh);
            tiepTuc();
            break;
        case 2:
            //HoaDon::XoaThongTinHoaDon(hoaDon);
            break;
        case 3:
            KhachHang::DeleteKhachHang(khachHang);
            break;
        case 4:
            return;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nXin vui long chon lai!";
            goto nhapLai;
        }
    }
}


void menu() {
    int key = 0;
    while (true) {
        system("cls");
        cout << "CHUONG TRINH QUAN LY CUA HANG BAN MAY TINH \n";
        cout << "***************MENU*****************\n";
        cout << "* 1. Liet ke                       *\n";
        cout << "* 2. Them thong tin                *\n";
        cout << "* 3. Chinh sua thong tin           *\n";
        cout << "* 4. Xoa thong tin                 *\n";
        cout << "* 5. Lap hoa don                   *\n";
        cout << "* 6. Thoat                         *\n";
        cout << "************************************\n";
        label:
        cout << "\nNhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            //cout << "\n1. Liet ke";
            LietKeThongTin();
            break;
        case 2:
            //cout << "\n2. Them thong tin ";
            ThemThongTin();
            break;
        case 3:
            //cout << "\n3. Chinh sua thong tin";
            ChinhSuaThongTin();
            break;
        case 4:
            //cout << "\n4. Xoa thong tin";
            XoaThongTin();
            break;
        case 5:
            //cout << "\n5. Lap hoa don";
            break;
        case 6:
           // cout << "\n6. Thoat";
            return;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            tiepTuc();
        }
    }
}
int main() {
    MayTinh::ReadMayTinh(mayTinh);
    menu();
    return 0;
}
