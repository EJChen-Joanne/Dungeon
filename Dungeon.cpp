#include "Dungeon.h"
#include <fstream>
#include <vector>
#include <windows.h>

bool Dungeon::startGame_load()
{
    bool check = record.loadToFile(&player,room);
    if (check == false)//if without data in file//
    {
        cout << "Oops...Sorry..."<<endl<<"Your data is lost, let's start a new game!"<<endl<<endl;
        return false;
    }

    cout << "Welcome back, " << player.getName()<<endl;
    cout << "Let's start the game..."<<endl<<endl;
    Sleep(2000);
    //Debug//
    //cout << player.getName()<<endl;
    //player.triggerEvent(&player);
    //cout << player.getcurrentRoom()->getIndex()<<endl;
    //cout << player.getPreviousRoom()->getIndex()<<endl;
    //Debug//

    return true;

}
string Dungeon::Toupper(string a)
{
    string temp = a;
    for (unsigned int i =0;i<a.length();i++)
    {
        temp[i] = toupper(a[i]);
    }

    return temp;
}

void Dungeon::printActions(int usedNum, string actions[])
{
    string notation[5] = {"A","/B","/C","/D","/E"};
    cout << "You can choose " << endl;
    for (int i = 0;i<usedNum;i++)
    {
        cout << actions[i]<<endl;
    }
    cout << "Please choose your answer by ";
    for (int j = 0;j<usedNum;j++)
    {
         cout << notation[j];
    }
    cout << " (No matter upper/lowercase):  ";
}

void Dungeon::createPlayer()
{
    Item firstweapon("dagger",5,5,0);
    player.addItem(firstweapon);
    cout << endl;
    player.listStatus();
    cout << "   * You have a weapon named: "<< firstweapon.getName()<<endl;
}

void Dungeon::createMap()
{
    //set up the first room//
    vector <Object*> firstroom;
    NPC* vendor = new NPC("Vendor","This is a shop for whatever you want!",vector<Item>());
    vendor->setCommodity("goods_vendor.txt");

    GameCharacter *character_1 = (GameCharacter*)(vendor);
    Object *obj_room_1 = (Object*) character_1;
    firstroom.push_back(obj_room_1);
    room[0] = Room(false,0,firstroom);

    //set up the second room//
    vector<Object*> secondroom;
    Monster* Chucky = new Monster("Chucky",14,6,40);
    GameCharacter *character_2 = (GameCharacter*)(Chucky);
    Object *obj_room_2 = (Object*) character_2;
    secondroom.push_back(obj_room_2);
    room[1] = Room(false,1,secondroom);

    //set up the third room//
    vector <Object*> thirdroom;
    Item* diamond = new Item("Diamond",5,5,10);
    Object* obj_room_3 = (Object*)(diamond);
    thirdroom.push_back(obj_room_3);
    room[2] = Room(false,2,thirdroom);

    //set up the fifth room//
    vector<Object*> fourthroom;
    Monster* Pennywise = new Monster("Pennywise",30,15,60);
    GameCharacter*character_4 = (GameCharacter*)(Pennywise);
    Object*obj_room_4 = (Object*) character_4;
    fourthroom.push_back(obj_room_4);
    room[3] = Room(true,3,fourthroom);

    //create connected//
    rooms = &room[0];
    room[0].setRightroom(&room[1]);
    room[1].setLeftroom(&room[0]);
    room[1].setUproom(&room[2]);
    room[2].setDownroom(&room[1]);
    room[2].setLeftroom(&room[3]);
    room[3].setRightroom(&room[2]);
    room[3].setDownroom(&room[0]);
    player.setCurrentRoom(&room[0]);
    player.setPreviousRoom(&room[0]);

    cout <<endl;//check//
}

