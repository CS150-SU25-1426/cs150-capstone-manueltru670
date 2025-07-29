#include "item.h"
#include <iomanip>

// Default Constructor
Item::Item() : id(0), brand(""), model(""), length(0), width(0), thickness(0), quantity(0), price(0.0) {}

// Parameterized Constructor
Item::Item(int id, std::string brand, std::string model, double length, double width, double thickness, int quantity, double price)
    : id(id), brand(brand), model(model), length(length), width(width), thickness(thickness), quantity(quantity), price(price) {}

// Getters
int Item::getId() const { return id; }
std::string Item::getBrand() const { return brand; }
std::string Item::getModel() const { return model; }
double Item::getLength() const { return length; }
double Item::getWidth() const { return width; }
double Item::getThickness() const { return thickness; }
int Item::getQuantity() const { return quantity; }
double Item::getPrice() const { return price; }

// Setters
void Item::setBrand(const std::string& b) { brand = b; }
void Item::setModel(const std::string& m) { model = m; }
void Item::setLength(double l) { length = l; }
void Item::setWidth(double w) { width = w; }
void Item::setThickness(double t) { thickness = t; }
void Item::setQuantity(int q) { quantity = q; }
void Item::setPrice(double p) { price = p; }

// Operator==
bool Item::operator==(const Item& other) const {
    return this->id == other.id;
}

// Output Operator Overload
std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << std::left << std::setw(6) << item.id
        << std::setw(17) << item.brand
        << std::setw(17) << item.model
        << std::setw(12) << std::fixed << std::setprecision(2) << item.length
        << std::setw(11) << item.width
        << std::setw(15) << item.thickness
        << std::setw(10) << item.quantity
        << item.price;
    return out;
}
