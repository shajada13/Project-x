#ifndef ROOM_H
#define ROOM_H

void room_menu();
void loadFromFile(SeatData *data);
void saveToFile(SeatData *data);
void initialize_seat(SeatData *data);

void room_grid();
void resetroomdata() ;

#endif // ROOM_H