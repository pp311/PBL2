
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
    int soLuong;
    static int count;
public:
    void Nhap(vector<MayTinh>&, string);
    static void AddMayTinh(vector<MayTinh>&, string = "");
    static void DeleteMayTinh(vector<MayTinh>&);
    static void EditMayTinh(vector<MayTinh>&);
    static void ReadMayTinh(vector<MayTinh>&);
    static void ShowMayTinh(vector<MayTinh>&);
    static void Show1MayTinh(vector<MayTinh>&, string);
    static void ShowKho(vector<MayTinh>&);
    static void AddKho(vector<MayTinh>&);
    static int CheckTonTai(vector<MayTinh>&, string);
    void WriteToFileMayTinh(string);
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
    void setSoLuong(int);
    int getSoLuong();
    friend class HoaDon;
};
#endif
