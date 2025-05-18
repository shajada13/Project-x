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
void box(int ulx, int uly, int brx, int bry) ;
void reset_student_data();

#define FLOORS 10
#define ROOMS 5
#define SEATS 3

typedef struct {
    int availability;  // 0 for unavailable, 1 for available
    char saved_id[100]; // Store an ID as a string
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


typedef struct {
    int day;
    int month;
    int year;
} Date;
Date addDaysToDate(Date start, int days_to_add);




#endif // LIBRARY_H