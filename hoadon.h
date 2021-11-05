#ifndef HOADON_H
#define HOADON_H
#include <string>
#include <vector>
#include "khachhang.h"
#include "maytinh.h"

using namespace std;
class HoaDon
{
    string maHoaDon;
    string maKhachHang;
    string ngayBan;
    int soSanPham;
    string maMay[100];
    int soLuong[100];
    int donGia[100];
    int tongTien;
    static int count;
public:
    void Nhap(vector<HoaDon>&, vector<KhachHang>&, vector<MayTinh>&);
    static void AddHoaDon(vector<HoaDon>&, vector<KhachHang>&, vector<MayTinh>&);
    static void ReadHoaDon(vector<HoaDon>&);
    void TinhTien();
    static int CheckTonTai(vector<HoaDon>&, string);
    static void DeleteHoaDon(vector<HoaDon>&);
    static void EditHoaDon(vector <HoaDon>&);
    static void ShowHoaDon(vector<HoaDon>&, vector<KhachHang>&, vector<MayTinh>&);
    static void ThongKeHoaDon(vector<HoaDon>&);
    static void tach(string, int*);
    static int sosanh(string, string);
    static int check(string);
    static string MoneyFormat(int);
    void Show1HoaDon(vector<HoaDon>&);
    void ShowChiTietHoaDon(vector<HoaDon>&, vector<KhachHang>&, vector<MayTinh>&);
    void WriteToFileHoaDon(string);
};
#endif
