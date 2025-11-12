#ifndef VISITOR_H
#define VISITOR_H

#include <iostream>
#include <string>
using namespace std;

class Visitor {
private:
    string visitorName;
    int ticketsBought;

public:
    Visitor();
    Visitor(string n, int t);
    ~Visitor();

    void displayInfo() const;
};

#endif
