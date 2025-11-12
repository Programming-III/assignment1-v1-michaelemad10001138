#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
private:
    float wingSpan;

public:
    Bird();
    Bird(float w, string n, int a, bool h);
    ~Bird();

    void setWingSpan(float w);
    float getWingSpan() const;

    void display() const override;
};

#endif
