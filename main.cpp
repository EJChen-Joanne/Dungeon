#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
//#include <windows.h>
#include<thread>
#include<chrono>
#include "Item.h"
#include "Object.h"
#include "Dungeon.h"
#include "Player.h"
#include "GameCharacter.h"
#include "Room.h"
#include "NPC.h"
#include "Monster.h"


using namespace std;

int main()
{
    Dungeon* D;
    try
    {
        cout << endl<<endl;
        cout << "Hello, what do you want: "<<endl;
        cout << "A. Start a new game or B. Load previous data "<<endl;
        cout << "Please choose A/B:  ";
        char input;
        int flag = 0;
        while(cin >> input)
        {
            input = toupper(input);

            if (input == 'A')
            {
                throw input;
            }
            else if (input == 'B')
            {
                D = new Dungeon();
                bool check = D->startGame_load();

                if (check == false)//without data now//
                {
                    throw input;
                }
                else
                {
                    flag = 1;//open file success//
                    break;
                }
            }
            else
            {
                cout << "Incorrect choice, please choose again (A/B):  ";
            }

            if (flag == 1)
            {
                break;//leave while loop//
            }
        }
    }

    catch(...)
    {
    cout << endl<<endl;
    //Sleep(1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "Welcome to the Haunted House!" << endl;
    cout << "Watch out for the ghosts! Try to escape and stay survived..." << endl;
    cout << "Are you ready?"<< endl;
    cout << "Let's start the adventure..." << endl<<endl<<endl;
    //Sleep(2000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    cout << "What's your name:  ";
    string name;
    cin >> name;

    //Sleep(2000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << endl;
    cout << "Hello, " << name <<endl;
    Player player = Player(name,15,8,50);
    D = new Dungeon(player);
    D->createPlayer();
    D->createMap();
    //Sleep(2000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "Now you enter a room..."<<endl;

    //Sleep(1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    while(true)
    {
        int result = D->runDungeon();
        if (result == 0)
        {
            break;
        }
    }

    cout << "See ya!"<<endl;

    return 0;
}
