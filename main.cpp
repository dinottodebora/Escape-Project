#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Room.h"
#include "Player.h"

using namespace std;

int main()
{

    srand(time(0));

    int rows = 0;
    int columns = 0;

    cout << "Controls: " << endl;
    cout << "w : up " << endl;
    cout << "a : left " << endl;
    cout << "s : down " << endl;
    cout << "d : right " << endl;

    while (rows < 3)
    {
        cout << "Enter the number of rows: ";
        cin >> rows;
        if (rows < 3)
        {
            cout << "The map requires minimum of 3 rows. Try again. " << endl;
        }
    }

    while (columns < 3)
    {
        cout << "Enter the number of columns: ";
        cin >> columns;
        if (columns < 3)
        {
            cout << "The map requires minimum of 3 columns. Try again. " << endl;
        }
    }

    Player player;
    Room room(columns, rows, &player);

    Item key('k',"key");
    room.placeItem(&key,2,2);

    Item potion('p',"potion");
    room.placeItem(&potion,4,4);

    bool isRunning = true;

    while (isRunning)
    {
        room.draw();
        char input;

        cout << endl
             << endl
             << "Type a key to move or q to quit: ";
        cin >> input;

        if (input == 'q')
        {   cout << " Done! ";
            isRunning = false;
        }
        else
        {
            player.move(input, &room);
        }
    }

    return 0;
}
