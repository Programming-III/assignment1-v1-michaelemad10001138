#include "Animal.h"
#include "Bird.h"
#include "Mammal.h"
#include "Reptile.h"
#include "Enclosure.h"
#include "Visitor.h"
#include <iostream>
using namespace std;
class Animal {
private:
    string name;
    int age;
    bool isHungry;

public:
    Animal() : name(""), age(0), isHungry(false) {}
    Animal(string n, int a, bool h) : name(n), age(a), isHungry(h) {}
    ~Animal() {}

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setIsHungry(bool h) { isHungry = h; }

    string getName() const { return name; }
    int getAge() const { return age; }
    bool getIsHungry() const { return isHungry; }

    virtual void display() const {
        cout << "Name: " << name << " (Age: " << age << ") "
             << "Hungry: " << (isHungry ? "Yes" : "No") << endl;
    }

    virtual void feed() {
        if (isHungry) {
            cout << name << " is being fed.\n";
            isHungry = false;
        } else {
            cout << name << " is not hungry.\n";
        }
    }
};

class Mammal : public Animal {
private:
    string furColor;

public:
    Mammal() : Animal(), furColor("") {}
    Mammal(string f, string n, int a, bool h) : Animal(n, a, h), furColor(f) {}
    ~Mammal() {}

    void setFurColor(string f) { furColor = f; }
    string getFurColor() const { return furColor; }

    void display() const override {
        cout << "Mammal - ";
        Animal::display();
        cout << "Fur Color: " << furColor << endl;
    }
};

class Bird : public Animal {
private:
    float wingSpan;

public:
    Bird() : Animal(), wingSpan(0.0f) {}
    Bird(float w, string n, int a, bool h) : Animal(n, a, h), wingSpan(w) {}
    ~Bird() {}

    void setWingSpan(float w) { wingSpan = w; }
    float getWingSpan() const { return wingSpan; }

    void display() const override {
        cout << "Bird - ";
        Animal::display();
        cout << "Wing Span: " << wingSpan << " meters" << endl;
    }
};

class Reptile : public Animal {
private:
    bool isVenomous;

public:
    Reptile() : Animal(), isVenomous(false) {}
    Reptile(bool v, string n, int a, bool h) : Animal(n, a, h), isVenomous(v) {}
    ~Reptile() {}

    void setIsVenomous(bool v) { isVenomous = v; }
    bool getIsVenomous() const { return isVenomous; }

    void display() const override {
        cout << "Reptile - ";
        Animal::display();
        cout << "Venomous: " << (isVenomous ? "Yes" : "No") << endl;
    }
};

class Enclosure {
private:
    Animal** animals;
    int capacity;
    int count;

public:
    Enclosure() : capacity(5), count(0) {
        animals = new Animal*[capacity];
    }
    Enclosure(int cap) : capacity(cap), count(0) {
        animals = new Animal*[capacity];
    }
    ~Enclosure() {
        delete[] animals;
    }

    void addAnimal(Animal* a) {
        if (count < capacity) {
            animals[count++] = a;
        } else {
            cout << "Enclosure is full!\n";
        }
    }

    void displayAnimals() const {
        cout << "Animals in Enclosure:\n";
        for (int i = 0; i < count; i++) {
            animals[i]->display();
            cout << endl;
        }
    }
};

class Visitor {
private:
    string visitorName;
    int ticketsBought;

public:
    Visitor() : visitorName(""), ticketsBought(0) {}
    Visitor(string n, int t) : visitorName(n), ticketsBought(t) {}
    ~Visitor() {}

    void displayVisitorInfo() const {
        cout << "Visitor: " << visitorName
             << " | Tickets Bought: " << ticketsBought << endl;
    }
};

int main() {
    Mammal m1("Brown", "Lion", 5, true);
    Bird b1(2.5, "Eagle", 3, false);
    Reptile r1(true, "Cobra", 2, true);

    Enclosure e1(5);
    e1.addAnimal(&m1);
    e1.addAnimal(&b1);
    e1.addAnimal(&r1);

    Visitor v1("Michael", 10);

    cout << "--- Display Individual Animals ---\n";
    m1.display();
    b1.display();
    r1.display();

    cout << "\n--- Display Enclosure ---\n";
    e1.displayAnimals();

    cout << "\n--- Visitor Info ---\n";
    v1.displayVisitorInfo();

    return 0;
}
