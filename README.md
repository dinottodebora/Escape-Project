# Part 1
Create an application that allows you to move an @ character around the terminal using the a, w, s and d keys.

Requirements

When the program starts, it asks the user how big the map should be: a number of rows and a number of columns.

The map has a wall of # characters all the way around its edge. More # characters are distributed around the inside of the map, and they act as walls too.

The @ starts on an open space. After each move, the program draws the whole map again with the @ in its new place.
w moves up, a left, s down, and d right. The @ never moves onto a #: if the next space is a wall, it stays where it is.
q quits. It's fine for the user to press Enter after each key.

Design
A Room class holds the map. The map's size isn't known until the program runs, so the Room allocates the map with new and releases it in its destructor.
The Room can draw itself, with the @ at the player's position.
A Player class holds the player's position. Its move member function takes a key and the room, and moves the player only if the space in that direction isn't a wall.
Don't use an LLM to write this assignment.


