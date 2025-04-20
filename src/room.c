#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <../include/library.h>
#include <../include/room.h>

SeatData seatdata;

void initialize_seat(SeatData *data) {
    for (int f = 0; f < FLOORS; f++) {
        for (int r = 0; r < ROOMS; r++) {
            for (int s = 0; s < SEATS; s++) {
                data->floors[f].rooms[r].seats[s].availability = 1; // Default available
                strcpy(data->floors[f].rooms[r].seats[s].saved_id, ""); // Empty ID
            }
        }
    }
}
void saveToFile(SeatData *data) {
    FILE *file = fopen("../data/rooms.dat", "wb");
    if (!file) {
        printf("Error saving data.\n");
        return;
    }
    fwrite(data, sizeof(SeatData), 1, file);
    fclose(file);
}

void loadFromFile(SeatData *data) {
    FILE *file = fopen("../data/rooms.dat", "rb");
    if (!file) {
        printf("No existing data found. Initializing...\n");
        initialize_seat(data);
        return;
    }
    fread(data, sizeof(SeatData), 1, file);
    fclose(file);
}
void resetroomdata() {
    if (remove("../data/rooms.dat") == 0) {
        printf("Data file deleted successfully.\n");
    } else {
        printf("No data file found to delete.\n");
    }
}
void printSeats(SeatData *data) {
    for (int f = 0; f < FLOORS; f++) {
        for (int r = 0; r < ROOMS; r++) {
            for (int s = 0; s < SEATS; s++) {
                printf("Floor %d, Room %d, Seat %d - Availability: %d, ID: %s\n",
                    f + 1, r + 1, s + 1,
                    data->floors[f].rooms[r].seats[s].availability,
                    data->floors[f].rooms[r].seats[s].saved_id);
            }
        }
    }
}
void room_grid(){
    box(1,5,38,35);
    box(40,5,90,35);
    for(int i = 50;i<90;i=i+10){
        moveXY(i,5);
        printf("%c",203); // ╦	double down and horizontal
        for(int j=6;j<35;j++){
            moveXY(i,j);
            printf("%c", 186); // ║ Right Vertical Line
        }
        moveXY(i,35);
        printf("%c",202); // ╩	double up and horizontal

    }
    for(int i = 8;i<35;i=i+3){
        moveXY(40,i);
        printf("%c",204); // ╠	double vertical and right
        for(int j = 41;j<90;j++){
            moveXY(j,i);
            
            if(j%10==0){
                printf("%c", 206); // ╬	double vertical and horizontal
            }else{
                printf("%c", 205); // ═ Horizontal Line
            }
        }
        moveXY(90,i);
        printf("%c",185); // ╣	double vertical and left
    }
    loadFromFile(&seatdata);
    
    for(int i = 9;i>=0;i--)
    {   
        moveXY(92,(i+1)*3+3);
        printf("Floor : %d",i+1);
        for (int j = 0; j < 5; j++)
        {   
            moveXY((j+1)*10+34,(i+1)*3+3);
            printf("R:%d",j+1);
            for (int k = 0; k < 3; k++)
            {   
                
                moveXY((j+1)*10+32+k*2,(i+1)*3+4);
                if(seatdata.floors[i].rooms[j].seats[k].availability==0){
                    textColor(31);
                    printf(" %c",254); //	■	 square
                    textColor(0);
                }else{
                    textColor(32);
                    printf(" %c",254); //	■	 square
                    textColor(0);
                }
                
            }
            
        }
        
    }
    moveXY(2, 36);
}
void room_menu(){
    system("cls");
    box1();
    moveXY(41, 2);
    printf("Rooms");
    room_grid();
    getch_echo();
}

