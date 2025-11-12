#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"

class Reptile : public Animal {
private:
    bool isVenomous;

public:
    Reptile();
    Reptile(bool v, string n, int a, bool h);
    ~Reptile();

    void setIsVenomous(bool v);
    bool getIsVenomous() const;

    void display() const override;
};

#endif
