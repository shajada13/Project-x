#ifndef ROOM_H
#define ROOM_H

void initialize_seats();
void room_menu();
void room_show();

#define FLOORS 10
#define ROOMS 5
#define SEATS 3

struct SeatData {
    long long int seat_status[FLOORS][ROOMS][SEATS]; // 0 = Available, 1 = Occupied
};

#endif // ROOM_H