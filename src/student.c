#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/library.h"
#include "../include/room.h"

void enroll();
void show();
int check_if_already_enrolled(char id[]);
void reset_student_records() ;
void remove_student();

struct stdn {
    char name[100];
    char id[100];
    char dep[50];
    int room;
    int floor;
    int seat;
    float amount;
    Date payment_date;
};

void student_menu() {
    char ch;
    do {
        system("cls");
        moveXY(41, 2);
        printf("Student");

        box1();
        moveXY(35, 15);
        printf("1. Student Details");
        moveXY(35, 17);
        printf("2. Enroll New Student");
        moveXY(35, 19);
        printf("3. Remove a Student");
        moveXY(35, 21);
        printf("4. Reset Student Records");
        moveXY(35, 23);
        printf("5. Main Menu");
        mainBox();
        lowerBox();
        moveXY(3, 37);
        printf("Press First Character for further Menu... ");
        moveXY(50, 37);
        ch = getch();

        switch (ch) {
            case 'S':
            case '1':
                show();
                break;
            case 'E':
            case '2':
                enroll();
                break;
            case 'R':
            case '3':
                remove_student();
                break;
            case 'D':
            case '4':
                reset_student_records();
                break;
            case 'Q':
            case '5':
                return;
            default:
                moveXY(3, 37);
                printf("Invalid input! Press any key to retry...   ");
                getch_echo();
        }
    } while (ch!='Q');
}


void enroll() {
    system("cls");
    box1();
    mainBox();
    lowerBox();
    moveXY(41, 2);
    printf("Enroll");

    struct stdn temp;
    FILE *fp = fopen("../data/student.dat", "ab");
    if (fp == NULL) {
        printf("\nCannot open file!!");
        getch_echo();
        return;
    }

    moveXY(35, 15);
    printf("Name :");
    moveXY(42, 15);
    fgets(temp.name, 100, stdin);
    temp.name[strcspn(temp.name, "\n")] = '\0';

    moveXY(35, 17);
    printf("ID :");
    moveXY(42, 17);
    fgets(temp.id, 100, stdin);
    temp.id[strcspn(temp.id, "\n")] = '\0';

    if (check_if_already_enrolled(temp.id)) {
        moveXY(35, 19);
        printf("ID already exists!");
        fclose(fp);
        getch_echo();
        return;
    }

    moveXY(35, 19);
    printf("Department :");
    moveXY(48, 19);
    fgets(temp.dep, 50, stdin);
    temp.dep[strcspn(temp.dep, "\n")] = '\0';

    system("cls");
    box1();
    moveXY(41, 2);
    printf("Enroll");
    room_grid();
    moveXY(3,6); printf("Name : %s",temp.name);
    moveXY(3,8); printf("ID   : %s",temp.id);
    moveXY(3,10); printf("DEP  : %s",temp.dep);

    SeatData seatdata;
    loadFromFile(&seatdata);
    int f, r, s;
    
    int day, month, year;
    float amount = 0.0;
    while (1) {
        moveXY(3,12); printf("Floor : ");
        scanf("%d", &f);
        moveXY(3,14); printf("Room : ");
        scanf("%d", &r);
        moveXY(3,16); printf("Seat : ");
        scanf("%d", &s);

        // Validate seat selection

        if (f < 1 || f > FLOORS || r < 1 || r > ROOMS || s < 1 || s > SEATS) {
            moveXY(3, 18);
            printf("Invalid floor/room/seat number! Try again.");
            continue;
        }

        // Check if the seat is available
        if (seatdata.floors[f-1].rooms[r-1].seats[s-1].availability == 0) {
            moveXY(3, 18);
            printf("Seat is already occupied! Choose another.");
            continue;
        }
        
        moveXY(3,18); printf("Day : ");
        scanf("%d", &day);
        moveXY(3,20); printf("Month : ");
        scanf("%d", &month);
        moveXY(3,22); printf("Year : ");
        scanf("%d", &year);
        if (day < 1 || day > 31 || month < 1 || month > 12 || year > 2025) {
            moveXY(3, 24);
            printf("Invalid date! Try again.");
            continue;
        }
        moveXY(3,24); printf("Payment amount : ");
        scanf("%f", &amount);
        if (amount <= 0) {
            moveXY(3, 26);
            printf("Invalid amount! Try again.");
            continue;
        }
        break;  // Exit loop if valid seat is chosen
    }
    
    // Save student details


    // Mark seat as occupied and save student ID
    seatdata.floors[f-1].rooms[r-1].seats[s-1].availability = 0;
    strcpy(seatdata.floors[f-1].rooms[r-1].seats[s-1].saved_id, temp.id);
    saveToFile(&seatdata);

    temp.floor = f;
    temp.room = r;
    temp.seat = s;
    temp.payment_date.day = day;
    temp.payment_date.month = month;
    temp.payment_date.year = year;
    temp.amount = amount;

    fwrite(&temp, sizeof(temp), 1, fp);
    fclose(fp);
    
    moveXY(3, 20);
    printf("Student enrolled successfully!");
    getch_echo();
}




#define STUDENTS_PER_PAGE 7

