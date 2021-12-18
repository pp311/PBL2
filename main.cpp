#include "khachhang.h"
#include "maytinh.h"
#include "hoadon.h"
#include "menu.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <Windows.h>
using namespace std;
string t5();
void tiepTuc();
vector<MayTinh> mayTinh;
vector<HoaDon> hoaDon;
vector<KhachHang> khachHang;

int main() {
    MayTinh::ReadMayTinh(mayTinh);
    KhachHang::ReadKhachHang(khachHang);
    HoaDon::ReadHoaDon(hoaDon);
    Menu::MainMenu();
    return 0;
}

void tiepTuc() {
    cout << "\t";
    system("pause");
    system("cls");
}
string t5() {
    return "\t\t\t\t\t";
}
void Menu::LietKeThongTin() {
    while (true) {
        system("cls");
        int key = 0;
        cout << "\n\n";
        cout << t5() << " ======== LIET KE THONG TIN ========\n";
        cout << t5() << "| 1. Liet ke may tinh               |\n";
        cout << t5() << "| 2. Liet ke hoa don                |\n";
        cout << t5() << "| 3. Liet ke khach hang             |\n";
        cout << t5() << "| 4. Liet ke kho                    |\n";
        cout << t5() << "| 5. Quay lai                       |\n";
        cout << t5() << " ===================================\n";
    nhapLai:
        cout << endl << t5() << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            cout << "\n\n\t\t\t\t\t===== DANH SACH MAY TINH =====\n\n\t";
            MayTinh::ShowMayTinh(mayTinh);
            tiepTuc();
            break;
        case 2:
            system("cls");
            
            HoaDon::ShowHoaDon(hoaDon, khachHang, mayTinh);
            tiepTuc();
            break;
        case 3:
            system("cls");
            cout << "\n\n\t\t\t\t\t===== DANH SACH KHACH HANG =====\n\n\t";
            KhachHang::ShowKhachHang(khachHang);
            tiepTuc();
            break;
        case 4:
            system("cls");
            cout << "\n\n\t\t\t\t\t\t===== THONG TIN KHO =====\n\n\t";
            MayTinh::ShowKho(mayTinh);
            tiepTuc();
            break;
        case 5:
            return;
        default:
            cout << "\n\tKhong co chuc nang nay!";
            cout << "\n\tXin vui long chon lai!";
            goto nhapLai;
        }
    }
}
void Menu::ThemThongTin() {
    while (true) {
        system("cls");
        int key;
        cout << "\n\n";
        cout << t5() << " ========= THEM THONG TIN =========\n";
        cout << t5() << "| 1. Them thong tin may tinh       |\n";
        cout << t5() << "| 2. Them thong tin khach hang     |\n";
        cout << t5() << "| 3. Quay lai                      |\n";
        cout << t5() << " ==================================\n";
    nhapLai:
        cout << endl << t5() << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            cout << "\n\n\t\t\t\t\t===== THEM THONG TIN MAY TINH =====\n\n";
            MayTinh::AddMayTinh(mayTinh);
            tiepTuc();
            break;
        case 2:
            system("cls");
            cout << "\n\n\t\t\t\t\t===== THEM THONG TIN KHACH HANG =====\n\n";
            KhachHang::AddKhachHang(khachHang);
            tiepTuc();
            break;
        case 3:
            return;
        default:
            cout << "\n\tKhong co chuc nang nay!";
            cout << "\n\tXin vui long chon lai!";
            goto nhapLai;
        }
    }
}
void Menu::ChinhSuaThongTin() {
start:
    while (true) {
        system("cls");
        int key;
        cout << "\n\n";
        cout << t5() << " ======= CHINH SUA THONG TIN ========\n";
        cout << t5() << "| 1. Chinh sua thong tin may tinh    |\n";
        cout << t5() << "| 2. Chinh sua thong tin hoa don     |\n";
        cout << t5() << "| 3. Chinh sua thong tin khach hang  |\n";
        cout << t5() << "| 4. Quay lai                        |\n";
        cout << t5() << " ====================================\n";
    nhapLai:
        cout << endl << t5() << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            MayTinh::EditMayTinh(mayTinh);
            tiepTuc();
            goto start;
            break;
        case 2:
            HoaDon::EditHoaDon(hoaDon);
            break;
        case 3:
            KhachHang::EditKhachHang(khachHang);
            break;
        case 4:
            return;
        default:
            cout << "\n\tKhong co chuc nang nay!";
            cout << "\n\tXin vui long chon lai!";
            goto nhapLai;
        }
    }
}
void Menu::XoaThongTin() {
    while (true) {
        system("cls");
        int key;
        cout << "\n\n";
        cout << t5() << " ========== XOA THONG TIN =========\n";
        cout << t5() << "| 1. Xoa thong tin may tinh        |\n";
        cout << t5() << "| 2. Xoa thong tin hoa don         |\n";
        cout << t5() << "| 3. Xoa thong tin khach hang      |\n";
        cout << t5() << "| 4. Quay lai                      |\n";
        cout << t5() << " ==================================\n";
    nhapLai:
        cout << endl << t5() << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            system("cls");
            MayTinh::DeleteMayTinh(mayTinh);
            tiepTuc();
            break;
        case 2:
            system("cls");
            HoaDon::DeleteHoaDon(hoaDon);
            tiepTuc();
            break;
        case 3:
            system("cls");
            KhachHang::DeleteKhachHang(khachHang);
            tiepTuc();
            break;
        case 4:
            return;
        default:
            cout << "\n\tKhong co chuc nang nay!";
            cout << "\n\tXin vui long chon lai!";
            goto nhapLai;
        }
    }
}


void Menu::MainMenu() {
    int key = 0;
    while (true) {
        system("cls");
        cout << "\n\n" << t5() << " CHUONG TRINH QUAN LY BAN MAY TINH \n\n\n";
        cout << t5() << " ============== MENU ==============\n";
        cout << t5() << "| 1. Liet ke                       |\n";
        cout << t5() << "| 2. Them thong tin                |\n";
        cout << t5() << "| 3. Chinh sua thong tin           |\n";
        cout << t5() << "| 4. Xoa thong tin                 |\n";
        cout << t5() << "| 5. Nhap hang ve                  |\n";
        cout << t5() << "| 6. Lap hoa don                   |\n";
        cout << t5() << "| 7. Thong ke                      |\n";
        cout << t5() << "| 8. Thoat                         |\n";
        cout << t5() << " ==================================\n";
    label:
        cout << endl << t5() << "Nhap tuy chon : ";
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
            MayTinh::AddKho(mayTinh);
            break;
        case 6:
            //cout << "\n5. Lap hoa don";
            HoaDon::AddHoaDon(hoaDon, khachHang, mayTinh);
            break;
        case 7:
            // cout << "\n6. Thoat";
            HoaDon::ThongKeHoaDon(hoaDon);
            break;
        case 8:
            return;
        default:
            cout << "\n\tKhong co chuc nang nay!";
            cout << "\n\tHay chon chuc nang trong hop menu.";
            tiepTuc();
        }
    }
}