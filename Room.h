#include "Object.h"

#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <vector>
using namespace std;

class Room
{
public:
    Room();
    Room(bool,int,vector<Object*>);// Room(bool,int,vector<Object*>);//
    ~Room();
    void clearObject(Object*);

    void setUproom(Room*);
    void setDownroom(Room*);
    void setLeftroom(Room*);
    void setRightroom(Room*);
    void setIndex(int);
    void setisExit(bool);
    Room* getUproom();
    Room* getDownroom();
    Room* getLeftroom();
    Room* getRightroom();
    int getIndex();
    int getObjectsSize();
    bool getisExit();
    Object* operator[](int);
    void setObjects(vector<Object*> theobj);
    vector<Object*> getObjects();

private:
    Room *upRoom,*downRoom,*leftRoom,*rightRoom;
    bool isExit;//the last one room//
    int index;
    vector <Object*> objects;//what's in that room: monster? NPC?//
};
#endif // ROOM_H_INCLUDED
