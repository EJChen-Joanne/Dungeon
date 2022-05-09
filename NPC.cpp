#include "NPC.h"
#include <fstream>
#include <cctype>

NPC::NPC():GameCharacter()
{
    this->script = "No script";
}

NPC::NPC(string N,string script,vector<Item> product):GameCharacter(N,"NPC",0,0,0)
{
    this->script = script;
    this->commodity = product;
}

NPC& NPC::operator=(NPC& oldobj)
{
    GameCharacter::operator=(oldobj);
    if (this == &oldobj)
    {
        return *this;
    }
    this->script = oldobj.script;
    this->commodity = oldobj.commodity;

    return *this;
}

void NPC::listCommodity()
{
    for (unsigned int i =0;i<commodity.size();i++)
    {
        cout << "-"<< commodity[i];
    }
}

//bool NPC::buyItem(Item item){}

//bool NPC::buyItem(int something){}

bool NPC::triggerEvent(Object* npc)
{
    cout << "Hi! ";
    Player *player = dynamic_cast<Player*>(npc);
    if (player == nullptr)
    {
        return false;
    }

    cout << "I'm " << this->getName()<<endl;
    cout << this->script << endl;
    cout << endl;
    cout << "-Item/Attack/Defense/Health "<<endl;
    listCommodity();
    cout << endl;
    cout << "What do you want? (You can only pick one)" <<endl;
    cout << "Please enter R/B/P:  ";
    char choice;
    cin >> choice;
    choice = toupper(choice);
    Item tool;
    if (choice == 'R')//commodity[0]//
    {
        player->addItem(commodity[0]);
    }
    else if (choice == 'B')
    {
        player->addItem(commodity[1]);
    }
    else if (choice == 'P')
    {
        player->addItem(commodity[2]);
    }
    cout << endl;
    //Sleep(1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "Transaction done." << endl;
    cout << endl;
    player->triggerEvent(player);
    return true;
}

void NPC::setScript(string script)
{
    this->script = script;
}

void NPC::setCommodity(string filename)//by open file//
{
    ifstream infile;
    infile.open(filename);
    string N_name;
    int N_attack,N_defense,N_health;
    while (!infile.eof())
    {
        infile >> N_name >> N_attack >> N_defense >> N_health;
        Item N_item = Item(N_name,N_attack,N_defense,N_health);

        this->commodity.push_back(N_item);
    }

    infile.close();
}

string NPC::getScript()
{
    return this->script;
}

vector<Item> NPC::getCommodity()
{
    return this->commodity;
}

int NPC::getCommoditysize()
{
    return this->commodity.size();
}