void show() {
    system("cls");
    box1();
    moveXY(41, 2);
    printf("Students");

    struct stdn temp;
    FILE *fp = fopen("../data/student.dat", "rb");
    if (fp == NULL) {
        printf("\nCannot open file!!");
        getch_echo();
        return;
    }

    int count = 0;
    char choice;

    while (1) {
        int studentsShown = 0;
        system("cls");
        box1();
        moveXY(41, 2);
        printf("Students");
        moveXY(1, 6);
        upperLine();

        int i = 7;

        while (studentsShown < STUDENTS_PER_PAGE && fread(&temp, sizeof(struct stdn), 1, fp) == 1) {
            moveXY(1, i);
            printf("║ Name : %-30s ", temp.name);
            moveXY(3, i+1);
            printf("ID : %-20s ", temp.id);
            moveXY(3, i+2);
            printf("Dep: %-10s ", temp.dep);
            moveXY(90, i); printf("║"); 

            moveXY(80, i);
            printf("Floor: %-2d", temp.floor);
            moveXY(80, i+1);
            printf("Room : %-2d",temp.room);
            moveXY(80, i+2);
            printf("Seat : %-2d",temp.seat);
            moveXY(1, i); printf("║"); moveXY(90, i); printf("║"); i++;

            moveXY(40, i-1);
            printf("Payment amount: %.2f ৳ ", temp.amount);
            moveXY(40, i);
            printf("Date of enrollment: %02d/%02d/%04d", temp.payment_date.day, temp.payment_date.month, temp.payment_date.year);
            moveXY(1, i); printf("║"); moveXY(90, i); printf("║"); i++;

            moveXY(40, i);
            Date temp_date = addDaysToDate(temp.payment_date, temp.amount / 100);
            printf("Last Valid Date   : %02d/%02d/%04d", temp_date.day, temp_date.month, temp_date.year);
            moveXY(1, i); printf("║"); moveXY(90, i); printf("║"); i++;

            moveXY(1, i);
            printf("╠");
            for (int j = 2; j < 90; j++) {
                moveXY(j, i);
                printf("═");
            }
            moveXY(90, i);
            printf("╣");
            i++;

            studentsShown++;
            count++;
        }

        if (studentsShown == 0) break;

        // Proper bottom corner
        i--;
        moveXY(1, i);
        printf("╚");
        for (int j = 2; j < 90; j++) {
            moveXY(j, i);
            printf("═");
        }
        moveXY(90, i);
        printf("╝");

        // Prompt
        box(1, i + 1, 90, i + 3);
        moveXY(3, i + 2);
        if (feof(fp)) {
            printf("End of list. Press Enter to exit...");
            getch_echo();
            break;
        } else {
            printf("Press 'n' for next, 'q' to quit...");
            choice = getch();
            if (choice == 'q' || choice == 'Q') break;
        }
    }

    fclose(fp);
}




int check_if_already_enrolled(char id[]) {
    FILE *fp = fopen("../data/student.dat", "rb"); // Use "rb" for reading binary files
    if (fp == NULL) {
        return 0;  // Assume no students exist
    }

    struct stdn temp;
    while (fread(&temp, sizeof(struct stdn), 1, fp) == 1) {
        if (strcmp(temp.id, id) == 0) {
            fclose(fp);
            return 1; // ID found
        }
    }

    fclose(fp);
    return 0; // ID not found
}
void remove_student() {
    system("cls");
    box1();
    mainBox();
    moveXY(41, 4);
    printf("Remove Student");

    char id[100];
    moveXY(35, 15);
    printf("Enter Student ID to remove: ");
    moveXY(65, 15);
    fgets(id, 100, stdin);
    id[strcspn(id, "\n")] = '\0'; // Remove newline

    FILE *fp = fopen("../data/student.dat", "rb");
    FILE *tempFile = fopen("../data/temp.dat", "wb");

    if (fp == NULL || tempFile == NULL) {
        printf("\nCannot open file!!");
        getch_echo();
        return;
    }

    struct stdn temp;
    int found = 0;
    SeatData seatdata;
    loadFromFile(&seatdata);

    while (fread(&temp, sizeof(struct stdn), 1, fp) == 1) {
        if (strcmp(temp.id, id) == 0) {
            found = 1;
            // Mark the seat as available again
            seatdata.floors[temp.floor - 1].rooms[temp.room - 1].seats[temp.seat - 1].availability = 1;
            strcpy(seatdata.floors[temp.floor - 1].rooms[temp.room - 1].seats[temp.seat - 1].saved_id, "");
        } else {
            fwrite(&temp, sizeof(struct stdn), 1, tempFile);
        }
    }

    fclose(fp);
    fclose(tempFile);

    if (found) {
        remove("../data/student.dat");
        rename("../data/temp.dat", "../data/student.dat");
        saveToFile(&seatdata); // Save updated room data

        moveXY(35, 17);
        printf("Student with ID %s removed successfully!", id);
    } else {
        remove("../data/temp.dat");
        moveXY(35, 17);
        printf("Student with ID %s not found!", id);
    }

    moveXY(3, 37);
    printf("Press Enter to continue...");
    getch_echo();
}

void reset_student_records() {
    system("cls");
    box1();
    mainBox();
    moveXY(41, 4);
    printf("Reset Student Records");

    moveXY(35, 15);
    printf("Are you sure you want to delete ALL student records? (Y/N)");
    
    char confirm = getch();
    if (confirm == 'Y' || confirm == 'y') {
        FILE *fp = fopen("../data/student.dat", "wb");
        if (fp != NULL) {
            fclose(fp);
            
            // Reset room data
            SeatData seatdata;
            initialize_seat(&seatdata);
            saveToFile(&seatdata);

            moveXY(35, 17);
            printf("All student records and room allocations have been deleted!");
        } else {
            moveXY(35, 17);
            printf("Error! Could not reset records.");
        }
    } else {
        moveXY(35, 17);
        printf("Operation canceled.");
    }

    moveXY(3, 37);
    printf("Press Enter to continue...");
    getch_echo();
}
