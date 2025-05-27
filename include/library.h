#ifndef LIBRARY_H
#define LIBRARY_H

char getch_echo();
char getch();
void moveXY(int x, int y);
void textColor(int code);
void resetTextColor();
void box1();
void mainBox();
void lowerBox();
void animation();
void line();
void upperLine();
void lowerLine();
void middleLine();
void middleLine_small();
void box(int ulx, int uly, int brx, int bry) ;
void reset_student_data();
void graph_menu();




typedef struct {
    int day;
    int month;
    int year;
} Date;

#include <time.h>

Date addDaysToDate(Date start, int days_to_add);
time_t convertToTimeT(Date d);
int checkIfDatePassed(Date target) ;



#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif



#define FLOORS 10
#define ROOMS 5
#define SEATS 3

typedef struct {
    int availability;
    char saved_id[100]; 
} Seat;


typedef struct {
    Seat seats[SEATS];
} Room;

typedef struct {
    Room rooms[ROOMS];
} Floor;

typedef struct {
    Floor floors[FLOORS];
} SeatData;


// Payment record structure

#define MAX_PAYMENTS 100


Date addDaysToDate(Date start, int days_to_add);




#endif // LIBRARY_H