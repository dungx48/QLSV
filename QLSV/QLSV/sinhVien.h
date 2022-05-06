//
// Created by dungm on 4/19/2022.
//

#ifndef TTKTLT_SINHVIEN_H
#define TTKTLT_SINHVIEN_H

#include <iostream>
#include <string>
#include <sstream>
#include "date.h"

using namespace std;

class SinhVien {
private:
    string MaLop;
    int MaSV;
    string HoTen;
    Date NgaySinh;
    float DiemTB;

public:
    SinhVien();

    SinhVien(string MaLop, int MaSV, string HoTen, Date NgaySinh, float DiemTB);

    void ThemHoSo();

    void setMaLop(string MaLop);

    string getMaLop();

    void setMaSV(int MaSV);

    int getMaSV();

    void setHoTen(string HoTen);

    string getHoTen();

    void setNgaySinh(int Ngay, int Thang, int Nam);

    Date getNgaySinh();

    void setDiemTB(float DiemTB);

    float getDiemTB();

    string toString_SinhVien();

    friend void alo();

};

#endif //TTKTLT_SINHVIEN_H
