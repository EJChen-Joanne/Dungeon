#include "Object.h"

Object::Object()
{
    name = "Name";
    tag = "tag";
}

Object::Object(string name,string tag)
{
    this->name = name;
    this->tag = tag;
}

void Object::setName(string name)
{
    this->name = name;
}

void Object::setTag(string tag)
{
    this->tag = tag;
}

string Object::getName()
{
    return this->name;
}

string Object::getTag()
{
    return this->tag;
}

Object& Object::operator=(Object& oldobj)
{
    if (this == &oldobj)
    {
        return *this;
    }
    name = oldobj.name;
    tag = oldobj.tag;

    return *this;
}
