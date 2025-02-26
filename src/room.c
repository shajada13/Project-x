#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/library.h"
#include "../include/room.h"
struct buildingstr
{
    char building_name[100];
    int total_floors;
    int rooms_per_floor;
    int seats_per_room;
};
b1.building_name = "Building 1";
b1.total_floors = 5;    
b1.rooms_per_floor = 10;
b1.seats_per_room = 5;



// void building(){
//     struct buildingstr building;
//     FILE *fp;
//     char ch;
//     system("cls");
//     textColor(31);
//     moveXY(41, 4);
//     printf("Building");

//     textColor(30);
//     box1();

//     moveXY(35, 15);
//     printf("Building Details");
//     moveXY(35, 17);
//     printf("Add New Building");
//     moveXY(35, 19);
//     printf("Edit Building");
//     moveXY(35, 21);
//     printf("Delete Building");
//     moveXY(35, 23);
//     printf("Main Menu");
//     mainBox();

//     textColor(34);
//     moveXY(3, 30);
//     printf("Press First Charecter for further Menu... ");

//     ch = toupper(getch_echo());

//     switch (ch)
//     {
//         case 'A':
//             system("cls");
//             textColor(31);
//             moveXY(41, 4);
//             printf("Building");
//             moveXY(35, 15);
//             printf("Add New Building");
//             moveXY(35, 17);
//             printf("Building Name: ");
//             moveXY(35, 19);
//             printf("Building Address: ");
//             moveXY(35, 21);
//             printf("Building Contact: ");
//             moveXY(35, 23);
//             printf("Total Floors: ");
//             moveXY(35, 25);
//             printf("Rooms Per Floor: ");
//             moveXY(35, 27);
//             printf("Seats Per Room: ");
//             moveXY(52, 17);
//             fgets(building.building_name, 100, stdin);
//             building.building_name[strcspn(building.building_name, "\n")] = '\0';
//             moveXY(54, 19);
//             fgets(building.building_address, 100, stdin);
//             building.building_address[strcspn(building.building_address, "\n")] = '\0';
//             moveXY(54, 21);
//             fgets(building.building_contact, 50, stdin);
//             building.building_contact[strcspn(building.building_contact, "\n")] = '\0';
//             moveXY(50, 23);
//             scanf("%d", &building.total_floors);
//             moveXY(53, 25);
//             scanf("%d", &building.rooms_per_floor);
//             moveXY(52, 27);
//             scanf("%d", &building.seats_per_room);
//             fp = fopen("../data/room.dat", "a");
//             if (fp == NULL)
//             {
//                 printf("\n Can not open file!!");
//                 exit(0);
//             }
//             fwrite(&building, sizeof(building), 1, fp);
//             fclose(fp);
//             building();
//             break;
//         case 'B':
            

            
// }
// }