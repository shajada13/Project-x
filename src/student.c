#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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


int load_all_students(struct stdn students[], int max_students) {
    FILE *fp = fopen("../data/student.dat", "rb");
    if (!fp) return 0;
    int count = 0;
    while (fread(&students[count], sizeof(struct stdn), 1, fp) == 1 && count < max_students) {
        count++;
    }
    fclose(fp);
    return count;
}

int select_student(struct stdn students[], int count) {
    CLEAR_SCREEN();
    box1();
    moveXY(40, 2);
    printf("Select Student");

    for (int i = 0, y = 5; i < count && y < 35; i++, y += 3) {
        moveXY(3, y);
        printf("%2d. %-30s  [ID: %s]", i + 1, students[i].name, students[i].id);
    }

    char input[100];
    moveXY(3, 36);
    printf("Enter index or ID to select: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    // Try index
    if (isdigit(input[0])) {
        int index = atoi(input) - 1;
        if (index >= 0 && index < count)
            return index;
    }

    // Try ID
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, input) == 0)
            return i;
    }

    moveXY(3, 38);
    printf("Student not found.");
    getch_echo();
    return -1;
}

void student_menu() {
    char ch;
    do {
        CLEAR_SCREEN();
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
    CLEAR_SCREEN();
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



    while (1)
    {
        moveXY(35, 15);
        printf("Name :");
        moveXY(42, 15);
        fgets(temp.name, 100, stdin);
        temp.name[strcspn(temp.name, "\n")] = '\0';
        if (strlen(temp.name) == 0) {
            moveXY(35, 15);
            printf("Name cannot be empty!");
            getch_echo();
            moveXY(35, 15);
            printf("                       ");

        }
        else {
            break;  // Exit loop if name is valid
        }
    }
    
    

    while(1){
        moveXY(35, 17);
        printf("ID :");
        moveXY(42, 17);
        fgets(temp.id, 100, stdin);
        temp.id[strcspn(temp.id, "\n")] = '\0';
        if (strlen(temp.id) == 0) {
            moveXY(35, 17);
            printf("ID cannot be empty!");
            getch_echo();
            moveXY(35, 17);
            printf("                       "); // Clear previous message
        } else if(check_if_already_enrolled(temp.id))
        {
            moveXY(35, 17);
            printf("ID already exists!");
            getch_echo();
            moveXY(35, 17);
            printf("                       "); // Clear previous message
        } else if (strlen(temp.id) < 2 || strlen(temp.id) > 15 || !isdigit(temp.id[0])) {
            moveXY(20, 17);
            printf("ID must be 5-15 characters long and start with a digit!");
            getch_echo();
            moveXY(20, 17);
            printf("                                                        "); // Clear previous message
        }  // Check if ID is valid
        else if (strspn(temp.id, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != strlen(temp.id)) {
            moveXY(35, 17);
            printf("ID can only contain alphanumeric characters!");
            getch_echo();
            moveXY(35, 17);
            printf("                                                        "); // Clear previous message
        }
        else if (strchr(temp.id, ' ') != NULL) {
            moveXY(35, 17);
            printf("ID cannot contain spaces!");
            getch_echo();
            moveXY(35, 17);
            printf("                                                        "); // Clear previous message
        }else {
            break;  // Exit loop if ID is valid
        }
    }


    // Get department
    while(1){
        moveXY(35, 19);
        printf("Department :");
        moveXY(48, 19);
        fgets(temp.dep, 50, stdin);
        temp.dep[strcspn(temp.dep, "\n")] = '\0';
        if (strlen(temp.dep) == 0) {
            moveXY(35, 21);
            printf("Department cannot be empty!");
            getch_echo();
            moveXY(35, 21);
            printf("                       "); // Clear previous message
        } else if (strchr(temp.dep, ' ') != NULL) {
            moveXY(35, 21);
            printf("Department cannot contain spaces!");
            getch_echo();
            moveXY(35, 21);
            printf("                                    "); // Clear previous message
        } else {
            break;  // Exit loop if department is valid
        }
    }
    

    CLEAR_SCREEN();
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

    while(1){
        moveXY(3,12); printf("Floor : ");
        scanf("%d", &f);
        if (f < 1 || f > FLOORS) {
            moveXY(3,12); printf("Invalid floor! Try again.");
            getch_echo();
            getch_echo();
           
        }else {
            break;
        }
        moveXY(3,12); printf("                                "); // Clear previous message
    }

    // Check if the floor exists

    while(1){
        moveXY(3,14); printf("Room : ");
        scanf("%d", &r);
        if (r < 1 || r > ROOMS) {
            moveXY(3,14); printf("Invalid room! Try again.");
            getch_echo();
            getch_echo();
            
        }else {
            break;
        }
        moveXY(3,14); printf("                                "); // Clear previous message
    }

    // Check if the room exists

    while (1){
        moveXY(3,16); printf("Seat : ");
        scanf("%d", &s);
        if (s < 1 || s > SEATS) {
            moveXY(3,16); printf("Invalid seat! Try again.");
        } else if(seatdata.floors[f-1].rooms[r-1].seats[s-1].availability == 0) {
            moveXY(3,16); printf("Seat is already occupied! Choose another.");
            getch_echo();
            getch_echo();
            
        }else {
            break;  // Exit loop if seat is valid
        }
        moveXY(3,16); printf("                                         "); // Clear previous message
    }
        
    while (1)
    {
        moveXY(3,18); printf("Day : ");
        scanf("%d", &day);
        moveXY(13,18); printf("Month : ");
        scanf("%d", &month);
        moveXY(23,18); printf("Year : ");
        scanf("%d", &year);
        if (day < 1 || day > 31 || month < 1 || month > 12 || year > 2025) {
        moveXY(3, 18);
        printf("Invalid date! Try again.");
        getch_echo();
        getch_echo();
        moveXY(3, 18);
        printf("                                "); // Clear previous message
        }else{
            break;  // Exit loop if date is valid
        }

    }
        // Get payment amount
        while(1){
            moveXY(3,24); printf("Payment amount : ");
            scanf("%f", &amount);
            if (amount <= 0) {
            moveXY(3, 24);
            printf("Invalid amount! Try again.");
            getch_echo();
            getch_echo();
            moveXY(3, 24);
            printf("                                "); // Clear previous message
            }else {
                break;  // Exit loop if amount is valid
            }
        
        }



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
    getch_echo();
}




#define STUDENTS_PER_PAGE 8

void show() {
    CLEAR_SCREEN();
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
        CLEAR_SCREEN();
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
    CLEAR_SCREEN();
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
    CLEAR_SCREEN();
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





int calculateDueDays(struct stdn s) {
    int days_paid = (int)(s.amount / 100);
    Date last_valid = addDaysToDate(s.payment_date, days_paid);
    time_t due_time = convertToTimeT(last_valid);
    time_t now = time(NULL);

    double diff = difftime(now, due_time);
    if (diff <= 0) return 0;

    return (int)(diff / (24 * 60 * 60));
    }

float calculateDueAmount(int due_days) {
    return due_days * 100.0f;
}



void payment_menu() {
    FILE *fp = fopen("../data/student.dat", "rb+");
    if (fp == NULL) {
        printf("Could not open file.\n");
        getch_echo();
        return;
    }

    struct stdn list[1000];
    int total = 0;

    // Load all students
    while (fread(&list[total], sizeof(struct stdn), 1, fp)) {
        total++;
    }

    int page = 0;
    char input[100];

    while (1) {
        CLEAR_SCREEN();
        box1();
        box(1, 5, 90, 23);
        box(1,24,90,38);
        moveXY(39, 2);
        printf("Payment System");

        int start = page * STUDENTS_PER_PAGE;
        int end = start + STUDENTS_PER_PAGE;
        if (end > total) end = total;
        moveXY(3, 6);
        printf("%-3s %-19s %-31s %-20s %-10s\n", "No", "ID", "Name", "Balance", "Owes");
        middleLine();
        moveXY(1, 8);
        int k = 8;
        for (int i = start; i < end; ++i) {
            int due_days = calculateDueDays(list[i]);
            float due_amount = calculateDueAmount(due_days);
            
            moveXY(3,k++);
            printf("%-3d │ %-16s │ %-28s │ %-10.2f ৳    │   %-8.2f ৳\n",
                   i, list[i].id, list[i].name, list[i].amount, due_amount);
            
            middleLine_small();
            k++;
        }
        moveXY(1, k-1);
        lowerLine();
        moveXY(3, 25);
        printf("[n] Next  [b] Back  [id] Search by ID  [index] Search by index  [back] Exit\n");
        moveXY(3, 26);
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "n") == 0) {
            if ((page + 1) * STUDENTS_PER_PAGE < total) page++;
        } else if (strcmp(input, "b") == 0) {
            if (page > 0) page--;
        } else if (strcmp(input, "id") == 0) {
            moveXY(3, 28);
            printf("Enter student ID: ");
            scanf("%s", input);
            int found = -1;
            for (int i = 0; i < total; ++i) {
                if (strcmp(list[i].id, input) == 0) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                int due_days = calculateDueDays(list[found]);
                float due_amount = calculateDueAmount(due_days);
                moveXY(3, 30);
                printf("Found: %s (%s) ",
                       list[found].name, list[found].id);
                moveXY(3, 32);
                printf("Current balance: %.2f ৳\n",list[found].amount);
                moveXY(3, 34);
                printf("Due: %.2f ৳ (%d days)",due_amount, due_days);


                float add;
                moveXY(3, 36);
                printf("Enter amount to add: ");
                scanf("%f", &add);
                list[found].amount += add;

                fseek(fp, found * sizeof(struct stdn), SEEK_SET);
                fwrite(&list[found], sizeof(struct stdn), 1, fp);
                fflush(fp);
                moveXY(50, 36);
                printf("Payment updated.");
                getch_echo();
                getch_echo();
            } else {
                moveXY(3, 30);
                printf("Student not found.");
                getch_echo();
                getch_echo();
            }
        } else if (strcmp(input, "index") == 0) {
            int index;
            moveXY(3, 28);
            printf("Enter index: ");
            scanf("%d", &index);
            if (index >= 0 && index < total) {
                int due_days = calculateDueDays(list[index]);
                float due_amount = calculateDueAmount(due_days);
                
                moveXY(3, 30);
                printf("Found: %s (%s) ",list[index].name, list[index].id);
                moveXY(3, 32);
                printf("Current balance: %.2f ৳\n",list[index].amount);
                moveXY(3, 34);
                printf("Due: %.2f ৳ (%d days)",due_amount, due_days);


                float add;
                moveXY(3, 36);
                printf("Enter amount to add: ");
                scanf("%f", &add);
                list[index].amount += add;

                fseek(fp, index * sizeof(struct stdn), SEEK_SET);
                fwrite(&list[index], sizeof(struct stdn), 1, fp);
                fflush(fp);
                moveXY(50, 36);
                printf("Payment updated.");
                getch_echo();
                getch_echo();
            } else {
                moveXY(3, 30);
                printf("Invalid index.");
                getch_echo();
                getch_echo();
            }
        } else if (strcmp(input, "back") == 0) {
            break;
        } else {
            moveXY(3, 28);
            printf("Invalid input. Try again.");
            getch_echo();
            getch_echo();
        }
    }

    fclose(fp);
}
