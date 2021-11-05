
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
    void Show1MayTinh(vector<MayTinh>&);
    static void ShowKho(vector<MayTinh>&);
    static void AddKho(vector<MayTinh>&);
    static int CheckTonTai(vector<MayTinh>&, string);
    void WriteToFileMayTinh(string);
    string getGiaBanMoneyFormat();
    friend class HoaDon;
};
#endif
