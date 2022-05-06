#pragma once
//
// Created by dungm on 4/19/2022.
//

#ifndef TTKTLT_MENU_H
#define TTKTLT_MENU_H
#include <iostream>
#include <string>
#include "sinhVien.h"

class Menu {
private:
    int choiceMenu;
    static const string nhapsai;
    static const string baotri;

public:
    Menu();
    ~Menu();
    void hienThi();
    void sapXep();
    int algoSapXep();
    void timKiem();
    int algoTimKiem();
    int chonKhoa();
    void thongKe();
    void thoat();
};

#endif //TTKTLT_MENU_H
