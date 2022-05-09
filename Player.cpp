#include "Player.h"

Player::Player():GameCharacter(){}

Player::Player(string thename,int theattack,int thedefense,int thehealth):GameCharacter(thename,"Player",theattack,thedefense,thehealth)
{
    this->currentRoom = nullptr;
    this->previousRoom = nullptr;
}
void Player::addItem(Item item) //when getting new Item//
{
    inventory.push_back(item);
    increaseStates(item.getAttack(),item.getDefense(),item.getHealth());
}
void Player::increaseStates(int A,int D,int H)
{
    int att_temp = getAttack();
    att_temp += A;
    setAttack(att_temp);
    int def_temp = getDefense();
    def_temp += D;
    setDefense(def_temp);
    int maxH_temp = getmaxHealth();
    maxH_temp += H;
    setmaxHealth(maxH_temp);
    int curH_temp = getcurrentHealth();
    curH_temp += H;
    setcurrentHealth(curH_temp);
}

void Player::changeRoom(Room* nowRoom)
{
    this->previousRoom = this->currentRoom;
    this->currentRoom = nowRoom;
}

bool Player::triggerEvent(Object* player)
{
    if (player == nullptr)
    {
        return false;
    }
    else
    {
        //Sleep(1000);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << endl;
        cout << "   * Your status: "<<endl;
        cout << "   * Value of attack: " << this->getAttack()<< endl;
        cout << "   * Value of defense: " << this->getDefense() << endl;
        cout << "   * Value of Health: " << this->getcurrentHealth() << " / "<< this->getmaxHealth() << endl<<endl;
    }
    return true;
}

void Player::setCurrentRoom(Room* newRoom)
{
    this->currentRoom = newRoom;
}
void Player::setPreviousRoom(Room* oldRoom)
{
    this->previousRoom = oldRoom;
}

Room* Player::getcurrentRoom()
{
    return currentRoom;
}
Room* Player::getPreviousRoom()
{
    return previousRoom;
}

void Player::listStatus()
{
    cout << "   * Your status: "<<endl;
    cout << "   * Value of attack: " << this->getAttack()<< endl;
    cout << "   * Value of defense: " << this->getDefense() << endl;
    cout << "   * Value of Health: " << this->getcurrentHealth() << " / "<< this->getmaxHealth() << endl;
}

vector<Item> Player::getInventory()
{
    return this->inventory;
}
