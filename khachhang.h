#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <string>
#include <vector>
using namespace std;
class KhachHang {
        string maKhachHang;
        string tenKhachHang;
        string diaChi, dienThoai;
        int namSinh;
        string gioiTinh;
   
    static int count;
public:
    void Nhap(vector<KhachHang>& , string);
    static void AddKhachHang(vector<KhachHang>&, string = "");
    static void ReadKhachHang(vector<KhachHang>&);
    static void DeleteKhachHang(vector<KhachHang>&);
    static void EditKhachHang(vector<KhachHang>&);
    static void ShowKhachHang(vector<KhachHang>&);
    void Show1KhachHang(vector<KhachHang>&);
    static int CheckTonTai(vector<KhachHang>&, string);
    void WriteToFileKhachHang(string);
    friend class HoaDon;
};
#endif
