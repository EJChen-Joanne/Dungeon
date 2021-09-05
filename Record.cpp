#include "Record.h"
#include <fstream>

Record::Record(){}

void Record::saveToFile(Player* player,Room therooms[])
{
    ofstream playerout;
    ofstream roomout;
    playerout.open("Record_Player.txt",std::ios::out | std::ios::trunc);
    roomout.open("Record_Rooms.txt",std::ios::out | std::ios::trunc);
    if (playerout.fail() || roomout.fail())
    {
        cout << "File open failed.\n";
    }

    savePlayer(player,playerout);
    saveRooms(therooms,roomout);

    playerout.close();
    roomout.close();
}

void Record::savePlayer(Player* player,ofstream& outp)
{
      outp << player->getName() << endl;
      outp << player->getAttack() << endl;
      outp << player->getDefense()<<endl;
      outp <<player->getmaxHealth() << endl;
      outp << player->getcurrentHealth() << endl;
      outp << player->getcurrentRoom()->getIndex() << endl;
      outp <<player->getPreviousRoom()->getIndex() << endl;

      vector<Item> inventory = player->getInventory();

      outp << inventory.size()<<endl;

      for (unsigned int i =0;i<inventory.size();i++)
      {
          outp << inventory[i].getName()<<endl;
          outp << inventory[i].getAttack() << endl;
          outp << inventory[i].getDefense() << endl;
          outp << inventory[i].getHealth() << endl;
      }

      outp.close();
}

void Record::saveRooms(Room rooms[],ofstream& outr)
{
    outr << 4<<endl; //4 rooms//

    vector<Object*> goods = rooms[0].getObjects();//store the Object* in one room//

    for (unsigned int i = 0;i<4;i++)
    {
        if (rooms[i].getUproom() == nullptr)
        {
            outr << -1 << endl;
        }
        else
        {
            outr << rooms[i].getUproom()->getIndex()<<endl;
        }

        if (rooms[i].getDownroom() == nullptr)
        {
            outr << -1 << endl;
        }
        else
        {
            outr << rooms[i].getDownroom()->getIndex()<<endl;
        }
        if (rooms[i].getLeftroom() == nullptr)
        {
            outr << -1 << endl;
        }
        else
        {
            outr << rooms[i].getLeftroom()->getIndex()<<endl;
        }
        if (rooms[i].getRightroom() == nullptr)
        {
            outr << -1 << endl;
        }
        else
        {
            outr << rooms[i].getRightroom()->getIndex()<<endl;
        }

        outr << rooms[i].getIndex()<<endl;
        outr << rooms[i].getisExit()<<endl;

        goods= rooms[i].getObjects();

        if (goods.size() == 0) //empty object in the room//
        {
            outr << 0 << endl;//emtpy room//
        }
        else
        {
            outr << 1 << endl;
            outr << goods[0]->getTag()<<endl;
            outr << goods[0]->getName()<<endl;
            NPC* npc = dynamic_cast<NPC*>(goods[0]);
            Item* item = dynamic_cast<Item*>(goods[0]);
            Monster* monster = dynamic_cast<Monster*>(goods[0]);
            if (npc != 0)
            {
                outr << npc->getScript()<<endl;
              //vector<Item> commodity = npc->getCommodity();
             // outr << commodity.size()<<endl;
             // for (unsigned int j = 0;j < commodity.size(); j++)
             // {
                  //outr << commodity[j].getName()<<endl;
                //outr<<commodity[j].getAttack()<<endl;
                 // outr<<commodity[j].getDefense()<<endl;
                 // outr << commodity[j].getHealth()<<endl;
              //}
            }

            else if (item != 0)
            {
                outr << item->getAttack()<<endl;
                outr << item->getDefense()<<endl;
                outr << item->getHealth() << endl;

            }

            else if (monster != 0)
            {
                outr << monster->getAttack()<<endl;
                outr << monster->getDefense() <<endl;
                outr << monster->getcurrentHealth()<<endl;

            }
        }
    }

    outr.close();
}

bool Record::loadToFile(Player* player,Room rooms[])
{
    ifstream playerin;
    ifstream roomin;
    playerin.open("Record_Player.txt");
    roomin.open("Record_Rooms.txt");

    if (playerin.fail() || roomin.fail())
    {
        cout << "File open failed..."<<endl;
        return false;
    }

    if(checkisempty(playerin,roomin))
    {
        return false;
    }

    loadPlayer(player,playerin);
    loadRooms(rooms,roomin);

    playerin.close();
    roomin.close();

    return true;
}

bool Record::checkisempty(ifstream& _player,ifstream& _rooms)
{
    char temp;
    _player >> temp;
    if (_player.eof())
    {
        return true;//is empty//
    }
    _rooms >> temp;
    if (_rooms.eof())
    {
        return true;
    }
    return false;
}

