#include "maytinh.h" 
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;

int MayTinh::count = 0; //so sanpham
	void MayTinh::Nhap()
    {
        cout << "\nNhap ma may: ";
        cin >> this->maMay;
        cout << "\nNhap ten hang: ";
        cin.ignore();
        getline(cin, this->tenHang);
        cout << "\nNhap cpu: ";
        cin >> this->cpu;
        cout << "\nNhap dung luong ram: ";
        cin >> this->ram;
        cout << "\nNhap dung luong o cung: ";
        cin >> this->disk;
        cout << "\nNhap nam san xuat: ";
        cin >> this->namSX;
        cout << "\nNhap noi xuat xu: ";
        cin.ignore();
        getline(cin, this->xuatXu);
        cout << "\nNhap thoi gian bao hanh (thang):";
        cin >> this->thoiGianBaoHanh;
        cout << "\nNhap gia ban: ";
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
    void MayTinh::AddMayTinh(vector<MayTinh>& mayTinh)
    {
        system("cls");
		mayTinh.resize(count + 5);
		mayTinh[count].Nhap();
        mayTinh[count].WriteToFileMayTinh("maytinh.txt");
        count++;
    }
    //delete may tinh
    void MayTinh::DeleteMayTinh(vector<MayTinh>& mayTinh) {
        string maMay;
        cout << "Nhap ma may tinh can xoa: ";
        cin >> maMay;
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
    }
    //chinh sua may tinh
    
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
        //system("cls");
        fstream file("maytinh.txt", ios::in);
        MayTinh input;
        int i = 0;
        string temp;
        // file>>this->maMay>>this->tenHang>>this->cpu>>this->ram>>this->disk>>this->namSX>>this->xuatXu>>this->thoiGianBaoHanh>>this->giaBan;
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
            getline(file, temp);
            input.giaBan = atoi(temp.c_str());
            getline(file, temp);
            input.soLuong = atoi(temp.c_str());
            mayTinh.push_back(input);
            //cout << "Thong tin may " << i + 1 << ":" << input.maMay << " " << input.tenHang << " " << input.cpu << " " << input.ram << " " << input.disk << " " << input.namSX << " " << input.xuatXu << " " <<
              //  input.thoiGianBaoHanh << " " << input.giaBan << endl;
            i++;
        }
        count = i;
        file.close();
    }
    void MayTinh::ShowMayTinh(vector<MayTinh>& mayTinh) {
        cout << "\n\n\n\t";
        cout <<left<< setw(10)<<"Ma May"<<setw(12)<<"Ten Hang" <<setw(10)<<"CPU" << setw(10)<<"Ram" <<setw(10)<<"Disk"<<setw(18)<<"Nam San Xuat" << setw(15) << "Xuat Xu" << setw(10) << "TGBH" << setw(15) << "Gia" << endl;
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
    }
    void MayTinh::Show1MayTinh(vector<MayTinh>& mayTinh, string maMay) {
        cout << "\n\n\n\t";
        cout << left << setw(10) << "Ma May" << setw(12) << "Ten Hang" << setw(10) << "CPU" << setw(10) << "Ram" << setw(10) << "Disk" << setw(18) << "Nam San Xuat" << setw(15) << "Xuat Xu" << setw(10) << "TGBH" << setw(15) << "Gia" << endl;
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
    }
    void MayTinh::ShowKho(vector<MayTinh>& mayTinh) {
        cout << "\n\n\n\t";
        cout << left << setw(10) << "Ma May" << setw(20) << "So Luong"<<endl;
        for (int i = 0; i < count; i++) {
            cout << "\t";
            cout << setw(10) << mayTinh[i].maMay;
            cout << setw(20) << mayTinh[i].soLuong;
            cout << endl;
        }
    }
    void MayTinh::AddKho(vector<MayTinh>& mayTinh) {
        system("cls");
        string maMay;
        bool tonTai = false;
        NhapLai:
        cout << "\nNhap ma may tinh:";
        cin >> maMay;
        int i = 0;
        for ( i; i < count; i++) {
            if (mayTinh[i].maMay == maMay) {
                tonTai = true;
                cout << "\nSo luong hien co: " << mayTinh[i].soLuong<<endl;
                break;
            }
        }
        if (tonTai == false) {
            cout << "\nThong tin may tinh nay khong co trong he thong. Vui long nhap lai!";
            goto NhapLai;
        }
        else {
            int nhapThem = 0;
            cout << "\nSo luong may tinh muon nhap them: ";
            cin >> nhapThem;
            mayTinh[i].soLuong += nhapThem;
            cout << "\nNhap them thanh cong!";
            for (int i = 0; i < count; i++) {
                mayTinh[i].WriteToFileMayTinh("maytinhtam.txt");
            }
            remove("maytinh.txt");
            rename("maytinhtam.txt", "maytinh.txt");
        }
    }
    void MayTinh::EditMayTinh(vector<MayTinh>& mayTinh) {
        system("cls");
        string maMay;
        int pos;
    NhapLai1:
        cout << "\nNhap ma may tinh can chinh sua: ";
        cin >> maMay;
        pos = CheckTonTai(mayTinh, maMay);
        if (pos == -1) {
            cout << "May tinh nay khong ton tai. Vui long nhap lai!";
            goto NhapLai1;
        }
        else {
            int luaChon;
            string temp;
            int num;
        NhapLai2:
            system("cls");
            Show1MayTinh(mayTinh, maMay);
            cout << "\nChon thong tin can chinh sua:";
            cout << "\n1. Ten Hang";
            cout << "\n2. CPU";
            cout << "\n3. Ram";
            cout << "\n4. Disk";
            cout << "\n5. Nam san xuat";
            cout << "\n6. Xuat xu";
            cout << "\n7. Thoi gian bao hanh";
            cout << "\n8. Gia ban";
            cout << "\n-------------";
            cout << "\nNhap lua chon:";
            cin >> luaChon;
            switch (luaChon) {
            case 1:
                cout << "\nNhap ten hang:";
                cin >> temp;
                mayTinh[pos].tenHang = temp;
                break;
            case 2:
                cout << "\nNhap CPU:";
                cin >> temp;
                mayTinh[pos].cpu = temp;
                break;
            case 3:
                cout << "\nNhap dung luong ram:";
                cin >> temp;
                mayTinh[pos].ram = temp;
                break;
            case 4:
                cout << "\nNhap dung luong o cung:";
                cin >> temp;
                mayTinh[pos].disk = temp;
                break;
            case 5:
                cout << "\nNhap nam san xuat:";
                cin >> num;
                mayTinh[pos].namSX = num;
                break;
            case 6:
                cout << "\nNhap noi xuat xu:";
                cin.ignore();
                getline(cin, temp);
                mayTinh[pos].tenHang = temp;
                break;
            case 7:
                cout << "\nNhap thoi gian bao hanh:";
                cin >> num;
                mayTinh[pos].thoiGianBaoHanh = num;
                break;
            case 8:
                cout << "\nNhap gia ban:";
                cin >> num;
                mayTinh[pos].giaBan = num;
                break;
            default:
                cout << "\nSo khong hop le. Vui long nhap lai!";
                goto NhapLai2;
                break;
            }
            int chon;
            cout << "Sua doi thanh cong!";
            cout << "\nBan co muon tiep tuc chinh sua?";
            cout << "\n 1. Co"<<"\n 2. Khong"<<endl;
            cin >> chon;
            if (chon == 1) goto NhapLai2;
            for (int i = 0; i < count; i++) {
                mayTinh[i].WriteToFileMayTinh("maytinhtam.txt");
            }
            remove("maytinh.txt");
            rename("maytinhtam.txt", "maytinh.txt");
        }
    }
    void MayTinh::setMaMay(string mm)
    {
    	maMay=mm;
	}
    void MayTinh::setTenHang(string th)
    {
    	tenHang=th;
	}
    void MayTinh::setCpu(string cp)
    {
    	cpu=cp;
	}
    void MayTinh::setRam(string r)
    {
    	ram=r;
	}
    void MayTinh::setDisk(string d)
    {
    	disk=d;
	}
    void MayTinh::setNamSX(int nam)
    {
    	namSX=nam;
	}
	void MayTinh::setXuatXu(string cho)
	{
		xuatXu=cho;
	}
	void MayTinh::setGiaBan(int gia)
    {
    	giaBan=gia;
	}	
	void MayTinh::setThoiGianBaoHanh(int tg)
    {
    	thoiGianBaoHanh=tg;
	}		
    string MayTinh::getMaMay(){
		return maMay;
    }
    string MayTinh::getTenHang(){
		return tenHang;
    }
    string MayTinh::getCpu(){
		return cpu;
    }
    string MayTinh::getRam(){
		return ram;
    }
    string MayTinh::getDisk(){
		return maMay;
    }    
    int MayTinh::getNamSX(){
		return namSX;
    }
    string MayTinh::getXuatXu(){
		return xuatXu;
    }
	int MayTinh::getGiaBan(){
		return giaBan;
    }       
    int MayTinh::getThoiGianBaoHanh(){
		return thoiGianBaoHanh;
    }
    void MayTinh::setSoLuong(int sl)
    {
        soLuong = sl;
    }
    int MayTinh::getSoLuong() {
        return soLuong;
    }



