#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

class Mammal : public Animal {
private:
    string furColor;

public:
    Mammal();
    Mammal(string f, string n, int a, bool h);
    ~Mammal();

    void setFurColor(string f);
    string getFurColor() const;

    void display() const override;
};

#endif
