#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/library.h"
#include "../include/main_menu.h"
#include "../include/student.h"
#include "../include/room.h"




// ========== Main Menu ==========

void main_menu() {
    char ch;
    do{
        CLEAR_SCREEN();
        box1();
        mainBox();
        lowerBox();
        moveXY(15, 2);  printf("1");
        moveXY(12, 3); printf("Students");

        moveXY(30, 2); printf("2");
        moveXY(28, 3); printf("Enroll");

        moveXY(45, 2); printf("3");
        moveXY(43, 3); printf("rooms");

        moveXY(60, 2); printf("4");
        moveXY(57, 3); printf("Payments");

        moveXY(75, 2); printf("5");
        moveXY(73, 3); printf("Graphs");


        moveXY(40, 16); printf("Welcome to...");
        moveXY(30, 17); printf("STUDENT DORM ADMINISTRATION SYSTEM");
        

        moveXY(3, 37);printf("Enter the number of the menu you want to access...");
        
        moveXY(55, 37);
        ch =(getch());
           
        switch (ch) {
            case '1':
                student_menu();
                break;
            case '2':
                enroll();
                break;
            case '3':
                room_menu();
                break;
            case '4':
                payment_menu();
                break;
            case '5':
                graph_menu();
                break;
            default: 
                moveXY(3, 37);
                printf("Invalid input! Press any key to retry...  ");
                getch_echo();
        }
    }while (ch!='Q');
    CLEAR_SCREEN();
    return;
}
