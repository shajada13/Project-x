#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/library.h"
#include "../include/main_menu.h"
#include "../include/student.h"



// ========== Main Menu ==========

void main_menu()
{
    system("cls");

    textColor(31);

    moveXY(3, 4);
    printf("Student");
    // moveXY(4, 4);
    // printf("tudent");

    moveXY(14, 4);
    printf("R");
    moveXY(15, 4);
    printf("oom");

    moveXY(22, 4);
    printf("M");
    moveXY(23, 4);
    printf("eals");

    moveXY(31, 4);
    printf("P");
    moveXY(32, 4);
    printf("ayments");

    moveXY(43, 4);
    printf("M");
    moveXY(44, 4);
    printf("aintenance");

    moveXY(58, 4);
    printf("V");
    moveXY(59, 4);
    printf("isitors");

    moveXY(70, 4);
    printf("R");
    moveXY(71, 4);
    printf("eports");

    moveXY(81, 4);
    printf("S");
    moveXY(82, 4);
    printf("ettings");

    textColor(30);
    moveXY(40, 16);
    printf("Welcome to...");
    // textColor(36);
    moveXY(30, 17);
    printf("STUDENT DORM ADMINISTRATION SYSTEM");

    textColor(34);
    moveXY(3, 28);
    printf("Press First Charecter for further Menu... ");

    textColor(30);
    box1();
    mainBox();

    moveXY(45, 28);
    char ch = toupper(getch_echo());
    switch(ch)
    {
        case 'S': student();
        break;
    }
}
