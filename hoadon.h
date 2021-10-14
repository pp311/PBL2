#ifndef HOADON_H
#define HOADON_H
#include <string>
#include <vector>
using namespace std;
class HoaDon
{
    string maHoaDon;
    string maKhachHang;
    string ngayBan;
    int tongTien;
    static int count;
public:
    void Nhap();
    static void CreateHoaDon(vector<HoaDon>);
    void setMaHoaDon(string );
    void setMaKhachHang(string );
    void setNgayBan(string );
    void setTongTien(int );
    string getMaHoaDon();
    string getMaKhachHang();
    string getNgayBan();
	int getTongTien();
    static void ReadHoaDon(vector<HoaDon>);
};
#endif
