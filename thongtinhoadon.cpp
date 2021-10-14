#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "thongtinhoadon.h"
using namespace std;

int ThongTinHoaDon::count = 0;
void ThongTinHoaDon::Nhap()
{
    cout << "\nNhap ma hoa don: ";
    cin >> this->maHoaDon;
    cout << "\nNhap ma may tinh: ";
    cin >> this->maMay;
    cout << "\nNhap so luong : ";
    cin >> this->soLuong;
}
void ThongTinHoaDon::CreateThongTinHoaDon()
{
    system("cls");
    Nhap();
    fstream file("ThongTinHoaDon.txt", ios::app);
    file << this->maHoaDon << "\t" << this->maMay << "\t" << this->soLuong << "\n";
    file.close();
}
void ThongTinHoaDon::setMaHoaDon(string mhd)
{
    maHoaDon = mhd;
}
void ThongTinHoaDon::setMaMay(string mm)
{
    maMay = mm;
}
void ThongTinHoaDon::setSoLuong(int sl)
{
    soLuong = sl;
}
string ThongTinHoaDon::getMaHoaDon()
{
    return maHoaDon;
}
string ThongTinHoaDon::getMaMay()
{
    return maMay;
}
int ThongTinHoaDon::getSoLuong()
{
    return soLuong;
}
void ThongTinHoaDon::ReadThongTinHoaDon(ThongTinHoaDon thongTinHoaDon[])
{
    system("cls");
    fstream file("ThongTinHoaDon.txt", ios::in);
    int i = 0;

    while (!file.eof())
    {
        string temp;
        getline(file, thongTinHoaDon[i].maHoaDon, '\t');
        getline(file, thongTinHoaDon[i].maMay, '\t');
        getline(file, temp);
        thongTinHoaDon[i].soLuong = atoi(temp.c_str());

        cout << "Thong tin hoa don: " << i + 1 << ":" << thongTinHoaDon[i].maHoaDon << " " << thongTinHoaDon[i].maMay << " " << thongTinHoaDon[i].soLuong << endl;
        i++;
    }
    count = i;
    file.close();
}
