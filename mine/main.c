#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "menu.h"

char x[10]="naim";
int main(){
    
    char choice;
    
    while (choice!='n')
    {
        main_menu();
        textColor(34);
        moveXY(3, 17);
        printf("Press First Character for further Menu... ");
        resetTextColor();
        moveXY(45, 17);
        scanf(" %c", &choice); 
        choice=toupper(choice);
        switch (choice)
        {
        case 'N':
            system("cls");
            return 0;
            break;
        
            
        
        default:
            break;
        }
    }
    

}