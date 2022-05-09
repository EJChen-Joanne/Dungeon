#include "Room.h"
#include "Item.h"
#include "GameCharacter.h"

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <vector>
//#include <windows.h>
#include<thread>
#include<chrono>

using namespace std;
typedef Room* RoomPtr;

class Item;

class Player: public GameCharacter
{
public:
    Player();
    Player(string thename,int theattack,int thedefense,int thehealth);
    void addItem(Item item); //when getting new Item//
    void increaseStates(int A,int D,int H);

    bool triggerEvent(Object*) override;

    void changeRoom(Room*);
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    Room* getcurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();

    void listStatus();

private:
    RoomPtr currentRoom,previousRoom;
    vector <Item> inventory;//hold the tools//
};


#endif // PLAYER_H_INCLUDED
