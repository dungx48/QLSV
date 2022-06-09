#include <iostream>
#include <string>
#include <Windows.h>
#include "Header/Tools.h"
#include "Header/Menu.h"

using namespace std;

int main(int argc, char** argv)
{

    Menu mainMenu;
    while (!mainMenu.HienThi()) {
    }

    system("PAUSE");
    return 0;
}