void Dungeon::handleMovement(Room* _room)//when need to move//
{
    while(true)
    {
        if (_room->getIndex() == 0)
       {
            string direction[] = {"A. Move right. "};
            printActions(1,direction);
            char input;
            cin >> input;
            input = toupper(input);
            if (input == 'A')
            {
                player.changeRoom(&room[1]);
                return;
            }
            else
            {
                cout << "This is incorrect direction, please try again..."<<endl;
            }
       }
       else if(_room->getIndex() == 1)
       {
           if(_room->getObjectsSize() == 0)//there is no monster now//
           {
                string direction[] = {"A. Move up","B. Move left"};
                printActions(2,direction);
                char input;
                cin >> input;
                input = toupper(input);

                if (input == 'A')
                {
                    player.changeRoom(&room[2]);
                    return;
                }
                else if (input == 'B')
                {
                    player.changeRoom(&room[0]);
                    return;
                }
                else
                {
                    cout << "This is incorrect direction, please try again..."<<endl;
                }
           }
           else
           {
                cout << "There is a ghost, you could only move to previous room..."<<endl;
                cout<<endl;
                string direction[]={"A. Move left"};
                printActions(1,direction);
                char input;
                cin >> input;
                input = toupper(input);

                if (input == 'A')
                {
                    player.changeRoom(player.getPreviousRoom());
                    return;
                }
                else
                {
                    cout << "This is incorrect direction, please try again..."<<endl;
                }
           }
       }
       else if (_room->getIndex() == 2)
       {
           string direction[] = {"A. Move down","B. Move left"};
           printActions(2,direction);
           char input;
           cin >> input;
           input = toupper(input);
           if (input == 'A')
           {
               player.changeRoom(&room[1]);
               return;
           }
           else if (input == 'B')
           {
               player.changeRoom(&room[3]);
               return;
           }
           else
           {
               cout << endl;
               cout << "This is incorrect direction, please try again..."<<endl;
           }
       }
       else if (_room->getIndex() == 3)
       {
            string direction[] = {"A. Move down","B. Move right"};
            printActions(2,direction);
            char input;
            cin >> input;
            input = toupper(input);
            if (input == 'A')
            {
                player.changeRoom(&room[0]);
                return;
            }
            else if (input == 'B')
            {
                player.changeRoom(&room[2]);
                return;
            }
            else
            {
                cout << "This is incorrect direction, please try again..."<<endl;
            }
        }
    }
}

