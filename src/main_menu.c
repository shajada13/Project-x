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
        system("cls");
        box1();
        mainBox();
        lowerBox();
        moveXY(6, 2);  printf("1");
        moveXY(3, 3); printf("Student");

        moveXY(16, 2); printf("2");
        moveXY(14, 3); printf("Room");

        moveXY(24, 2); printf("3");
        moveXY(22, 3); printf("Graph");

        moveXY(35, 2); printf("5");
        moveXY(31, 3); printf("Payments");

        moveXY(48, 2); printf("6");
        moveXY(43, 3); printf("Maintenance");

        moveXY(62, 2); printf("7");
        moveXY(58, 3); printf("Visitors");

        moveXY(73, 2); printf("8");
        moveXY(70, 3); printf("Reports");

        moveXY(84, 2); printf("9");
        moveXY(81, 3); printf("Setting");

        moveXY(40, 16); printf("Welcome to...");
        moveXY(30, 17); printf("STUDENT DORM ADMINISTRATION SYSTEM");
        

        moveXY(3, 37);printf("Enter the number of the menu you want to access...");
        
        moveXY(55, 37);
        ch =(getch());
           
        switch (ch) {
            case 'S':
            case '1':
                student_menu();
                break;
            case 'R':
            case '2':
                room_menu();
                break;
            case '3':
                graph_menu();
                break;
            default: 
                moveXY(3, 37);
                printf("Invalid input! Press any key to retry...  ");
                getch_echo();
        }
    }while (ch!='Q');
    system("cls");
    return;
}
