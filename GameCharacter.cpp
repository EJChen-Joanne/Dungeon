#include "GameCharacter.h"

GameCharacter::GameCharacter():Object(),attack(0),defense(0),maxHealth(0),currentHealth(0){}

GameCharacter::GameCharacter(string thename,string thetag,int attack,int defense,int thehealth):Object(thename,thetag)
{
    this->attack = attack;
    this->defense = defense;
    this->maxHealth = thehealth;
    this->currentHealth = thehealth;
}

void GameCharacter::setAttack(int attack)
{
    this->attack = attack;
}

void GameCharacter::setDefense(int defense)
{
    this->defense = defense;
}

void GameCharacter::setmaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}

void GameCharacter::setcurrentHealth(int currentHealth)
{
    this->currentHealth = currentHealth;
}

int GameCharacter::getAttack()
{
    return this->attack;
}

int GameCharacter::getDefense()
{
    return this->defense;
}

int GameCharacter::getmaxHealth()
{
    return this->maxHealth;
}

int GameCharacter::getcurrentHealth()
{
    return this->currentHealth;
}

bool GameCharacter::checkIsDead()
{

    if (currentHealth <= 0){
        return true;
    }
    else
    {
        return false;
    }
}

int GameCharacter::takeDamage(int beDamaged)
{
    int damage = beDamaged - this->getDefense();
    if (damage < 0)
    {
        damage = 0;
    }

    return damage;
}

 GameCharacter& GameCharacter::operator=(GameCharacter& oldobj)
 {
     Object::operator=(oldobj);
     if (this == &oldobj)
     {
         return *this;
     }
     this->setName(oldobj.getName());
     this->setTag(oldobj.getTag());
     this->attack = oldobj.attack;
     this->defense = oldobj.defense;
     this->maxHealth = oldobj.maxHealth;
     this->currentHealth = oldobj.currentHealth;

     return *this;
 }

