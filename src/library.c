#include "../include/library.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int i;

char getch_echo()
{
    char c = getchar();
    //putchar(c);  // Echo the character
    return c;
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

// ========== For blinking First Letter ==========

// void blink_letter(char word[], int times, int delay)
// {
//     for (i = 0; i < times; i++)
//     {
//         if (i % 2 == 0)
//             printf("_%s\r", word + 1);
//         else   
//             printf("%s\r", word);
        
//         fflush(stdout);
//         Sleep(delay);
//     }
//     printf("\n");
// }

void animation()
{
	for (i=45; i>=1; i--)
	{
		Sleep(30);
		moveXY(1,i);
		//clreol();
	}
	for (i=1; i<=20; i++)
	{
		//clreol();
		Sleep(40);
		moveXY(1,i);
	}
}

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
    for (i = 1; i < 89; i++)
    {
        printf("%c", 205); //Horizontal Line
    }
}
void upperLine()
{   
    printf("%c", 201); // Top Left Corner
    for (i = 1; i < 89; i++)
    {
        printf("%c", 205); // Upper Horizontal Line
    }
    printf("%c", 187); // Top Right Corner
}
void lowerLine()
{
    printf("%c", 200); // Bottom Left Corner
    for (i = 1; i < 89; i++)
    {
        printf("%c", 205); // Lower Horizontal Line
    }
    printf("%c", 188); // Bottom Right Corner
}



void box(int ulx, int uly, int brx, int bry) {
    moveXY(ulx, uly);
    printf("%c", 201); // ╔ Top Left Corner
    for (int i = ulx + 1; i < brx; i++) {   
        moveXY(i, uly);
        printf("%c", 205); // ═ Upper Horizontal Line
    }
    moveXY(brx, uly);
    printf("%c", 187); // ╗ Top Right Corner
    for (int i = uly + 1; i < bry; i++) {
        moveXY(ulx, i);
        printf("%c", 186); // ║ Left Vertical Line
        moveXY(brx, i);
        printf("%c", 186); // ║ Right Vertical Line
    }
    moveXY(ulx, bry);
    printf("%c", 200); // ╚ Bottom Left Corner
    for (int i = ulx + 1; i < brx; i++) {
        moveXY(i, bry);
        printf("%c", 205); // ═ Lower Horizontal Line
    }
    moveXY(brx, bry);
    printf("%c", 188); // ╝ Bottom Right Corner
}

void reset_student_data() {
    if (remove("../data/studen.dat") == 0) {
        printf("Data file deleted successfully.\n");
    } else {
        printf("No data file found to delete.\n");
    }
}