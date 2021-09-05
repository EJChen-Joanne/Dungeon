#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include "Player.h"
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Player;
class Room;

class Record
{
public:
    Record();
    void saveToFile(Player*,Room rooms[]);
    bool loadToFile(Player*,Room rooms[]);
private:
    void savePlayer(Player*,ofstream&);
    void saveRooms(Room rooms[],ofstream&);
    void loadPlayer(Player*,ifstream&);
    void loadRooms(Room rooms[],ifstream&);
    bool checkisempty(ifstream&,ifstream&);//helping function//
};

#endif // RECORD_H_INCLUDED