void Record::loadPlayer(Player* player,ifstream& inputPlayer)
{
    string str;
    int temp;
    int idx;
    int length;
    char cstr[80];

    inputPlayer.seekg(0,ios::beg);

    //inputPlayer >> str;
    getline(inputPlayer,str);//?lost one char?//
    player->setName(str);
    player->setTag("Player");
    inputPlayer >> temp;//attack//
    player->setAttack(temp);
    inputPlayer >> temp;//defense//
    player->setDefense(temp);
    inputPlayer >> temp;//maxH//
    player->setmaxHealth(temp);
    inputPlayer >> temp;//currentH//
    player->setcurrentHealth(temp);

    Room* room_cur = new Room;
    Room* room_pre = new Room;
    inputPlayer >> idx;
    room_cur->setIndex(idx);
    player->setCurrentRoom(room_cur);
    inputPlayer >> idx;
    room_pre->setIndex(idx);
    player->setPreviousRoom(room_pre);

    vector <Item> inventory;
    Item item;
    inputPlayer >> length;
    for (int k = 0; k < length;k++)
    {
        inputPlayer.getline(cstr,1);
        getline(inputPlayer,str);
        item.setName(str);
        item.setTag("Item");
        inputPlayer >> temp;
        item.setAttack(temp);
        inputPlayer >> temp;
        item.setDefense(temp);
        inputPlayer >> temp;
        item.setHealth(temp);
        inventory.push_back(item);
    }

    inputPlayer.close();
}

void Record::loadRooms(Room therooms[],ifstream& inputRoom)
{
    int len;
    int temp;
    string str;
    char cstr[100];
    Room _room;

    inputRoom.seekg(0,ios::beg);
    inputRoom >> len;//roomsize//

    //for (int r = 0;r<len;r++)
    //{
        //therooms[r] = _room;
    //}//??//

    for (int t = 0; t < len;t++)
    {
        inputRoom >> temp;
        if (temp == -1)
        {
            therooms[t].setUproom(nullptr);
        }
        else{
            therooms[t].setUproom(&therooms[temp]);
        }

        inputRoom >> temp;
        if (temp == -1)
        {
            therooms[t].setDownroom(nullptr);
        }
        else{
            therooms[t].setDownroom(&therooms[temp]);
        }

        inputRoom >> temp;
        if (temp == -1)
        {
            therooms[t].setLeftroom(nullptr);
        }
        else{
            therooms[t].setLeftroom(&therooms[temp]);
        }

        inputRoom >> temp;
        if (temp == -1)
        {
            therooms[t].setRightroom(nullptr);
        }
        else
        {
            therooms[t].setRightroom(&therooms[temp]);
        }

        inputRoom >> temp;
        therooms[t].setIndex(temp);
        inputRoom >> temp;
        therooms[t].setisExit(temp);

        vector<Object*> objects; //= therooms[t].getObjects();
        inputRoom >> temp;


        if (temp > 0)//not empty room//
        {
            inputRoom.getline(cstr,1);//eat whitespace//
            //inputRoom >> str;
            getline(inputRoom,str);//check tag//
            //DEBUG::cout << "Here: " <<str<<endl;

            if (str == "NPC")
            {
                NPC* npc = new NPC;
                vector<Item> commodity;
                Item item;

                getline(inputRoom,str);
                npc->setName(str);
                npc->setTag("NPC");

                //inputRoom.getline(cstr,1);//eat white space//
                //inputRoom.getline(cstr,100);//set script//
                getline(inputRoom,str);
                npc->setScript(str);
                npc->setAttack(0);
                npc->setDefense(0);
                npc->setmaxHealth(0);
                npc->setcurrentHealth(0);

                npc->setCommodity("goods_vendor.txt");
                objects.push_back(npc);
            }

            else if (str=="Monster")
            {
                Monster *monster= new Monster;
                //inputRoom.getline(cstr, 1);
                //inputRoom.getline(cstr, 100);
                getline(inputRoom,str);
                monster->setName(str);
                monster->setTag("Monster");

                inputRoom>>temp;
                monster->setAttack(temp);
                inputRoom>>temp;
                monster->setDefense(temp);
                inputRoom>>temp;
                monster->setmaxHealth(temp);
                monster->setcurrentHealth(temp);
                objects.push_back(monster);
            }
            else if (str == "Item")
            {
                Item *item= new Item;
                //inputRoom.getline(cstr, 1);//whitespace//
                //inputRoom.getline(cstr, 100);
                getline(inputRoom,str);
                item->setName(str);
                item->setTag("Item");
                inputRoom>>temp;
                item->setAttack(temp);
                inputRoom>>temp;
                item->setDefense(temp);
                inputRoom>>temp;
                item->setHealth(temp);
                objects.push_back(item);
            }
            therooms[t].setObjects(objects);
        }
    }

    inputRoom.close();
}
