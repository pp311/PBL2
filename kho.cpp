#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "kho.h"
using namespace std;

int Kho::count = 0; //so sanpham

    void Kho::Nhap()
    {
        cout << "\nNhap ma san pham: ";
        cin >> this->maSanPham;
        cout << "\nNhap so luong : ";
        cin >> this->soLuong;
    }
    void Kho::CreateKho()
    {
        system("cls");
        Nhap();
        fstream file("Kho.txt", ios::app);
        file <<this->maSanPham << "\t" << this->soLuong << "\n";
        file.close();
    }
    void Kho::setMaSanPham(string msp)
    {
    	maSanPham=msp;
	}
	void Kho::setSoLuong(int sl)
	{
		soLuong=sl;
	}
    string Kho::getMaSanPham(){
    return maSanPham;
    }
    int Kho::getSoLuong(){
    return soLuong;
    }
    void Kho::ReadKho(Kho sanPham[])
    {
        system("cls");
        fstream file("Kho.txt", ios::in);
        int i = 0;

        while (!file.eof())
        {
            string temp;
            getline(file, sanPham[i].maSanPham, '\t');
            getline(file, temp, '\t'); 
            sanPham[i].soLuong = atoi(temp.c_str());
            cout << "San pham trong kho "<<i+1<<":" << sanPham[i].maSanPham << " " << sanPham[i].soLuong << endl;
            i++;
        }
        count = i;
        file.close();
    }


