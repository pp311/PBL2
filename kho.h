#ifndef KHO_H
#define KHO_H
#include<string>
#include<vector>
using namespace std;
class Kho
{
    string maSanPham;
    int soLuong;
    static int count;
public:
    void Nhap();
    static void CreateKho(vector<Kho>);
    void setMaSanPham(string );
	void setSoLuong(int );
    string getMaSanPham();
    int getSoLuong();
    static void ReadKho(vector <Kho>);
};
#endif

