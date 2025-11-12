#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    bool isHungry;

public:
    Animal();
    Animal(string n, int a, bool h);
    virtual ~Animal();

    void setName(string n);
    void setAge(int a);
    void setIsHungry(bool h);

    string getName() const;
    int getAge() const;
    bool getIsHungry() const;

    virtual void display() const;
    virtual void feed();
};

#endif
