#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "Animal.h"

class Enclosure {
private:
    Animal** animals;
    int capacity;
    int count;

public:
    Enclosure();
    Enclosure(int cap);
    ~Enclosure();

    void addAnimal(Animal* a);
    void displayAnimals() const;
};

#endif
