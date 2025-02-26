#ifndef LIBRARY_H
#define LIBRARY_H

char getch_echo();
char getch();
void moveXY(int x, int y);
void textColor(int code);
void blink_letter(char word[], int times, int delay);
void resetTextColor();
void box1();
void mainBox();
void animation();
void line();
void upperLine();
void lowerLine();
void twoline(int i);
void midline(int i);

#endif // LIBRARY_H