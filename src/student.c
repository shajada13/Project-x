#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/library.h"
void enroll();
void show();
int checkid(char id[]);
struct stdn
{
  char name[100];
  char id[100];
  char dep[50];
};
struct stdn temp1;

void student()
{
    char ch;
    
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

        ch = toupper(getch_echo());

        switch (ch)
        {
          case 'E':
                  enroll();
                  break;
          case 'S':
                  show();
                  break;
        }

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
        //       moveXY(11,34);
        //       printf("Plese Enter right character ONLY (A,L,U,S,M).");
        //       getch();
        // }
      
      
    
}
void enroll(){
    system("cls");
    box1();
    mainBox();
    textColor(31);
    moveXY(41, 4);
    printf("Enroll");
    FILE *fp;
    fp=fopen("../data/student.dat","a");
    if(fp==NULL)
	   {
      printf("\n Can not open file!!");
      exit(0);
	   }
     getchar();
     moveXY(35, 15);
     printf("Name :");
     moveXY(42, 15);
     fgets(temp1.name,100,stdin);
     temp1.name[strcspn(temp1.name, "\n")] = '\0';

     moveXY(35, 17);
     printf("ID :");
      moveXY(42, 17);
      fgets(temp1.id,100,stdin);
     if (checkid(temp1.id))
     {
          moveXY(35, 19);
          printf("ID already exists");
          student();
     }
     

     moveXY(35, 19);
     printf("dep:");
      moveXY(42, 19);
      fgets(temp1.dep,50,stdin);
      temp1.dep[strcspn(temp1.dep, "\n")] = '\0';

      fwrite(&temp1,sizeof(temp1),1,fp);
      fclose(fp);
      student();
}
void show(){
    system("cls");
    box1();
    textColor(31);
    moveXY(41, 4);
    printf("Students");
    FILE *fp;
    fp=fopen("../data/student.dat","r");
    if(fp==NULL)
     {
      printf("\n Can not open file!!");
      exit(0);
     }
    moveXY(1, 6);
    upperLine();	// Upper Horizontal Line
    
    int i=7;

    while(fread(&temp1,sizeof(temp1),1,fp)==1){
        moveXY(1, i);
        printf("%c", 186); // Left Vertical Line
        printf("    Name : %s    ",temp1.name);
        moveXY(30, i);
        printf("ID : %s    ",temp1.id);
        moveXY(60, i);
        printf("dep: %s\n",temp1.dep);
        moveXY(90, i);
        printf("%c", 186); // Right Vertical Line
        i++;
    }

    moveXY(1, i);
    lowerLine();	// Lower Horizontal Line
    fclose(fp);
    
}
int checkid(char id[])
{
    FILE *fp;
    fp=fopen("../data/student.dat","r");
    if(fp==NULL)
    {
        printf("\n Can not open file!!");
        exit(0);
    }
    while(fread(&temp1,sizeof(temp1),1,fp)==1)
    {
        if(strcmp(temp1.id,id)==0)
        {
            return 1;
        }
    }
    return 0;
    fclose(fp);    
}