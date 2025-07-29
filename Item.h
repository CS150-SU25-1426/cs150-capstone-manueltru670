#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
private:
    int id;
    std::string brand;
    std::string model;
    double length;
    double width;
    double thickness;
    int quantity;
    double price;

public:
    // Constructors
    Item();
    Item(int id, std::string brand, std::string model, double length, double width, double thickness, int quantity, double price);

    // Getters
    int getId() const;
    std::string getBrand() const;
    std::string getModel() const;
    double getLength() const;
    double getWidth() const;
    double getThickness() const;
    int getQuantity() const;
    double getPrice() const;

    // Setters
    void setBrand(const std::string& b);
    void setModel(const std::string& m);
    void setLength(double l);
    void setWidth(double w);
    void setThickness(double t);
    void setQuantity(int q);
    void setPrice(double p);

    // Operator overloads
    bool operator==(const Item& other) const;

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& out, const Item& item);
};

#endif
