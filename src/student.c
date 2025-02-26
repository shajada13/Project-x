#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/library.h"

void student()
{
    char ch;
    do
    {
        system("cls");

        textColor(31);
        moveXY(41, 4);
        printf("Student");

        textColor(30);
        box1();

        moveXY(35, 15);
        printf("Student Details");
        moveXY(35, 17);
        printf("Enroll New Student");
        moveXY(35, 19);
        printf("Unenroll Student");
        moveXY(35, 21);
        printf("Main Menu");
        mainBox();

        textColor(34);
        moveXY(3, 30);
        printf("Press First Charecter for further Menu... ");

        char ch = toupper(getch_echo());

        // For next task!
        // switch(ch)
        // {
        //   case 'A':animation();
        //        supp_entry();
        //        break;
        //   case 'U':animation();
        //        sup_update();
        //        break;
        //   case 'L':animation();
        //        supp_list();
        //        break;
        //   case 'S':search();
        //        break;
        //   case 'M':main_menu();
        //        break;
        //   default://textcolor(4+BLINK);
        //       gotoxy(11,34);
        //       printf("Plese Enter right character ONLY (A,L,U,S,M).");
        //       getch();
        // }
      }while(ch!='M');
    
}