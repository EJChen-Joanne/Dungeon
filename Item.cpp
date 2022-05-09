#include "Item.h"

Item :: Item():Object(),attack(0),defense(0),health(0){}

Item::Item(string thename,int attack,int defense,int health):Object(thename,"Item"){

    this->health= health;
    this->attack=attack;
    this->defense=defense;
}

Item& Item::operator=(Item oldobj)
{
    Object::operator=(oldobj);

    if(this == &oldobj)
    {
        return *this;
    }
    this->setName(oldobj.getName());//?//
    attack = oldobj.attack;
    defense = oldobj.defense;
    health = oldobj.health;

    return *this;

}

void Item::setHealth(int health){

    this->health = health;
}

void Item::setAttack(int attack){

    this->attack = attack;
}

void Item::setDefense(int defense){

    this->defense = defense;
}

int Item::getHealth(){

    return this->health;
}

int Item::getAttack(){

    return this->attack;
}

int Item::getDefense(){

    return this->defense;
}

ostream& operator<<(ostream& outs,Item& item)
{
    outs << item.getName() << ",";
    outs << item.getAttack() << ",";
    outs << item.getDefense() << ",";
    outs << item.getHealth() << endl;
    return outs;
}

bool Item::triggerEvent(Object* obj)//pick up items//
 {
     Player* player = dynamic_cast<Player*> (obj);

     if (player == nullptr)
     {
         return false;
     }
     else
     {
         //Sleep(1000);
         std::this_thread::sleep_for(std::chrono::milliseconds(500));
         cout << "There is a chest, let's open it!"<<endl;
         player->addItem(*this);
         //Sleep(1500);
         std::this_thread::sleep_for(std::chrono::milliseconds(1000));
         cout << endl;
         cout << "You obtain a " << this->getName()<<endl;
         cout << "It could help you to defeat the big ghost..."<<endl << endl;
         //Sleep(500);
         std::this_thread::sleep_for(std::chrono::milliseconds(500));
         player->triggerEvent(player);
         return true;
     }
 }
