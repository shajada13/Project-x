#ifndef LIBRARY_H
#define LIBRARY_H

char getch_echo();
void moveXY(int x, int y);
void textColor(int code);
void blink_letter(char word[], int times, int delay);
void resetTextColor();
void box1();
void mainBox();

#endif // LIBRARY_H