#ifndef KHO_H
#define KHO_H
#include<string>
using namespace std;
class Kho
{
    string maSanPham;
    int soLuong;
    static int count;
public:
    void Nhap();
    void CreateKho();
    void setMaSanPham(string );
	void setSoLuong(int );
    string getMaSanPham();
    int getSoLuong();
    static void ReadKho(Kho sanPham[]);
};
#endif

