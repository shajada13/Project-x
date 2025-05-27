#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <../include/library.h>
#include <../include/room.h>

void graph_menu() {
    CLEAR_SCREEN();
    box1();
    moveXY(41, 2);
    printf("Graph");
    box(1, 5, 90, 9);
    box(1, 9, 90, 20);
    moveXY(1, 9);
    printf("╠");
    moveXY(90, 9);
    printf("╣");
    box(1, 21, 90, 23);

    SeatData seatdata;
    loadFromFile(&seatdata);
    int count_empty = 0;
    int count_full = 0;
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 3; k++) {
                if (seatdata.floors[i].rooms[j].seats[k].availability == 0) {
                    count_full++;
                } else {
                    count_empty++;
                }
            }
        }
    }
    moveXY(3, 14);
    printf("Total Seats: %d", count_empty + count_full);
    moveXY(3, 16);
    printf("Occupied Seats: %d", count_full);
    moveXY(3, 18);
    printf("Available Seats: %d", count_empty);

    int total = count_empty + count_full;
    int total_blocks = 44; // Total number of blocks to represent the graph

    int green_blocks = (count_empty * total_blocks) / total;
    int red_blocks = total_blocks - green_blocks;

    moveXY(2, 6);
    for (int i = 0; i < green_blocks; i++) printf("🟩");
    for (int i = 0; i < red_blocks; i++) printf("🟥");
    moveXY(2, 7);
    for (int i = 0; i < green_blocks; i++) printf("🟩");
    for (int i = 0; i < red_blocks; i++) printf("🟥");
    moveXY(2, 8);
    for (int i = 0; i < green_blocks; i++) printf("🟩");
    for (int i = 0; i < red_blocks; i++) printf("🟥");



    moveXY(10, 11);
    printf("Available 🟩 : %d (%.1f%%)", count_empty, (count_empty * 100.0) / total);
    moveXY(57, 11);
    printf("Occupied 🟥: %d (%.1f%%)", count_full, (count_full * 100.0) / total);
    moveXY(3, 22);
    printf("Press any key to go back to the main menu...");
    getch_echo();
}