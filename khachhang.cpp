#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include "khachhang.h"
using namespace std;

int KhachHang::count = 0; //so KhachHang

    void KhachHang::Nhap(vector<KhachHang>& khachHang, string maKhachHang) {
        NhapLai:
        if (maKhachHang == "")      //khi tao hoa don, nhap va kiem tra ma khach hang, neu chua co thi tao moi, luc nay da co maKhachHang 
        {
            cout << "\n\tNhap ma khach hang: "; cin >> this->maKhachHang;
        }
        else this->maKhachHang = maKhachHang;
        if (CheckTonTai(khachHang, this->maKhachHang) != -1) {
            cout << "\n\tMa khach hang nay da ton tai. Vui long nhap lai!\n";
            goto NhapLai;
        }
            cout<<"\n\tNhap ten khach hang: "; cin.ignore(); getline(cin, this->tenKhachHang);
            cout<<"\n\tNhap nam sinh: "; cin>>this->namSinh;
            cout<<"\n\tNhap gioi tinh: "; cin>>this->gioiTinh;      
            cout<<"\n\tNhap so dien Thoai: "; cin>>this->dienThoai;
            cout<<"\n\tNhap dia chi: "; cin.ignore(); getline(cin, this->diaChi);
    }
    int KhachHang::CheckTonTai(vector<KhachHang>& khachHang, string maKhachHang) {
        for (int i = 0; i < count; i++) {
            if (khachHang[i].maKhachHang == maKhachHang) {
                return i;
            }
        }
        return -1;
    }
    //CreateKhachHang
    void KhachHang::AddKhachHang(vector<KhachHang>& khachHang, string maKhachHang) {
        khachHang.resize(count + 10);
        khachHang[count].Nhap(khachHang, maKhachHang);
        khachHang[count].WriteToFileKhachHang("khachhang.txt");
        count++;
        int chon;
        cout << "Them thanh cong!";
    }
    //ShowKhachHang
    void KhachHang::ShowKhachHang(vector<KhachHang>& khachHang) {
        cout << "\n\n\t\t\t\t\t\tDANH SACH KHACH HANG\n\n\t";
        cout <<left << setw(17) << "Ma Khach Hang" << setw(20) << "Ten Khach Hang" << setw(12) << "Nam Sinh" 
            << setw(12) << "Gioi Tinh" << setw(15) << "So DT" << setw(30) << "Dia Chi"<<endl;
        char prev = cout.fill('-');
        cout.width(100);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        for (int i = 0; i < count; i++) {
            cout << "\t";
            cout << setw(17) << khachHang[i].maKhachHang;
           cout << setw(20) << khachHang[i].tenKhachHang;
            cout << setw(12) << khachHang[i].namSinh;
            cout << setw(12) << khachHang[i].gioiTinh;
           cout << setw(15) << khachHang[i].dienThoai;
            cout << setw(30) << khachHang[i].diaChi <<endl;
        }
        cout << "\n\n\t";
    }
    void KhachHang::Show1KhachHang(vector<KhachHang>& khachHang, string maKhachHang) {
        cout << "\n\n\t";
        cout << left << setw(17) << "Ma Khach Hang" << setw(20) << "Ten Khach Hang" << setw(12) << "Nam Sinh" << setw(12) << "GioiTinh" 
            << setw(15) << "So DT" << setw(30) << "Dia Chi" << endl;
        char prev = cout.fill('-');
        cout.width(100);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        for (int i = 0; i < count; i++) {
            if (khachHang[i].maKhachHang == maKhachHang) {
                cout << "\t";
                cout << setw(17) << khachHang[i].maKhachHang;
                cout << setw(20) << khachHang[i].tenKhachHang;
                cout << setw(12) << khachHang[i].namSinh;
                cout << setw(12) << khachHang[i].gioiTinh;
                cout << setw(15) << khachHang[i].dienThoai;
                cout << setw(30) << khachHang[i].diaChi << endl;
            }
        }
        cout << "\n\n\t";
    }
    //ReadKhachHang
    void KhachHang::ReadKhachHang(vector<KhachHang>& khachHang)
    {
        fstream file("KhachHang.txt", ios::in);
        int i = 0;
		KhachHang input;
        while (!file.eof())
        {
            string temp;
            if(!getline(file, input.maKhachHang, '\t')) break;
            getline(file, input.tenKhachHang, '\t');
            getline(file, temp, '\t');
            input.namSinh = atoi(temp.c_str());
            getline(file, input.gioiTinh, '\t');
            getline(file, input.dienThoai, '\t');
            getline(file, input.diaChi);
			khachHang.push_back(input);       
            i++;
        }
        count = i;
        file.close();
    }
    //DeleteKhachHang
    void KhachHang::DeleteKhachHang(vector<KhachHang>& khachHang) {
        string maKhachHang;
        int pos;
    NhapLai:
        system("cls");
        cout << "\n\n\t\t\t\t\t===== XOA THONG TIN KHACH HANG =====\n\n\t";
        cout << "\n\tNhap ma khach hang can xoa: ";
        cin >> maKhachHang;
        pos = CheckTonTai(khachHang, maKhachHang);
        if (pos == -1) {
            cout << "\n\tKhach hang nay khong ton tai. Vui long nhap lai!\n\t";
            system("pause");
            goto NhapLai;
        }
        else {
            Show1KhachHang(khachHang, maKhachHang);
            char c;
            cout << "\n\tXac nhan xoa thong tin khach hang nay khoi he thong? <Y/N>";
            cin >> c;
            if (c == 'N' || c == 'n') return;
            for (int i = 0; i < count; i++) {
                if (khachHang[i].maKhachHang != maKhachHang) {
                    khachHang[i].WriteToFileKhachHang("khachhangtam.txt");
                }
                else {
                    khachHang.erase(khachHang.begin() + i, khachHang.begin() + i + 1);
                }
            }
            count--;
            remove("khachhang.txt");
            rename("khachhangtam.txt", "khachhang.txt");
            cout << "\n\tXoa thanh cong!";
            int chon;
            cout << "\n\tBan co muon tiep tuc xoa?";
            cout << "\n\t 1. Co" << "\n\t 2. Khong" << endl;
            cout << "\tLua chon: ";
            cin >> chon;
            if (chon == 1) goto NhapLai;
        }
    }
    void KhachHang::EditKhachHang(vector<KhachHang>& khachHang) {
        string maKhachHang;
        int pos;
    NhapLai1:
        system("cls");
        cout << "\n\n\t\t\t\t\t===== CHINH SUA THONG TIN KHACH HANG =====\n\n\t";
        cout << "\n\tNhap ma khach hang can chinh sua: ";
        cin >> maKhachHang;
        pos = CheckTonTai(khachHang, maKhachHang);
        if (pos == -1) {
            cout << "\n\tKhach hang nay khong ton tai. Vui long nhap lai!\n\t";
            system("pause");
            goto NhapLai1;
        }
        else {
            int luaChon;
            string temp;
            int num;
        NhapLai2:
            system("cls");
            cout << "\n\n\t\t\t\t\t===== CHINH SUA THONG TIN KHACH HANG =====\n\n\t";
            Show1KhachHang(khachHang, maKhachHang);
            cout << "\n\tChon thong tin can chinh sua:";
            cout << "\n\t1. Ten khach hang";
            cout << "\n\t2. Dia chi";
            cout << "\n\t3. Dien thoai";
            cout << "\n\t4. Nam sinh";
            cout << "\n\t5. Gioi tinh";
            cout << "\n\t-------------";
            cout << "\n\tNhap lua chon:";
            cin >> luaChon;
            switch (luaChon) {
            case 1:
                cout << "\n\tNhap ten khach hang:";
                cin >> temp;
                khachHang[pos].tenKhachHang = temp;
                break;
            case 2:
                cout << "\n\tNhap dia chi:";
                cin >> temp;
                khachHang[pos].diaChi = temp;
                break;
            case 3:
                cout << "\n\tNhap so dien thoai:";
                cin >> temp;
                khachHang[pos].dienThoai = temp;
                break;
            case 4:
                cout << "\n\tNhap nam sinh:";
                cin >> num;
                khachHang[pos].namSinh = num;
                break;
            case 5:
                cout << "\n\tNhap gioi tinh:";
                cin >> temp;
                khachHang[pos].gioiTinh = temp;
                break;
            default:
                cout << "\n\tSo khong hop le. Vui long nhap lai!\n\t";
                system("pause");
                goto NhapLai2;
                break;
            }
            for (int i = 0; i < count; i++) {
                khachHang[i].WriteToFileKhachHang("khachhangtam.txt");
            }
            remove("khachhang.txt");
            rename("khachhangtam.txt", "khachhang.txt");
            int chon;
            cout << "\n\tSua doi thanh cong!\n\t";
            system("pause");
            cout << "\n\tBan co muon tiep tuc chinh sua?";
            cout << "\n\t 1. Tiep tuc chinh sua thong tin khach hang hien tai" << "\n\t 2. Chinh sua thong tin cua khach hang khac" << "\n\t 3. Thoat" << endl;
            cout << "\tLua chon: ";
            cin >> chon;
            if (chon == 1) goto NhapLai2;
            else if (chon == 2) goto NhapLai1;
        }
        
    }
    void KhachHang::WriteToFileKhachHang(string tenFile) {
        fstream file(tenFile, ios::app);
        file << this->maKhachHang << "\t" << this->tenKhachHang << "\t" <<  this->namSinh << "\t" << this->gioiTinh <<"\t" 
            << this->dienThoai << "\t" << this->diaChi << "\n";
        file.close();
    }
    void KhachHang::setMaKhachHang(string mkh)
    {
    	maKhachHang=mkh;
	}
	void KhachHang::setTenKhachHang(string tkh)
    {
    	tenKhachHang=tkh;
	}
	void KhachHang::setDiaChi(string dc)
    {
    	diaChi=dc;
	}
	void KhachHang::setDienThoai(string dt)
    {
    	dienThoai=dt;
	}
	void KhachHang::setNamSinh(int ns)
    {
    	namSinh=ns;
	}
	void KhachHang::setGioiTinh(string gt)
    {
    	gioiTinh=gt;
	}
    string KhachHang::getMaKhachHang(){
    return maKhachHang;
    }
    string KhachHang::getTenKhachHang(){
    return tenKhachHang;
    }
    string KhachHang::getDiaChi(){
    return diaChi;
    }
    string KhachHang::getDienThoai(){
    return dienThoai;
    }
    int KhachHang::getNamSinh(){
    return namSinh;
    }    
    string KhachHang::getGioiTinh(){
    return gioiTinh;
    }



