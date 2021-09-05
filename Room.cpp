#include "Room.h"

Room::Room()
{
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
    isExit = false;
    index = 0;
}

Room::Room(bool isExit,int index,vector<Object*> Obj)
{
    this->isExit = isExit;
    this->index = index;
    this->objects = Obj;
    upRoom = nullptr;
    downRoom = nullptr;
    leftRoom = nullptr;
    rightRoom = nullptr;
}

void Room::clearObject(Object* theobj)
{
    for (unsigned int i = 0; i<objects.size();i++)
    {
        if (objects[i] == theobj)//with the same object//
        {
            for (unsigned int j = i;j<objects.size();j++)
            {
                objects[j] = objects[j+1];
            }
            objects.pop_back();
        }
    }
}

Room::~Room()
{
    objects.clear();
    delete upRoom;
    delete downRoom;
    delete leftRoom;
    delete rightRoom;
}

void Room::setUproom(Room* up)
{
    this->upRoom = up;//*upRoom?//
}

void Room::setDownroom(Room *down)
{
    this->downRoom = down;
}
void Room::setLeftroom(Room *left)
{
    this->leftRoom = left;
}
void Room::setRightroom(Room *right)
{
    this->rightRoom = right;
}
void Room::setIndex(int n)
{
    this->index = n;
}
void Room::setisExit(bool exit)
{
    this->isExit = exit;
}
Room* Room::getUproom()
{
    return this->upRoom;
}
Room* Room::getDownroom()
{
    return this->downRoom;
}
Room* Room::getLeftroom()
{
    return this->leftRoom;
}
Room* Room::getRightroom()
{
    return this->rightRoom;
}
int Room::getIndex()
{
    return this->index;
}

int Room::getObjectsSize()
 {
     return this->objects.size();
 }

 bool Room::getisExit()
 {
     return this->isExit;
 }

 void Room::setObjects(vector<Object*> theobj)
 {
     this->objects = theobj;
 }

 Object* Room::operator[](int index)
 {
     return this->objects[index];
 }

 vector<Object*> Room::getObjects()
 {
     return this->objects;
 }
