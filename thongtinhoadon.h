#ifndef THONGTINHOADON_H
#define THONGTINHOADON_H
#include<string>
using namespace std;
class ThongTinHoaDon
{
private:
    string maHoaDon;
    string maMay;
    int soLuong;
    static int count;
public:
    void Nhap();
    void CreateThongTinHoaDon();
    void setMaHoaDon(string );
    void setMaMay(string );
    void setSoLuong(int );
    string getMaHoaDon();
    string getMay();
	string getMaMay();
	int getSoLuong();
    static void ReadThongTinHoaDon(ThongTinHoaDon thongTinHoaDon[]);
};
#endif
