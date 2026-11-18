#ifndef ROOM_H
#define ROOM_H

#include "Player.h"

class Room {
    private:
        Player* player;
        char** map; // map is a variable that holds the memory address of a set of lists that hold char in it
        int width;
        int height;
    
    public:
        Room(int x, int y, Player* player);
        ~Room();
        void draw();
        bool canMove(int x, int y);

};

#endif

