#include <stdio.h>
#include <stdlib.h>
#include "../include/library.h"
#include "../include/main_menu.h"

int i;

void moveXY(int x, int y);
void textColor(int code);
void resetTextColor();
void box1();
void mainBox();
void main_menu();


// ========== Main Function ==========

int main()
{
    system("color F0");
    main_menu();
    return 0;
}



