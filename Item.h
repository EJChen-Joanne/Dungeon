#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include "Object.h" //Remember inheritance implement//
#include "Player.h"
#include<iostream>
#include<string>
//#include <windows.h>
#include<thread>
#include<chrono>

using namespace std;

class Player;

class Item : public Object
{
public:
    Item();
    Item(string name,int attack,int defense,int health);

    void setHealth(int health);
    void setAttack(int attack);
    void setDefense(int defense);
    int getHealth();
    int getAttack();
    int getDefense();

    friend ostream& operator<<(ostream& outs,Item& item);
    Item& operator=(Item oldobj);

    bool triggerEvent(Object*) override;

private:
    int attack;
    int defense;
    int health;
};

#endif // ITEM_H_INCLUDED
