#include "../include/library.h"
#include <stdio.h>
#include <stdlib.h>
int i;

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

void box1()
{
    moveXY(1, 3);
    printf("%c", 201); // Top Left Corner
    for(i = 1; i < 89; i++)
    {
        moveXY(i + 1, 3);
        printf("%c", 205); // Upper Horizontal Line
    }
    moveXY(90, 3);
    printf("%c", 187); // Top Right Corner
    moveXY(1, 3);
    for (i = 4; i < 5; i++)
    {
        moveXY(1, i);
        printf("%c", 186); // Left Vertical Line
    }
    moveXY(1, 5);
    printf("%c", 200); // Bottom Left Corner

    for(i = 1; i < 89; i++)
    {
        moveXY(i + 1, 5);
        printf("%c", 205); // Lower Horizontal Line
    }

    moveXY(1, 9);
    for (i = 4; i < 5; i++)
    {
        moveXY(90, i);
        printf("%c", 186); // Right Vertical Line
    }
    moveXY(90, 5);
    printf("%c", 188); // Bottom Right Corner
}

void mainBox()
{
    moveXY(1, 6);
    printf("%c", 201); // Top Left Corner
    for(i = 1; i < 89; i++)
    {
        moveXY(i + 1, 6);
        printf("%c", 205); // Upper Horizontal Line
    }

    moveXY(90, 6);
    printf("%c", 187); // Top Right Corner
    for (i = 5; i < 40; i++)
    {
        moveXY(1, i + 2);
        printf("%c", 186); // Left Vertical Line
    }

    for (i = 7; i < 42; i++)
    {
        moveXY(90, i);
        printf("%c", 186); // Right Vertical Line
    }

    moveXY(1, 42);
    printf("%c", 200); // Bottom Left Corner
    for (i = 1; i < 89; i++)
    {
        moveXY(i + 1, 42);
        printf("%c", 205); // Lower Horizontal Line
    }

    moveXY(90, 42);
    printf("%c", 188); // Bottom Right Corner

}