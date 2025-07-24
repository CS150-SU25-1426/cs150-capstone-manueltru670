#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string name;
    int quantity;

public:
    Item();                            // Default constructor
    Item(string itemName, int qty);    // Parameterized constructor

    string getName() const;
    int getQuantity() const;

    void setName(string itemName);
    void setQuantity(int qty);

    bool operator==(const Item& other) const;
    friend ostream& operator<<(ostream& out, const Item& item);
};

#endif