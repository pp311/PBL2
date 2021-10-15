using namespace std;
#include "khachhang.h"
#include "maytinh.h"
#include "hoadon.h"
#include "thongtinhoadon.h"
#include "kho.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
vector<MayTinh> mayTinh;
vector<HoaDon> hoaDon;
vector<KhachHang> khachHang;
//KhachHang khachHang[100];
//MayTinh mayTinh[100];
ThongTinHoaDon thongTinHoaDon[100];
int main() {
	//MayTinh::CreateMayTinh(mayTinh);
    //MayTinh::CreateMayTinh(mayTinh);

    MayTinh::ReadSanPham(mayTinh);

    //MayTinh::DeleteMayTinh(mayTinh);
    MayTinh::EditMayTinh(mayTinh);

    MayTinh::ReadSanPham(mayTinh);

    //Kho::ReadKho(kho);
	//KhachHang::ReadKhachHang(khachHang);
    //HoaDon::ReadHoaDon(hoaDon);
    //ThongTinHoaDon::ReadThongTinHoaDon(thongTinHoaDon);
    system("pause");
    return 0;
}
