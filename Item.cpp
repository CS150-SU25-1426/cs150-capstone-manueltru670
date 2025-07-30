#include "Item.h"
#include <iomanip>

// Default Constructor
Item::Item() : id(0), brand(""), model(""), engineSize(0), seatHeight(0), weight(0), quantity(0), price(0.0) {}

// Parameterized Constructor
Item::Item(int id, std::string brand, std::string model, double engineSize, double seatHeight, double weight, int quantity, double price)
    : id(id), brand(brand), model(model), engineSize(engineSize), seatHeight(seatHeight), weight(weight), quantity(quantity), price(price) {}

// Getters
int Item::getId() const { return id; }
std::string Item::getBrand() const { return brand; }
std::string Item::getModel() const { return model; }
double Item::getEngineSize() const { return engineSize; }
double Item::getSeatHeight() const { return seatHeight; }
double Item::getWeight() const { return weight; }
int Item::getQuantity() const { return quantity; }
double Item::getPrice() const { return price; }

// Setters
void Item::setBrand(const std::string& b) { brand = b; }
void Item::setModel(const std::string& m) { model = m; }
void Item::setEngineSize(double e) { engineSize = e; }
void Item::setSeatHeight(double s) { seatHeight = s; }
void Item::setWeight(double w) { weight = w; }
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
        << std::setw(15) << std::fixed << std::setprecision(1) << item.engineSize
        << std::setw(17) << item.seatHeight
        << std::setw(14) << item.weight
        << std::setw(10) << item.quantity
        << std::fixed << std::setprecision(2) << item.price;
    return out;
}
