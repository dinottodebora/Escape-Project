#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Room.h"
#include "Player.h"

using namespace std;

int main(){
    
    srand(time(0));

    int rows = 0;
    int columns = 0;
    
    cout << "Controls: " << endl;
    cout << "w : up " << endl;
    cout << "a : left " << endl;
    cout << "s : down " << endl;
    cout << "d : right " << endl;

    while(rows < 3 || columns < 3) {
        cout << "Enter the number of rows: ";
        cin >> rows;
        cout << "Enter the number of columns: ";
        cin >> columns;
        if(rows < 3 || columns < 3) {
            cout << "The map requires minimum of 3 rows and 3 columns.Try again." << endl;
        }
    }

    Player player;
    Room room(columns, rows, &player);
    
    bool isRunning = true;

    while(isRunning) { 
        room.draw();
        char input;

        cout << endl << endl << "Type a key to move or q to quit: ";
        cin >> input;

        if(input == 'q') {
            isRunning = false;
        } else {
            player.move(input, &room);
        }

    }
    
    return 0;
}
  