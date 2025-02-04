#include <stdio.h>

int i;
void moveXY(int x, int y);
void textColor(int code);
void resetTextColor();
void box1();
void mainBox();
void main_menu();

// ========== Main Function ==========

int main()
{
    system("color F0");
    main_menu();
    return 0;
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

void box1()
{
    moveXY(1, 3);
    printf("%c", 201);
    for(i = 1; i < 89; i++)
    {
        moveXY(i + 1, 3);
        printf("%c", 205);
    }
    moveXY(90, 3);
    printf("%c", 187);
    moveXY(1, 3);
    for (i = 4; i < 5; i++)
    {
        moveXY(1, i);
        printf("%c", 186);
    }
    moveXY(1, 5);
    printf("%c", 200);

    for(i = 1; i < 89; i++)
    {
        moveXY(i + 1, 5);
        printf("%c", 205);
    }

    moveXY(1, 9);
    for (i = 4; i < 5; i++)
    {
        moveXY(90, i);
        printf("%c", 186);
    }
    moveXY(90, 5);
    printf("%c", 188);
}

void mainBox()
{
    moveXY(1, 6);
    printf("%c", 201);
    for(i = 1; i < 89; i++)
    {
        moveXY(i + 1, 6);
        printf("%c", 205);
    }

    moveXY(90, 6);
    printf("%c", 187);
    for (i = 5; i < 40; i++)
    {
        moveXY(1, i + 2);
        printf("%c", 186);
    }

    moveXY(1, 42);
    printf("%c", 200);
    for (i = 1; i < 89; i++)
    {
        moveXY(i + 1, 42);
        printf("%c", 205);
    }

}

// ========== Main Menu ==========

void main_menu()
{
    system("cls");

    textColor(31);

    moveXY(3, 4);
    printf("S");
    moveXY(4, 4);
    printf("tudent");

    moveXY(14, 4);
    printf("R");
    moveXY(15, 4);
    printf("oom");

    moveXY(22, 4);
    printf("M");
    moveXY(23, 4);
    printf("eals");

    moveXY(31, 4);
    printf("P");
    moveXY(32, 4);
    printf("ayments");

    moveXY(43, 4);
    printf("M");
    moveXY(44, 4);
    printf("aintenance");

    moveXY(58, 4);
    printf("V");
    moveXY(59, 4);
    printf("isitors");

    moveXY(70, 4);
    printf("R");
    moveXY(71, 4);
    printf("eports");

    moveXY(81, 4);
    printf("S");
    moveXY(82, 4);
    printf("ettings");

    textColor(30);
    box1();
    mainBox();
}
