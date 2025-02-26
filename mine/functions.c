#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "menu.h"

void moveXY(int x, int y) {
    printf("\033[%d;%dH", y, x);  // Switched row and column
}

void textColor(int code) {
    printf("\033[%dm", code);
}

void resetTextColor() {
    printf("\033[0m");
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


