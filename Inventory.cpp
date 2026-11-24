#include "Inventory.h"
#include "Item.h"
#include <iostream>


bool Inventory::addItem(Item *i)
{

    if (this->count >= this->arrayCapacity)
    {
        Item **bigger = new Item *[this->arrayCapacity * 2];
        for (int x = 0; x < this->arrayCapacity; x++)
        {
            bigger[x] = this->items[x];
        }

        delete[] items;
        this->items = bigger;

        this->arrayCapacity = this->arrayCapacity * 2;
    }

    this->items[count] = i;
    this->count += 1;

    return true;
}

void Inventory::removeItem(char id){
    bool deleted = false;
    for(int x=0; x< count;x++){
        if(this->items[x]->getId()==id){
            delete this->items[x];
            this->items[x] = nullptr;
            deleted = true;
        }
    }
    
    if(deleted == true){
        this->items[x - 1] = this->items[x];
    }
}