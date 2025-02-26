#include <stdio.h>
#include <stdlib.h>
#include "../include/library.h"
#include "../include/main_menu.h"
#include "../include/student.h"

int i;

void moveXY(int x, int y);
void textColor(int code);git 
void resetTextColor();
void box1();
void mainBox();
void main_menu();


// ========== Main Function ==========

int main()
{
    system("color F0");
    main_menu();
    student();
    return 0;
}



