#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <string>
#include <vector>
using namespace std;
class KhachHang {
        std::string maKhachHang;
        std::string tenKhachHang;
        string diaChi, dienThoai, ngaySinh;
        string gioiTinh;
   
    static int count;
public:
    void Nhap();
    static void CreateKhachHang(vector<KhachHang>);
    void setMaKhachHang(string);
    void setTenKhachHang(string);
    void setDiaChi(string);
    void setDienThoai(string);
    void setNgaySinh(string);
    void setGioiTinh(string);
    string getMaKhachHang();
    string getTenKhachHang();
    string getDiaChi();
    string getDienThoai();
    string getNgaySinh();
    string getGioiTinh();   
    static void ReadKhachHang(vector<KhachHang>);
};
#endif
