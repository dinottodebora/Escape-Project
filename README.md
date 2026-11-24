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

# Part 2
Add things to pick up to your game from Mini Project Part 1, Moving @ Around the Terminal: when the @ walks onto one, the player carries it.

Requirements

Start from your own code for Mini Project Part 1.

A few things are lying on open spaces of the map. Each is a lowercase letter, such as k for a key or c for a coin.
When the @ moves onto a thing, the player picks it up: it comes off the map and isn't drawn anymore.

The player only picks things up by moving onto them. A move into a wall picks up nothing.

After each move, the program lists what the player is carrying, in the order they were picked up.

Design

The Room gets two more member functions: placeItem takes an Item* and leaves its letter on an open space, and takeItem takes the thing at a position off the map and returns its letter, or 0 if nothing is there.

The Player's move takes the direction and the room it's moving in. The room already points at the player, so it can draw the @. The player doesn't keep a room of its own, and it never deletes one.

An Item class holds an id, a char, and a name, a std::string. A thing picked up from the map has its letter as its id. A static member function, Item::getNameFromId, gives the name for a letter, such as "key" for 'k'.

An Inventory class keeps pointers to its items in an array of Item* it allocates with new[], starting with room for 2. When it's full, it allocates an array twice as big, copies the pointers over, and releases the old array with delete[]. The items themselves don't move.

The Inventory owns its items. It can add an item made with new, remove an item by its id, which deletes it, and say whether it holds one. Its destructor deletes each item and then the array, and it's never copied: pass it by reference.

The Player owns an Inventory. After a move, it takes anything lying on its new space, makes a new Item for it with new, and adds it to the inventory.

If you started from the earlier version of this page
An earlier version of this page described a slightly different design: an item id that's a std::string, an Inventory that keeps the Items themselves in its array, and a Player that keeps a pointer to its current room, so its move takes just the direction. That design is fine too. If you built it, keep it: it meets every requirement above, and you don't need to change anything for Part 2.

Part 3's steps use the design above, so with the earlier design you'd adjust a few of them:

A std::string id: your hasItem takes a std::string, so the Player::hasItem you add in Step 6 does too. The lock's getKeyId gives the key's letter as a char, so in goThrough, turn it into a one-letter string before you ask the player: std::string keyId = ""; keyId += lock->getKeyId();. Pass tryKey the char, as Part 3 says.
A player that keeps its current room: main doesn't need a Room* of its own, because the player's room is the current room. In Step 3, placeAt takes the room too, placeAt(Room* room, int x, int y), and changes both. In Steps 4 and 5, goThrough takes just the player and the direction, gets the room from the player, and returns true if the player went through, or false where Part 3 returns the room it was given. The game loop draws the player's room.
An array of Items: nothing changes. Part 3 only asks the inventory whether it holds an id.
Don't use an LLM to write this assignment.

You can put your code in a GitHub repository, and submit the repository's link, or if you prefer you can upload your code in another way.



