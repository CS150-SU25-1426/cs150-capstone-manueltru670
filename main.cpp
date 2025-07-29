#include <iostream>
#include <vector>
#include <iomanip>
#include "item.h"

using namespace std;

// Function to display menu
void displayMenu() {
    cout << "\nChoose an option:\n";
    cout << "1. Add surfboard\n";
    cout << "2. Edit surfboard\n";
    cout << "3. Remove surfboard\n";
    cout << "4. Show inventory\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
}

// Function to find item index by ID
int findItemIndexById(const vector<Item>& inventory, int id) {
    for (size_t i = 0; i < inventory.size(); i++) {
        if (inventory[i].getId() == id)
            return i;
    }
    return -1;
}

int main() {
    vector<Item> inventory;
    int choice;
    int nextId = 10001;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        if (choice == 1) {
            string brand, model;
            double length, width, thickness, price;
            int quantity;

            cout << "\nEnter Brand: ";
            getline(cin, brand);
            cout << "Enter Model: ";
            getline(cin, model);
            cout << "Enter Length (ft): ";
            cin >> length;
            cout << "Enter Width (in): ";
            cin >> width;
            cout << "Enter Thickness (in): ";
            cin >> thickness;
            cout << "Enter Quantity: ";
            cin >> quantity;
            cout << "Enter Price: $";
            cin >> price;

            Item newItem(nextId++, brand, model, length, width, thickness, quantity, price);
            inventory.push_back(newItem);

            cout << "\n~~~Surfboard added successfully!~~~\n";

        } else if (choice == 2) {
            int id;
            cout << "Enter ID of surfboard to edit: ";
            cin >> id;

            int index = findItemIndexById(inventory, id);
            if (index != -1) {
                string brand, model;
                double length, width, thickness, price;
                int quantity;

                cin.ignore();
                cout << "Enter New Brand: ";
                getline(cin, brand);
                cout << "Enter New Model: ";
                getline(cin, model);
                cout << "Enter New Length (ft): ";
                cin >> length;
                cout << "Enter New Width (in): ";
                cin >> width;
                cout << "Enter New Thickness (in): ";
                cin >> thickness;
                cout << "Enter New Quantity: ";
                cin >> quantity;
                cout << "Enter New Price: $";
                cin >> price;

                inventory[index].setBrand(brand);
                inventory[index].setModel(model);
                inventory[index].setLength(length);
                inventory[index].setWidth(width);
                inventory[index].setThickness(thickness);
                inventory[index].setQuantity(quantity);
                inventory[index].setPrice(price);

                cout << "~~~Surfboard updated successfully!~~~\n";
            } else {
                cout << "~~~ID not found.~~~\n";
            }

        } else if (choice == 3) {
            int id;
            cout << "Enter ID of surfboard to remove: ";
            cin >> id;

            int index = findItemIndexById(inventory, id);
            if (index != -1) {
                inventory.erase(inventory.begin() + index);
                cout << "~~~Surfboard removed successfully!~~~\n";
            } else {
                cout << "~~~ID not found.~~~\n";
            }

        } else if (choice == 4) {
            cout << "\n~~~Current Inventory of Surfboards~~~\n\n";
            cout << left << setw(6) << "ID#"
                 << setw(17) << "Brand"
                 << setw(17) << "Model"
                 << setw(12) << "Length (ft)"
                 << setw(11) << "Width (in)"
                 << setw(16) << "Thickness (in)"
                 << setw(10) << "Quantity"
                 << "Price\n";

            for (const auto& item : inventory) {
                cout << left << setw(6) << item.getId()
                     << setw(17) << item.getBrand()
                     << setw(17) << item.getModel()
                     << setw(12) << fixed << setprecision(2) << item.getLength()
                     << setw(11) << item.getWidth()
                     << setw(16) << item.getThickness()
                     << setw(10) << item.getQuantity()
                     << fixed << setprecision(2) << item.getPrice()
                     << endl;
            }
        }

    } while (choice != 5);

    cout << "\n~~~Goodbye!~~~\n";
    return 0;
}
