#include "Monster.h"

Monster::Monster():GameCharacter(){}

Monster::Monster(string Mon_name,int Mon_attack,int Mon_defense,int Mon_health):GameCharacter(Mon_name,"Monster",Mon_attack,Mon_defense,Mon_health)
{
}

bool Monster::triggerEvent(Object* obj)
{
    Player *player = dynamic_cast<Player*>(obj);

    if (player == nullptr)
    {
        return false;
    }

    while(true){
        //Sleep(1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << endl <<endl;
        cout << "You start attacking..."<<endl;

        int mon_damage = this->takeDamage(player->getAttack());

        //Sleep(1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Your attack occurs " << mon_damage << " damage" <<endl;
        int mon_temp_health = this->getcurrentHealth()-mon_damage;
        if (mon_temp_health < 0)
        {
            mon_temp_health = 0;
        }
        this->setcurrentHealth(mon_temp_health);
        cout << this->getName() << "'s current health is " << this->getcurrentHealth()<<endl;


        if (this->checkIsDead())
        {
            //Sleep(1000);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout <<endl<<endl;
            cout << "------The ghost has been defeated------" << endl<<endl;
            return true;
        }

        //Sleep(1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "You're attacked by "<<this->getName()<<endl;
        int your_damage = player->takeDamage(this->getAttack());
        //Sleep(1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << this->getName() << "'s attack occurs " << your_damage << " damage"<<endl;
        int temp_health = player->getcurrentHealth()-your_damage;
        if (temp_health < 0)
        {
            temp_health = 0;
        }
        player->setcurrentHealth(temp_health);
        //Sleep(500);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << endl;
        player->triggerEvent(player);

        if (player->checkIsDead())
        {
            //Sleep(1000);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            cout <<endl<<endl;
            cout << "------You are dead------"<<endl<<endl;
            return true;
        }
    }
}
