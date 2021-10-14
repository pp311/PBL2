#include "maytinh.h" 
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
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
		fstream file("maytinh.txt", ios::app);
        file << this->maMay << "\t" << this->tenHang << "\t" << this->cpu << "\t" << this->ram << "\t" << this->disk << "\t" << this->namSX << "\t" << this->xuatXu << "\t" << this->thoiGianBaoHanh << "\t" << this->giaBan << "\n";
        file.close();
    }
    void MayTinh::CreateMayTinh(vector<MayTinh> mayTinh)
    {
        system("cls");
		if(mayTinh.size() == mayTinh.capacity()) {
			mayTinh.reserve(mayTinh.size() + 10);
		}
		mayTinh[count++].Nhap();
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
    void MayTinh::ReadSanPham(vector<MayTinh> mayTinh){
        system("cls");
        fstream file("maytinh.txt", ios::in);
		MayTinh input;
        int i = 0;
        // file>>this->maMay>>this->tenHang>>this->cpu>>this->ram>>this->disk>>this->namSX>>this->xuatXu>>this->thoiGianBaoHanh>>this->giaBan;
        while (!file.eof())
        {
            string temp;
			if(!getline(file, input.maMay, '\t')) break; //kieu tra dong trong
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
			mayTinh.push_back(input);
            cout << "Thong tin may "<<i+1<<":" << input.maMay << " " << input.tenHang << " " << input.cpu << " " << input.ram << " " << input.disk << " " << input.xuatXu << " " << input.thoiGianBaoHanh << " " << input.giaBan << endl;
            i++;
        }
        count = i;
        file.close();
    }



