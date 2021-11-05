#include "maytinh.h" 
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;

int MayTinh::count = 0; //so sanpham
	void MayTinh::Nhap(vector<MayTinh>& mayTinh, string maMay)
    {
    NhapLai:
        if (maMay == "") {
            cout << "\n\tNhap ma may: ";
            cin >> this->maMay;
        }
        else this->maMay = maMay;
        if (CheckTonTai(mayTinh, this->maMay) != -1) {
            cout << "\n\tMa may nay da ton tai. Vui long nhap lai!\n\t";
            system("pause");
            goto NhapLai;
        }
        cout << "\n\tNhap ten hang: ";
        cin.ignore();
        getline(cin, this->tenHang);
        cout << "\n\tNhap cpu: ";
        cin >> this->cpu;
        cout << "\n\tNhap dung luong ram: ";
        cin >> this->ram;
        cout << "\n\tNhap dung luong o cung: ";
        cin >> this->disk;
        cout << "\n\tNhap nam san xuat: ";
        cin >> this->namSX;
        cout << "\n\tNhap noi xuat xu: ";
        cin.ignore();
        getline(cin, this->xuatXu);
        cout << "\n\tNhap thoi gian bao hanh (thang):";
        cin >> this->thoiGianBaoHanh;
        cout << "\n\tNhap gia ban: ";
        cin >> this->giaBan;
        this->soLuong = 0;
    }
    //Write To File maytinh.txt
    void MayTinh::WriteToFileMayTinh(string tenFile) {
		fstream file(tenFile, ios::app);
        file << this->maMay << "\t" << this->tenHang << "\t" << this->cpu << "\t" << this->ram << "\t" << this->disk << "\t" << this->namSX << "\t" << this->xuatXu << "\t" 
            << this->thoiGianBaoHanh << "\t" << this->giaBan <<"\t" << this->soLuong << "\n";
        file.close();
    }
    //Create may tinh
    void MayTinh::AddMayTinh(vector<MayTinh>& mayTinh, string maMay)
    {
        mayTinh.resize(count + 5);
        mayTinh[count].Nhap(mayTinh, maMay);
        mayTinh[count].WriteToFileMayTinh("maytinh.txt");
        count++;
        int chon;
        cout << "\n\n\tThem thanh cong";
    }
    //delete may tinh
    void MayTinh::DeleteMayTinh(vector<MayTinh>& mayTinh) {
        string maMay;
        int pos;
    NhapLai:
        system("cls");
        cout << "\n\n\t\t\t\t\t===== XOA THONG TIN MAY TINH =====\n\n\t";
        cout << "\n\n\tNhap ma may tinh can xoa: ";
        cin >> maMay;
        pos = CheckTonTai(mayTinh, maMay);
        if (pos == -1) {
            cout << "\n\tMay tinh nay khong ton tai. Vui long nhap lai!\n\t";
            system("pause");
            goto NhapLai;
        }
        else {
        Show1MayTinh(mayTinh, maMay);
        char c;
        cout << "\n\tXac nhan xoa may tinh nay khoi he thong? <Y/N>";
        cin >> c;
        if (c == 'N' || c == 'n') return;
            for (int i = 0; i < count; i++) {
                if (mayTinh[i].maMay != maMay) {
                    mayTinh[i].WriteToFileMayTinh("maytinhtam.txt");
                }
                else {
                    mayTinh.erase(mayTinh.begin() + i, mayTinh.begin() + i + 1);
                }
            }
            count--;
            remove("maytinh.txt");
            rename("maytinhtam.txt", "maytinh.txt");
            cout << "\n\tXoa thanh cong!";
            int chon;
            cout << "\n\tBan co muon tiep tuc xoa?";
            cout << "\n\t 1. Co" << "\n\t 2. Khong" << endl;
            cout << "\n\tLua chon: ";
            cin >> chon;
            if (chon == 1) goto NhapLai;
        }
    }   
    //Neu ton tai thi tra ve vi tri. neu khong thi tra ve -1
    int MayTinh::CheckTonTai(vector<MayTinh>& mayTinh, string maMay) {
        for (int i = 0; i < count; i++) {
            if (mayTinh[i].maMay == maMay) {
                return i;
            }
        }
        return -1;
    }
    void MayTinh::ReadMayTinh(vector<MayTinh>& mayTinh) {
        fstream file("maytinh.txt", ios::in);
        MayTinh input;
        int i = 0;
        string temp;
        while (!file.eof())
        {
            string temp;
            if (!getline(file, input.maMay, '\t') || input.maMay.length() <= 1) break; //kiem tra dong trong
            getline(file, input.tenHang, '\t');
            getline(file, input.cpu, '\t');
            getline(file, input.ram, '\t');
            getline(file, input.disk, '\t');
            getline(file, temp, '\t'); //getline chi dc dung kieu string, nhung namSX kieu int nen phai dung bien temp
            input.namSX = atoi(temp.c_str());
            getline(file, input.xuatXu, '\t');
            getline(file, temp, '\t');
            input.thoiGianBaoHanh = atoi(temp.c_str());
            getline(file, temp,'\t');
            input.giaBan = atoi(temp.c_str());
            getline(file, temp);
            input.soLuong = atoi(temp.c_str());
            mayTinh.push_back(input);
            i++;
        }
        count = i;
        file.close();
    }
    void MayTinh::ShowMayTinh(vector<MayTinh>& mayTinh) {
        cout << "\n\n\t\t\t\t\t===== DANH SACH MAY TINH =====\n\n\t";
        cout <<left<< setw(10)<<"Ma May"<<setw(12)<<"Ten Hang" <<setw(10)<<"CPU" << setw(10)<<"Ram" <<setw(10)<<"Disk"<<setw(18)
            <<"Nam San Xuat" << setw(15) << "Xuat Xu" << setw(10) << "TGBH" << setw(15) << "Gia" << endl;
        char prev = cout.fill('-');
        cout.width(105);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        for (int i = 0; i < count; i++) {
            cout << "\t";
            cout << setw(10)<< mayTinh[i].maMay;
            cout << setw(12) << mayTinh[i].tenHang;
            cout << setw(10) << mayTinh[i].cpu ;
            cout << setw(10) << mayTinh[i].ram ;
            cout << setw(10) << mayTinh[i].disk ;
            cout << setw(18) << mayTinh[i].namSX ;
            cout << setw(15) << mayTinh[i].xuatXu ;
            cout << setw(10) << mayTinh[i].thoiGianBaoHanh;
            cout << setw(15) << mayTinh[i].giaBan << endl;
        }
        cout << "\n\n\n\t";
    }
    void MayTinh::Show1MayTinh(vector<MayTinh>& mayTinh, string maMay) {
        cout << "\n\n\t";
        cout << left << setw(10) << "Ma May" << setw(12) << "Ten Hang" << setw(10) << "CPU" << setw(10) << "Ram" << setw(10) << "Disk" << setw(18) << "Nam San Xuat" << setw(15) << "Xuat Xu" << setw(10) << "TGBH" << setw(15) << "Gia" << endl;
        char prev = cout.fill('-');
        cout.width(105);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        for (int i = 0; i < count; i++) {
            if (mayTinh[i].maMay == maMay) {
                cout << "\t";
                cout << setw(10) << mayTinh[i].maMay;
                cout << setw(12) << mayTinh[i].tenHang;
                cout << setw(10) << mayTinh[i].cpu;
                cout << setw(10) << mayTinh[i].ram;
                cout << setw(10) << mayTinh[i].disk;
                cout << setw(18) << mayTinh[i].namSX;
                cout << setw(15) << mayTinh[i].xuatXu;
                cout << setw(10) << mayTinh[i].thoiGianBaoHanh;
                cout << setw(15) << mayTinh[i].giaBan << endl;
            }
        }
        cout << "\n\n\t";
    }
    void MayTinh::ShowKho(vector<MayTinh>& mayTinh) {
        cout << "\n\n\t\t\t\t\t\t===== THONG TIN KHO =====\n\n\t";

        cout << left << setw(20) << "Ma May" << setw(20) << "So Luong"<<endl;
        char prev = cout.fill('-');
        cout.width(40);
        cout << "\t-";
        cout.fill(prev);
        cout << endl;
        for (int i = 0; i < count; i++) {
            cout << "\t";
            cout << setw(20) << mayTinh[i].maMay;
            cout << setw(20) << mayTinh[i].soLuong;
            cout << endl;
        }
        cout << "\n\n\t";
    }
    void MayTinh::AddKho(vector<MayTinh>& mayTinh) {
        string maMay;
        bool tonTai;
    NhapLai:
        system("cls");
        tonTai = false;
        cout << "\n\n\t\t\t\t\t\t===== NHAP HANG VE =====\n\n\t";
        cout << "\n\tNhap ma may tinh: ";
        cin >> maMay;
        int i = 0;
        for (i; i < count; i++) {
            if (mayTinh[i].maMay == maMay) {
                tonTai = true;
                cout << "\n\tSo luong hien co: " << mayTinh[i].soLuong << endl;
                break;
            }
        }
        if (tonTai == false) {
            int luaChon;
            cout << "\n\tThong tin may tinh nay khong co trong he thong. Them moi thong tin may?";
            cout << "\n\t 1. Them moi thong tin may\n\t 2. Nhap lai ma may";
            cout << "\n\tLua chon: ";
            cin >> luaChon;
            if (luaChon == 1) AddMayTinh(mayTinh, maMay);
            else goto NhapLai;
        }
        int nhapThem = 0;
        cout << "\n\tSo luong may tinh muon nhap them: ";
        cin >> nhapThem;
        mayTinh[i].soLuong += nhapThem;
        for (int i = 0; i < count; i++) {
            mayTinh[i].WriteToFileMayTinh("maytinhtam.txt");
        }
        remove("maytinh.txt");
        rename("maytinhtam.txt", "maytinh.txt");
        cout << "\n\tNhap them thanh cong!";
        int chon;
        cout << "\n\tBan co muon tiep tuc nhap them may?";
        cout << "\n\t 1. Co" << "\n\t 2. Khong" << endl;
        cout << "\n\tLua chon: ";
        cin >> chon;
        if (chon == 1) goto NhapLai;
    }
    void MayTinh::EditMayTinh(vector<MayTinh>& mayTinh) {
        //system("cls");
        string maMay;
        int pos;
    NhapLai1:
        system("cls");
        cout << "\n\n\t\t\t\t\t===== CHINH SUA THONG TIN MAY TINH =====\n\n\t";
        cout << "\n\tNhap ma may tinh can chinh sua: ";
        cin >> maMay;
        pos = CheckTonTai(mayTinh, maMay);
        if (pos == -1) {
            cout << "\n\tMay tinh nay khong ton tai. Vui long nhap lai!\n\t";
            system("pause");
            goto NhapLai1;
        }
        else {
            int luaChon;
            string temp;
            int num;
        NhapLai2:
            system("cls");
            cout << "\n\n\t\t\t\t\t===== CHINH SUA THONG TIN MAY TINH =====\n\n\t";
            Show1MayTinh(mayTinh, maMay);
            cout << "\n\tChon thong tin can chinh sua:";
            cout << "\n\t1. Ten Hang";
            cout << "\n\t2. CPU";
            cout << "\n\t3. Ram";
            cout << "\n\t4. Disk";
            cout << "\n\t5. Nam san xuat";
            cout << "\n\t6. Xuat xu";
            cout << "\n\t7. Thoi gian bao hanh";
            cout << "\n\t8. Gia ban";
            cout << "\n\t-------------";
            cout << "\n\tNhap lua chon: ";
            cin >> luaChon;
            switch (luaChon) {
            case 1:
                cout << "\n\tNhap ten hang: ";
                cin >> temp;
                mayTinh[pos].tenHang = temp;
                break;
            case 2:
                cout << "\n\tNhap CPU: ";
                cin >> temp;
                mayTinh[pos].cpu = temp;
                break;
            case 3:
                cout << "\n\tNhap dung luong ram: ";
                cin >> temp;
                mayTinh[pos].ram = temp;
                break;
            case 4:
                cout << "\n\tNhap dung luong o cung: ";
                cin >> temp;
                mayTinh[pos].disk = temp;
                break;
            case 5:
                cout << "\n\tNhap nam san xuat: ";
                cin >> num;
                mayTinh[pos].namSX = num;
                break;
            case 6:
                cout << "\n\tNhap noi xuat xu: ";
                cin.ignore();
                getline(cin, temp);
                mayTinh[pos].tenHang = temp;
                break;
            case 7:
                cout << "\n\tNhap thoi gian bao hanh: ";
                cin >> num;
                mayTinh[pos].thoiGianBaoHanh = num;
                break;
            case 8:
                cout << "\n\tNhap gia ban: ";
                cin >> num;
                mayTinh[pos].giaBan = num;
                break;
            default:
                cout << "\n\tSo khong hop le. Vui long nhap lai!\n\t";
                system("pause");
                goto NhapLai2;
                break;
            }
            for (int i = 0; i < count; i++) {
                mayTinh[i].WriteToFileMayTinh("maytinhtam.txt");
            }
            remove("maytinh.txt");
            rename("maytinhtam.txt", "maytinh.txt");
            int chon;
            cout << "\n\tSua doi thanh cong!\n\t";
            system("pause");
            cout << "\n\tBan co muon tiep tuc chinh sua?";
            cout << "\n\t 1. Tiep tuc chinh sua may tinh hien tai"<<"\n\t 2. Chinh sua may tinh khac"<<"\n\t 3. Thoat" << endl;
            cout << "\n\tLua chon: ";
            cin >> chon;
            if (chon == 1) goto NhapLai2;
            else if (chon == 2) goto NhapLai1;
        }
    }


