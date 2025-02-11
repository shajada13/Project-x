#include <stdio.h>
#include <stdlib.h>
#include "../include/library.h"
#include "../include/main_menu.h"

int i;

// ========== Main Menu ==========

void main_menu()
{
    system("cls");

    textColor(31);

    moveXY(3, 4);
    printf("S");
    moveXY(4, 4);
    printf("tudent");

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
    box1();
    mainBox();
}
