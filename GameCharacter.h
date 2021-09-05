#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include "Object.h"
#include <iostream>
#include <string>

using namespace std;

class GameCharacter : public Object
{
public:
    GameCharacter();
    GameCharacter(string thename,string thetag,int attack,int defense,int thehealth);

    bool checkIsDead(); //default Dead:false//
    int takeDamage(int); // If being attacked minus Health//

    //setter & getter//
    void setAttack(int);
    void setDefense(int);
    void setmaxHealth(int);
    void setcurrentHealth(int);
    int getAttack();
    int getDefense();
    int getmaxHealth();
    int getcurrentHealth();

    GameCharacter& operator=(GameCharacter& oldobj);

private:
    int attack;
    int defense;
    int maxHealth;
    int currentHealth;
};



#endif // GAMECHARACTER_H_INCLUDED
