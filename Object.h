#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include<string>
#include<iostream>

using namespace std;

class Object{
public:
    Object();
    Object(string name,string tag);
    void setName(string name);
    string getName();
    void setTag(string tag);
    string getTag();
    virtual bool triggerEvent(Object*)=0;//?//
    Object& operator=(Object& oldobj);

private:
    string tag;
    string name;
};


#endif // OBJECT_H_INCLUDED
