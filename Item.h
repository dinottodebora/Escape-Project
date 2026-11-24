#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;


class Item{
    private:
        char id;
        string name;
    public:
        static string getNameFromId(char id);
        Item(char id,string name);
        char getId();
        string getName();

};

#endif