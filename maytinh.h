
#ifndef MAYTINH_H
#define MAYTINH_H
#include<string>
#include<vector>
using namespace std;
class MayTinh
{
    string maMay;
    string tenHang;
    string cpu;
    string ram;
    string disk;
    int namSX;
    string xuatXu;
    int giaBan;
    //int giamGia;
    int thoiGianBaoHanh;
    static int count;
public:
    void Nhap();
    static void CreateMayTinh(vector<MayTinh> mayTinh);
    void setMaMay(string );
    void setTenHang(string );
    void setCpu(string );
    void setRam(string );
    void setDisk(string );
    void setNamSX(int );
	void setXuatXu(string );
	void setGiaBan(int gia);
	void setThoiGianBaoHanh(int );
    string getMaMay();
    string getTenHang();
    string getCpu();
    string getRam();
    string getDisk();
    int getNamSX();
    string getXuatXu();
	int getGiaBan();
    int getThoiGianBaoHanh();
    static void ReadSanPham(vector<MayTinh> mayTinh);
};
#endif
