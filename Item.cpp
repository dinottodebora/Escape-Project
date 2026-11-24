#include "Item.h"
#include <iostream>

Item::Item(char id, string name)
{
    this->id = id;
    this->name = name;
}

char Item::getId()
{
    return this->id;
}

string Item::getName()
{
    return this->name;
}

string Item::getNameFromId(char id)
{
    if (id == 'k')
    {
        return "key";
    }
    if (id == 'p')
    {
        return "potion";
    }
    else
    {
        return "N/A";
    }
}
