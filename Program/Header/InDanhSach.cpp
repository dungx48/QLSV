#include "InDanhSach.h"

InDanhSach::InDanhSach()
{
}

InDanhSach::InDanhSach(vector<SinhVien> &_DanhSach)
{
    DanhSach = _DanhSach;
}

void InDanhSach::importData()
{
    SinhVien temp;
    fstream dataInput;
    dataInput.open("data.txt", ios::in | ios::out);
    if (dataInput.peek() == EOF) {
        cout << "Ho so rong!\n";
        return;
    }
    while (!dataInput.eof()) {
        temp.importData(dataInput, temp);
        DanhSach.push_back(temp);
    }
}

void InDanhSach::printData()
{
    int n = DanhSach.size();
    for (int i=0; i<n; i++) {
        DanhSach[i].toScreen_SinhVien();
//        cout << endl;
    }
}

void InDanhSach::printListStudent() {
    cout << titleM2 << endl;
    string s;
//    cout << DanhSach[0].getMaSV();
    for (int i = 0; i < DanhSach.size(); ++i) {
        s = "|" + centerString(DanhSach[i].getMaLop(), 12) + "|"
            + centerStringint(DanhSach[i].getMaSV(), 18) +
            "|" + centerString(DanhSach[i].getHoTen(), 24) + "|" +
            centerString(DanhSach[i].toString_NgaySinh(), 14) + "|"
            + centerStringfloat(DanhSach[i].getDiemTB(), 10) + "|\n" ;
        printM2.push_back(midLineM2);
        printM2.push_back(s);
        cout << s;
    }
    cout << endLineM2;
    printM2.push_back(endLineM2);
    system("PAUSE");
}

string InDanhSach::centerString(string s, int space) {
    int length = s.length();
    int size = (space - length) / 2;
//    cout << "s: " << size;
//    stringstream stringstream1;
    string string1;

    for (int i=0; i<size; i++) {
        string1 += " ";
    }
    string1 += s;
    if (length%2 == 0) {
        for (int i = 0; i < size; i++) {
            string1 += " ";
        }
    }
    else {
        for (int i = 0; i < size+1; i++) {
            string1 += " ";
        }
    }
    return string1;
}

string InDanhSach::centerStringint(int input, int space) {
    int length = 0;
    int s = input;
//    cout << input;
    if (input == 0)
        length = 1;
    while (s > 0) {
        s = s / 10;
        length++;
    }
//    cout << length;
//    cout << s;
    stringstream ss;
    ss << input;
    string temp;
    ss >> temp;
    int size = (space - length) / 2;
    string string1;
    for (int i=0; i<size; i++) {
        string1 += " ";
    }
    string1 += temp;
    if (length%2 == 0) {
        if (space%2 != 0)
            size += 1;
        for (int i = 0; i < size; i++) {
            string1 += " ";
        }
    }
    else {
        if (space%2 != 0)
            size -= 1;
        for (int i = 0; i < size+1; i++) {
            string1 += " ";
        }
    }
//    cout << string1;
    return string1;
}

string InDanhSach::centerStringfloat(float input, int space) {
    ostringstream strInput;
    strInput.precision(2);
    strInput << fixed << input;
    string temp = strInput.str();
    int length = temp.length();

    int size = (space - length) / 2;
    string string1;
    for (int i=0; i<size; i++) {
        string1 += " ";
    }
    string1 += temp;
    if (length%2 == 0) {
        if (space%2 != 0) {
            size += 1;
        }
        for (int i = 0; i < size; i++) {
            string1 += " ";
        }
    }
    else {
        if (space%2 != 0) {
            size -= 1;
        }
        for (int i = 0; i < size+1; i++) {
            string1 += " ";
        }
    }

    return string1;
}

vector<SinhVien> InDanhSach::getData()
{
    return DanhSach;
}

void InDanhSach::ask()
{
    cout << "Ban co muon sap xep truoc khi in? (y/n): ";
    char ans;
    try {
        cin >> ans;
    }
    catch (exception e) {
        ask();
    }
    if (ans == 'y') {
        importData();
//        system("CLS");
        SapXep sapXep(DanhSach);
        sapXep.ChonKhoa();
        printListStudent();
    }
    else {
//        system("CLS");
        importData();
        printListStudent();
    }
}

void InDanhSach::askSearch(vector<SinhVien> &_DanhSach, int keyType)
{
    SapXep sortFirst(_DanhSach);
    sortFirst.selectionSort(_DanhSach, keyType);
}

void InDanhSach::setData(vector<SinhVien> _DanhSach)
{
    DanhSach = _DanhSach;
}