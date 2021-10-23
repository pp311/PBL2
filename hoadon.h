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
    int soSanPham;
    string maMay[100];
    int soLuong[100];
    int tongTien;
    static int count;
public:
    void Nhap();
    static void CreateHoaDon(vector<HoaDon>&);
    static void ReadHoaDon(vector<HoaDon>&);
    static void DeleteHoaDon(vector<HoaDon>&);
    static void EditHoaDon(vector <HoaDon>&);
    void WriteToFileHoaDon(string);
    void setMaHoaDon(string );
    void setMaKhachHang(string );
    void setNgayBan(string );
    void setTongTien(int );
    string getMaHoaDon();
    string getMaKhachHang();
    string getNgayBan();
	int getTongTien();
};
#endif
