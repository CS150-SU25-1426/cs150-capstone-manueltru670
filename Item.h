#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
private:
    int id;
    std::string brand;
    std::string model;
    double engineSize;     // in cc
    double seatHeight;     // in inches
    double weight;         // in lbs
    int quantity;
    double price;

public:
    // Constructors
    Item();
    Item(int id, std::string brand, std::string model, double engineSize, double seatHeight, double weight, int quantity, double price);

    // Getters
    int getId() const;
    std::string getBrand() const;
    std::string getModel() const;
    double getEngineSize() const;
    double getSeatHeight() const;
    double getWeight() const;
    int getQuantity() const;
    double getPrice() const;

    // Setters
    void setBrand(const std::string& b);
    void setModel(const std::string& m);
    void setEngineSize(double e);
    void setSeatHeight(double s);
    void setWeight(double w);
    void setQuantity(int q);
    void setPrice(double p);

    // Operator overloads
    bool operator==(const Item& other) const;

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& out, const Item& item);
};

#endif // ITEM_H
