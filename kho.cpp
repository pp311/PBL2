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
        fstream file("kho.txt", ios::app);
        file << this->maSanPham << "\t" << this->soLuong << "\n";
        file.close();
    }
    void Kho::CreateKho(vector<Kho> kho)
    {
        system("cls");
        kho.resize(count + 10);
        kho[count++].Nhap();
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
    void Kho::ReadKho(vector<Kho> kho)
    {
        system("cls");
        fstream file("Kho.txt", ios::in);
        int i = 0;
        Kho input;
        while (!file.eof())
        {
            string temp;
            getline(file, input.maSanPham, '\t');
            getline(file, temp); 
            input.soLuong = atoi(temp.c_str());
            kho.push_back(input);
            cout << "San pham trong kho "<<i+1<<":" << input.maSanPham << " " << input.soLuong << endl;
            i++;
        }
        count = i;
        file.close();
    }


