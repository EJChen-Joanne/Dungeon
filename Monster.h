#include "GameCharacter.h"
#include "Player.h"

#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include <string>
#include<windows.h>

using namespace std;

class Player;

class Monster : public GameCharacter
{
public:
    Monster();
    Monster(string,int,int,int);
    bool triggerEvent(Object*) override;
};


#endif // MONSTER_H_INCLUDED
