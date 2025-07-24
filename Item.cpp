#include "Item.h"

Item::Item() : name("Unnamed"), quantity(0) {}

Item::Item(string itemName, int qty) : name(itemName), quantity(qty) {}

string Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setName(string itemName) {
    name = itemName;
}

void Item::setQuantity(int qty) {
    quantity = qty;
}

bool Item::operator==(const Item& other) const {
    return name == other.name && quantity == other.quantity;
}

ostream& operator<<(ostream& out, const Item& item) {
    out << "Item [Name: " << item.name << ", Quantity: " << item.quantity << "]";
    return out;
}