bool Dungeon::handleRetreat()
{
    cout << "There is a ghost coming soon..."<<endl;
    cout << "You have a chance to retreat!!!"<<endl;
    cout << "If you choose to retreat, you'll be sent to the previous room."<<endl;
    cout << "Quickly! CHOOSE IT!! (input YES or NO):  ";

    string ans;
    cin >> ans;
    ans = Toupper(ans);//set all uppercase//

    if (ans == "YES")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Dungeon::chooseAction(int idx)
{
    if (idx == 0) //room[0]//
    {
        string actions[] = {"A. Move to another room","B. Check player's status","C. Talk to NPC","D. Save data & Exit"};
        printActions(4,actions);
    }

    else if (idx == 1)//room[1]//
    {
        string actions[] = {"A. Move to another room","B. Check player's status","C. Fight with Ghost","D. Save data & Exit"};
        printActions(4,actions);
    }

    else if (idx == 2)//room[2]//
    {
        string actions[] = {"A. Move to another room","B. Check player's status","C. Open the Chest","D. Save data & Exit"};
        printActions(4,actions);
    }
    else if (idx == 3)//room[3]//
    {
        string actions[] = {"A. Move to another room","B. Check player's status","C. Fight with Ghost","D. Save data & Exit"};
        printActions(4,actions);
    }
}

bool Dungeon::runDungeon()
{
    while (true)
    {
        enterRoom(player.getcurrentRoom());
        if (player.checkIsDead())
        {
            cout << endl;
            cout << "Game over..."<<endl<<endl;
            //cout << "Would you like to try again?"<<endl;
            return 0;
        }
        else if (player.getcurrentRoom()->getisExit())
        {
            if (player.getcurrentRoom()->getObjectsSize() == 0)
            {
                cout << endl;
                cout << "You win!"<<endl<<endl;
                //cout << "Want play again?"<<endl;
                return 0;
            }
        }
        else if (checkSaveGame == 1)
        {
            return 0;
        }
    }
}

void Dungeon::enterRoom(Room* room)
{
    int index = room->getIndex();
    cout << endl;
    Sleep(1000);
    cout << "|| You are in the " << "Room "<< index <<" ||"<< endl;
    cout << endl;

    if (room->getObjectsSize() != 0)
    {

        if (room->getIndex() == 0)//room[0]
        {
            handleNPCRoom(room);
        }
        else if (room->getIndex() == 1)
        {
            handleGhostRoom(room);
        }
        else if (room->getIndex() == 2)
        {
            handleChestRoom(room);
        }
        else if (room->getIndex() == 3)
        {
            handleGhostRoom(room);
        }
    }
    else
    {
        handleEmptyRoom(room);
    }
}

bool Dungeon::checkGameLogic()//game over or end or not//
{
    string check[] = {"A. Yes", "B. No"};
    while (true)
    {
        printActions(2,check);
        char input;
        input = toupper(input);
        if (input == 'A')
        {
            return true;
        }
        else if (input == 'B')
        {
            return false;
        }
        else
        {
            cout << "Incorrect choice, please try again..."<<endl;
        }
    }

}

bool Dungeon::checkMonsterRoom(vector<Object*> obj)
{
    for (unsigned int i =0;i<obj.size();i++)
    {
        if (obj[i]->getTag() == "Monster")
        {
            return true;
        }
    }
    return false;
}


void Dungeon::handleEmptyRoom(Room* _room)
{
    Sleep(1000);
    cout << "This room is empty, choose your next action: "<<endl;
    cout << endl;
    string actions[]={"A. Move to another room","B. Save your data & Exit"};
    while (true)
    {
         printActions(2,actions);
         char choice;
         cin >> choice;
         cout << endl;
         choice = toupper(choice);

         if (choice == 'A')
         {
            handleMovement(_room);
            cout << endl;
            cout << "Now you move to Room "<< player.getcurrentRoom()->getIndex()<<endl<<endl;
            return;
         }
         else if (choice == 'B')
         {
            record.saveToFile(&player,room);
            checkSaveGame = 1;
            return;
         }
         else
         {
             cout << "This is an incorrect answer, please choose again..."<<endl;
             cout << endl;
         }
    }
}

void Dungeon::handleChestRoom(Room* _room)
{
    Sleep(1000);
    cout << "You enter a room with a chest, let's take a look!"<<endl;
    cout << endl;
    int index = _room->getIndex();
    while (true)
    {
        chooseAction(index);
        char choice;
        cin >> choice;
        cout << endl;
        choice = toupper(choice);

        if (choice == 'A')
        {
            handleMovement(_room);
            cout << endl;
            cout << "Now you move to Room "<< player.getcurrentRoom()->getIndex()<<endl;
            return;
        }
        else if (choice == 'B')
        {
            player.triggerEvent(&player);
            cout << endl;
            cout << "Your checking done!"<<endl;
            return;
        }
        else if (choice == 'C')
        {
            for (auto i : (*_room).getObjects())
            {
                Item* pick = dynamic_cast<Item*>(i);
                if (pick == nullptr) continue;

                if ((*pick).triggerEvent(&player))
                {
                    (*_room).clearObject(i);
                }
                return;
            }
        }
        else if (choice == 'D')
        {
            record.saveToFile(&player,room);
            checkSaveGame = 1;
            return;
        }
        else
        {
            cout << "This is an incorrect answer, please choose again..."<<endl;
            cout << endl;
        }
    }

}

void Dungeon::handleGhostRoom(Room* _room)
{
    Sleep(1000);
    cout << "You enter a room with a ghost..."<<endl;
    cout << endl;

    int index = _room->getIndex();

     while (true)
    {
        chooseAction(index);
        char choice;
        cin >> choice;
        cout << endl;
        choice = toupper(choice);

        if (choice == 'A')
        {
            handleMovement(_room);
            cout << endl;
            cout << "Now you move to Room "<< player.getcurrentRoom()->getIndex()<<endl<<endl;
            return;
        }
        else if (choice == 'B')
        {
            player.triggerEvent(&player);
            cout << endl;
            cout << "Your checking done!"<<endl<<endl;
            return;
        }
        else if (choice == 'C')
        {
            if (handleRetreat())//wanna retreat//
            {
                player.changeRoom(player.getPreviousRoom());
                enterRoom(player.getcurrentRoom());
                return;
            }
            else
            {

                for (auto i : (*_room).getObjects())//don't retreat start fight//
                {
                    Monster* fight = dynamic_cast<Monster*>(i);
                    if (fight == nullptr) continue;

                    if ((*fight).triggerEvent(&player))
                    {
                        (*_room).clearObject(i);
                    }
                    return;
                }
            }
        }
        else if (choice == 'D')
        {
            record.saveToFile(&player,room);
            checkSaveGame = 1;
            return;
        }
        else
        {
            cout << "This is an incorrect answer, please choose again..."<<endl;
            cout << endl;
        }
    }
}

void Dungeon::handleNPCRoom(Room* _room)
{
    Sleep(1000);
    cout << "There is an NPC in this room, let's talk to him"<<endl;
    cout << endl;

    int index = _room->getIndex();

    while (true)
    {
        chooseAction(index);
        char choice;
        cin >> choice;
        cout << endl;
        choice = toupper(choice);

        if (choice == 'A')
        {
            handleMovement(_room);
            cout << endl;
            cout << "Now you move to Room "<< player.getcurrentRoom()->getIndex()<<endl<<endl;
            return;
        }
        else if (choice == 'B')
        {
            player.triggerEvent(&player);
            cout << endl;
            cout << "Your checking done!"<<endl<<endl;
            return;
        }
        else if (choice == 'C')
        {
            for (auto i : (*_room).getObjects())
            {
                NPC* talk = dynamic_cast<NPC*>(i);
                if (talk == nullptr) continue;

                (*talk).triggerEvent(&player);
                return;
            }
        }
        else if (choice == 'D')
        {
            record.saveToFile(&player,room);
            checkSaveGame = 1;
            return;
        }
        else
        {
            cout << "This is an incorrect answer, please choose again..."<<endl;
            cout << endl;
        }
    }
}
