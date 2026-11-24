#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <iostream>

class Inventory {
    private:
        int count;
        int arrayCapacity;
        Item** items;
    public:
        bool addItem(Item * i);
        void removeItem(char id);
        bool hasItem(char id);
        Inventory();
        ~Inventory();
        void printInventory();
};

#endif
