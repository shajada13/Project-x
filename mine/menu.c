#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "menu.h"

void main_menu() {
    system("cls");
    box(1,1,90,5);//upper box
    box(1,6,90,12);//main box
    box(1,13,90,18);//input box
    textColor(31);

    moveXY(3, 3);  printf("Student");
    moveXY(14, 3); printf("Room");
    moveXY(22, 3); printf("Meals");
    moveXY(31, 3); printf("Payments");
    moveXY(43, 3); printf("Maintenance");
    moveXY(58, 3); printf("Visitors");
    moveXY(70, 3); printf("Reports");
    moveXY(81, 3); printf("Settings");
    
    textColor(30);
    moveXY(73,7);  printf("Input n to close");
    moveXY(40, 10);
    printf("Welcome to...");

    moveXY(30, 11);
    printf("STUDENT DORM ADMINISTRATION SYSTEM");

    resetTextColor();

}