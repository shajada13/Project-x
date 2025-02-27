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
char getch()
{
    char c = getchar();
    //putchar(c);  // Echo the character
    return c;
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

void twoline(int i)
{
    moveXY(1, i);
    printf("%c", 186); // Left T
    moveXY(90, i);
    printf("%c", 186); // Right T
}
void midline(int i)
{
    moveXY(1, i);
    printf("%c", 204); // Left T
    for(int j = 1; j < 89; j++)
    {
        moveXY(j + 1, i);
        printf("%c", 205); // Upper Horizontal Line
    }
    moveXY(90, i);
    printf("%c", 185); // Right T
}
