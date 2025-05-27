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
// void room_grid() {
//     box(1, 5, 38, 35);    // Left section
//     box(40, 5, 90, 35);   // Room grid area

//     for (int i = 50; i < 90; i += 10) {
//         moveXY(i, 5);
//         printf("╦"); // double down and horizontal

//         for (int j = 6; j < 35; j++) {
//             moveXY(i, j);
//             printf("║"); // Right Vertical Line
//         }

//         moveXY(i, 35);
//         printf("╩"); // double up and horizontal
//     }

//     for (int i = 8; i < 35; i += 3) {
//         moveXY(40, i);
//         printf("╠"); // double vertical and right

//         for (int j = 41; j < 90; j++) {
//             moveXY(j, i);

//             if (j % 10 == 0) {
//                 printf("╬"); // double vertical and horizontal
//             } else {
//                 printf("═"); // Horizontal Line
//             }
//         }

//         moveXY(90, i);
//         printf("╣"); // double vertical and left
//     }

//     loadFromFile(&seatdata);

//     for (int i = 9; i >= 0; i--) {
//         moveXY(92, (i + 1) * 3 + 3);
//         printf("Floor : %d", i + 1);

//         for (int j = 0; j < 5; j++) {
//             moveXY((j + 1) * 10 + 34, (i + 1) * 3 + 3);
//             printf("R:%d", j + 1);

//             for (int k = 0; k < 3; k++) {
//                 moveXY((j + 1) * 10 + 33 + k * 2, (i + 1) * 3 + 4);

//                 if (seatdata.floors[i].rooms[j].seats[k].availability == 0) {
//                     textColor(31); // red
//                     printf("■");
//                     textColor(0);
//                 } else {
//                     textColor(32); // green
//                     printf("■");
//                     textColor(0);
//                 }
//             }
//         }
//     }

//     moveXY(2, 36);
// }
void room_grid() {
    box(1, 5, 38, 35);    // Left section
    box(40, 5, 90, 35);   // Room grid area

    for (int i = 50; i < 90; i += 10) {
        moveXY(i, 5);
        printf("╦");

        for (int j = 6; j < 35; j++) {
            moveXY(i, j);
            printf("║");
        }

        moveXY(i, 35);
        printf("╩");
    }

    for (int i = 8; i < 35; i += 3) {
        moveXY(40, i);
        printf("╠");

        for (int j = 41; j < 90; j++) {
            moveXY(j, i);
            if (j % 10 == 0) {
                printf("╬");
            } else {
                printf("═");
            }
        }

        moveXY(90, i);
        printf("╣");
    }

    loadFromFile(&seatdata);

    // Reversed floor loop
    for (int i = 0; i < 10; i++) {
        int displayFloor = 10 - i;
        moveXY(92, (i + 1) * 3 + 3);
        printf("Floor : %d", displayFloor);

        for (int j = 0; j < 5; j++) {
            moveXY((j + 1) * 10 + 34, (i + 1) * 3 + 3);
            printf("R:%d", j + 1);

            for (int k = 0; k < 3; k++) {
                moveXY((j + 1) * 10 + 33 + k * 2, (i + 1) * 3 + 4);

                if (seatdata.floors[displayFloor - 1].rooms[j].seats[k].availability == 0) {
                    textColor(31); // red
                    printf("▣");
                    textColor(0);
                } else {
                    textColor(32); // green
                    printf("▢");
                    textColor(0);
                }
            }
        }
    }

    moveXY(2, 36);
}





void room_grid_highlight(int floor, int room, int seat) {
    box(1, 5, 38, 35);    // Left section
    box(40, 5, 90, 35);   // Room grid area

    for (int i = 50; i < 90; i += 10) {
        moveXY(i, 5);
        printf("╦");

        for (int j = 6; j < 35; j++) {
            moveXY(i, j);
            printf("║");
        }

        moveXY(i, 35);
        printf("╩");
    }

    for (int i = 8; i < 35; i += 3) {
        moveXY(40, i);
        printf("╠");

        for (int j = 41; j < 90; j++) {
            moveXY(j, i);
            if (j % 10 == 0) {
                printf("╬");
            } else {
                printf("═");
            }
        }

        moveXY(90, i);
        printf("╣");
    }

    loadFromFile(&seatdata);

    for (int i = 0; i < 10; i++) {
        int displayFloor = 10 - i;
        moveXY(92, (i + 1) * 3 + 3);
        printf("Floor : %d", displayFloor);

        for (int j = 0; j < 5; j++) {
            moveXY((j + 1) * 10 + 34, (i + 1) * 3 + 3);
            if(j+1==room && displayFloor==floor){
                moveXY((j + 1) * 10 + 31, (i + 1) * 3 + 3);
                textColor(31);
                printf("❌ R:%d ❌", j + 1);
                textColor(0);
            }else{
                printf("R:%d", j + 1);
            }

            for (int k = 0; k < 3; k++) {
                moveXY((j + 1) * 10 + 33 + k * 2, (i + 1) * 3 + 4);

                int f_idx = displayFloor - 1;
                int r_idx = j;
                int s_idx = k;

                if (displayFloor == floor && (j + 1) == room && (k + 1) == seat) {
                //textColor(33); // yellow
                printf("🟨"); // highlight
                //textColor(0);
                }
                 else if (seatdata.floors[f_idx].rooms[r_idx].seats[s_idx].availability == 0) {
                    textColor(31); // Red for occupied
                    printf("▣");
                    textColor(0);
                } else {
                    textColor(32); // Green for available
                    printf("▢");
                    textColor(0);
                }
            }
        }
    }

    moveXY(2, 36);
}





void room_menu(){
    CLEAR_SCREEN();
    box1();
    moveXY(41, 2);
    printf("Rooms");
    room_grid();
    getch_echo();
}

