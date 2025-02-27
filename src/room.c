#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <../include/library.h>
#include <../include/room.h>




struct SeatData seatData;

// Initialize all seats as available (0) and save to file
void initialize_seats() {
    FILE *fp;
    fp = fopen("../data/rooms.dat", "wb");  // Open file for writing (binary mode)
    if (fp == NULL) {
        printf("\n Cannot open file!!");
        exit(0);
    }

    // Set all seat statuses to 0 (available)
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMS; j++) {
            for (int k = 0; k < SEATS; k++) {
                seatData.seat_status[i][j][k] = 0;  // Mark seat as available
            }
        }
    }

    // Save the seat data to the file
    fwrite(&seatData, sizeof(seatData), 1, fp);

      // Close the file
}

void room_menu() {
    FILE *fp;
    fp = fopen("../data/rooms.dat", "rb");  // Open file for reading (binary mode)
    if (fp == NULL) {
        printf("\n Cannot open file!!");
        exit(0);
    }
    fread(&seatData, sizeof(seatData), 1, fp);
    seatData.seat_status[2][3][2] = 1;//randomly setting some seats as reserved
    seatData.seat_status[5][3][1] = 1;
    seatData.seat_status[7][4][0] = 1;
    seatData.seat_status[9][2][2] = 1;
    textColor(30);
    moveXY(1, 6);
    upperLine();    // Upper Horizontal Line
    
    int i = 7;
    
    for(int floor = 10;floor>0;floor--)
    {
        moveXY(1, i);

        for(int room=1;room<=5;room++)
        {
            moveXY(room*18-12, i);
            printf("Room :%d",room);
            
            moveXY(room*18, i);
            printf("%c", 179); //Vertical Line
        }
        twoline(i);
        i++;
        
        for(int room=1;room<=5;room++)
        {
            moveXY(room*18-11, i);
            int count=0;
            for(int seat=1;seat<=3;seat++)
            {
                if(seatData.seat_status[floor-1][room-1][seat-1]==0)
                {   
                    textColor(32);
                    printf("%c ",254); 
                    textColor(30);
                }
                else
                {   
                    textColor(31);
                    printf("%c ",254);
                    textColor(30);
                }
            }
            
            
            
            moveXY(room*18, i);
            printf("%c", 179); //Vertical Line
        }
        moveXY(92, i);
        printf("Floor %d",floor);
        twoline(i);
        i++;
        for(int room=1;room<=5;room++)
        {
            moveXY(room*18-13, i);
            printf("Seat 1 2 3",room);
            
            moveXY(room*18, i);
            printf("%c", 179); //Vertical Line
        }
        twoline(i);
        i++;
        moveXY(1, i);
        midline(i);
        i++;
    }
    moveXY(1, i-1);
    lowerLine();    // Lower Horizontal Line
    

    fclose(fp);
    
}

void room_show(){
    system("cls");
    box1();
    textColor(31);
    moveXY(41, 4);
    printf("Rooms");
    room_menu();
}