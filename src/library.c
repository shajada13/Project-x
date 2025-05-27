#include "../include/library.h"
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <time.h>
#include <string.h>

char getch_echo()
{
    char c = getchar();
    //putchar(c);  // Echo the character
    return c;
}


int get_input(const char *prompt, char *output) {
    printf("%s", prompt);
    fgets(output, 100, stdin);
    output[strcspn(output, "\n")] = '\0';  // Remove newline

    if (strcmp(output, "back") == 0) return -1;
    if (strcmp(output, "quit") == 0) return -2;
    return 0;
}


char getch() {
    char buffer[10];  // Extra space to catch extra input
    char choice;

    // Get the input as a string (fgets handles buffer overflow and newlines)
    if (fgets(buffer, sizeof(buffer), stdin)) {
        sscanf(buffer, " %c", &choice);  // Extract the first non-whitespace char
        return toupper(choice);
    }
    return '\0';  // Return null character if fgets fails
}

// ========== Cursor Moving Function ==========

void moveXY(int x, int y)
{
    printf("\033[%d;%dH", y, x); 
}

// ========== For Text Colour ==========

void textColor(int code)
{
    printf("\033[%dm", code);
}

void resetTextColor()
{
    printf("\033[0m");
}

// ========== Box Drawing Functions ==========

void box1()
{
    box(1,1,90,4);
}

void mainBox()
{
    box(1,5,90,35);
    
}


void lowerBox(){
    box(1,36,90,38);
}


void line()
{
    for (int i = 1; i < 89; i++)
    {
        printf("═"); //  Horizontal Line
    }
}

void upperLine()
{   
    printf("╔"); // Top Left Corner
    for (int i = 1; i < 89; i++)
    {
        printf("═"); //  Horizontal Line
    }
    printf("╗"); // Top Right Corner
}
void middleLine()
{
    printf("╠"); // Middle Left Corner
    for (int i = 1; i < 89; i++)
    {
        printf("═"); // Middle Horizontal Line
    }
    printf("╣"); // Middle Right Corner
}
void middleLine_small()
{
    printf("╟"); // Middle Left Corner
    for (int i = 1; i < 89; i++)
    {
        printf("─"); // Middle Horizontal Line
    }
    printf("╢"); // Middle Right Corner
}

void lowerLine()
{
    printf("╚"); // Bottom Left Corner
    for ( int i = 1; i < 89; i++)
    {
        printf("═"); // Lower Horizontal Line
    }
    printf("╝"); // Bottom Right Corner
}


void box(int ulx, int uly, int brx, int bry) {
    moveXY(ulx, uly);
    printf("╔"); // Top Left Corner
    for (int i = ulx + 1; i < brx; i++) {   
        moveXY(i, uly);
        printf("═"); // Upper Horizontal Line
    }
    moveXY(brx, uly);
    printf("╗"); // Top Right Corner

    for (int i = uly + 1; i < bry; i++) {
        moveXY(ulx, i);
        printf("║"); // Left Vertical Line
        moveXY(brx, i);
        printf("║"); // Right Vertical Line
    }

    moveXY(ulx, bry);
    printf("╚"); // Bottom Left Corner
    for (int i = ulx + 1; i < brx; i++) {
        moveXY(i, bry);
        printf("═"); // Lower Horizontal Line
    }
    moveXY(brx, bry);
    printf("╝"); // Bottom Right Corner
}


void reset_student_data() {
    if (remove("../data/studen.dat") == 0) {
        printf("Data file deleted successfully.\n");
    } else {
        printf("No data file found to delete.\n");
    }
}



Date addDaysToDate(Date start, int days_to_add) {
    struct tm t = {0};
    t.tm_mday = start.day;
    t.tm_mon = start.month - 1;
    t.tm_year = start.year - 1900;

    // Convert to time_t
    time_t base_time = mktime(&t);

    // Add the number of seconds in the given number of days
    base_time += (time_t)days_to_add * 24 * 60 * 60;

    // Convert back to struct tm
    struct tm *result_time = localtime(&base_time);

    Date result;
    result.day = result_time->tm_mday;
    result.month = result_time->tm_mon + 1;
    result.year = result_time->tm_year + 1900;

    return result;
}

// Converts Date to time_t
time_t convertToTimeT(Date d) {
    struct tm t = {0};
    t.tm_mday = d.day;
    t.tm_mon = d.month - 1;
    t.tm_year = d.year - 1900;
    return mktime(&t);
}

// Compares a date to today's date
// Returns: -1 (past), 0 (today), 1 (future)
int checkIfDatePassed(Date target) {
    // Get today's date
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    Date today = {local->tm_mday, local->tm_mon + 1, local->tm_year + 1900};

    time_t target_time = convertToTimeT(target);
    time_t today_time = convertToTimeT(today);

    double diff = difftime(target_time, today_time);

    if (diff < -86400)  // More than 1 day ago
        return -1;
    else if (diff > 86400)  // More than 1 day in future
        return 1;
    else
        return 0;  // Within the same day (±1 day tolerance)
}

