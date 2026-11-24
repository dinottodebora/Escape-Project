#include <iostream>
#include <cstdlib>
#include "Room.h"
#include "Player.h"
#include "Item.h"
using namespace std;

Room::Room(int x, int y, Player *player)
{ // Player * player tracks the player

    // x is the number of rows, y is the number of columns
    this->map = new char *[y];
    this->player = player;
    this->width = x;
    this->height = y;

    for (int outerCounter = 0; outerCounter < y; outerCounter++)
    {
        this->map[outerCounter] = new char[x]; // create rows
        for (int innerCounter = 0; innerCounter < x; innerCounter++)
        { // create columns
            if (outerCounter == 0 || outerCounter == (y - 1) || innerCounter == 0 || innerCounter == (x - 1))
            {
                this->map[outerCounter][innerCounter] = '#';
            }
            else if (rand() % 8 == 0 && outerCounter > 1 && outerCounter < (y - 2) && innerCounter > 1 && innerCounter < (x - 2))
            { // create inside walls randonly
                this->map[outerCounter][innerCounter] = '#';
            }
            else
            {
                this->map[outerCounter][innerCounter] = ' ';
            }
        }
    }
}

Room::~Room()
{
    for (int outerCounter = 0; outerCounter < height; outerCounter++)
    {
        delete[] this->map[outerCounter];
    }
    delete[] this->map;
}

bool Room::canMove(int x, int y)
{
    if (map[y][x] != '#')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Room::draw()
{
    for (int outerCounter = 0; outerCounter < height; outerCounter++)
    {
        for (int innerCounter = 0; innerCounter < width; innerCounter++)
        {
            if (this->player->getX() == innerCounter && this->player->getY() == outerCounter)
            {
                cout << '@';
            }
            else
            {
                cout << this->map[outerCounter][innerCounter];
            }
        }
        cout << endl;
    }
}

void Room::placeItem(Item *i, int x, int y)
{
    this->map[y][x] = i->getId();
}

Item Room::takeItem(int x, int y)
{
    Item newItem(this->map[y][x], Item::getNameFromId(this->map[y][x]));
    this->map[y][x] = ' ';
    return newItem;
}

char Room::tileAt(int x, int y)
{
    return this->map[y][x];
}
