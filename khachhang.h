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
    static void Show1KhachHang(vector<KhachHang>&, string);
    static int CheckTonTai(vector<KhachHang>&, string);
    void WriteToFileKhachHang(string);
    void setMaKhachHang(string);
    void setTenKhachHang(string);
    void setDiaChi(string);
    void setDienThoai(string);
    void setNamSinh(int);
    void setGioiTinh(string);
    string getMaKhachHang();
    string getTenKhachHang();
    string getDiaChi();
    string getDienThoai();
    int getNamSinh();
    string getGioiTinh();   
    friend class HoaDon;
};
#endif
