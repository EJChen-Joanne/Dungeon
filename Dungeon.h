#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED
#include "Room.h"
#include "Object.h"
#include "Player.h"
#include "Item.h"
#include "NPC.h"
#include "Monster.h"
#include "GameCharacter.h"
#include "Record.h"
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Dungeon
{
public:
    Dungeon(){};
    Dungeon(Player p)
    {
        this->player = p;
    }
    bool startGame_load();
    void createPlayer();
    void createMap();
    void handleMovement(Room*);
    bool handleRetreat();
    bool checkMonsterRoom(vector<Object*>);
    void chooseAction(int);
    bool checkGameLogic();
    bool runDungeon();
    void printActions(int usedNum, string actions[]);
    void enterRoom(Room*);
    void handleEmptyRoom(Room*);
    void handleChestRoom(Room*);
    void handleGhostRoom(Room*);
    void handleNPCRoom(Room*);
    string Toupper(string);
    Room* rooms;
    Player player;
    Room room[4];//hard coded//
    Record record;
    bool checkSaveGame = 0;
};


#endif // DUNGEON_H_INCLUDED
