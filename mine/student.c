#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "menu.h"
#include "student.h"

void student(){
    system("cls");
    box(1,1,90,5);//upper box
    box(1,6,90,12);//main box
    box(1,13,90,18);//input box
    textColor(31);
    moveXY(43, 2); printf("Student >>");
    moveXY(31, 3); printf("Register new");
    moveXY(58, 3); printf("Show all");
    

}