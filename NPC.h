#include "Item.h"
#include "GameCharacter.h"

#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class NPC:public GameCharacter
{
public:
    NPC();
    NPC(string N,string script,vector<Item> product);
    void listCommodity();
    bool buyItem(Item);//??//
    bool buyItem(int);//??//
    void setScript(string script);

    bool triggerEvent(Object*);//talk to the NPC?//

    void setCommodity(string filename);
    int getCommoditysize();
    string getScript();
    vector<Item> getCommodity();
    NPC& operator=(NPC& oldobj);

private:
    string script;
    vector<Item> commodity;
};

#endif // NPC_H_INCLUDED
