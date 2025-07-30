#include <iostream>
#include <vector>
#include <iomanip>
#include "Item.h" // Make sure this file uses dirt bike terminology now

using namespace std;

// Function to display menu
void displayMenu() {
    cout << "\nChoose an option:\n";
    cout << "1. Add dirt bike\n";
    cout << "2. Edit dirt bike\n";
    cout << "3. Remove dirt bike\n";
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
            double engineSize, seatHeight, weight, price;
            int quantity;

            cout << "\nEnter Brand: ";
            getline(cin, brand);
            cout << "Enter Model: ";
            getline(cin, model);
            cout << "Enter Engine Size (cc): ";
            cin >> engineSize;
            cout << "Enter Seat Height (in): ";
            cin >> seatHeight;
            cout << "Enter Weight (lbs): ";
            cin >> weight;
            cout << "Enter Quantity: ";
            cin >> quantity;
            cout << "Enter Price: $";
            cin >> price;

            Item newItem(nextId++, brand, model, engineSize, seatHeight, weight, quantity, price);
            inventory.push_back(newItem);

            cout << "\n~~~Dirt bike added successfully!~~~\n";

        } else if (choice == 2) {
            int id;
            cout << "Enter ID of dirt bike to edit: ";
            cin >> id;

            int index = findItemIndexById(inventory, id);
            if (index != -1) {
                string brand, model;
                double engineSize, seatHeight, weight, price;
                int quantity;

                cin.ignore();
                cout << "Enter New Brand: ";
                getline(cin, brand);
                cout << "Enter New Model: ";
                getline(cin, model);
                cout << "Enter New Engine Size (cc): ";
                cin >> engineSize;
                cout << "Enter New Seat Height (in): ";
                cin >> seatHeight;
                cout << "Enter New Weight (lbs): ";
                cin >> weight;
                cout << "Enter New Quantity: ";
                cin >> quantity;
                cout << "Enter New Price: $";
                cin >> price;

                inventory[index].setBrand(brand);
                inventory[index].setModel(model);
                inventory[index].setLength(engineSize);   // assuming length = engineSize
                inventory[index].setWidth(seatHeight);    // assuming width = seatHeight
                inventory[index].setThickness(weight);    // assuming thickness = weight
                inventory[index].setQuantity(quantity);
                inventory[index].setPrice(price);

                cout << "~~~Dirt bike updated successfully!~~~\n";
            } else {
                cout << "~~~ID not found.~~~\n";
            }

        } else if (choice == 3) {
            int id;
            cout << "Enter ID of dirt bike to remove: ";
            cin >> id;

            int index = findItemIndexById(inventory, id);
            if (index != -1) {
                inventory.erase(inventory.begin() + index);
                cout << "~~~Dirt bike removed successfully!~~~\n";
            } else {
                cout << "~~~ID not found.~~~\n";
            }

        } else if (choice == 4) {
            cout << "\n~~~Current Inventory of Dirt Bikes~~~\n\n";
            cout << left << setw(6) << "ID#"
                 << setw(17) << "Brand"
                 << setw(17) << "Model"
                 << setw(15) << "Engine Size (cc)"
                 << setw(17) << "Seat Height (in)"
                 << setw(14) << "Weight (lbs)"
                 << setw(10) << "Quantity"
                 << "Price\n";

            for (const auto& item : inventory) {
                cout << left << setw(6) << item.getId()
                     << setw(17) << item.getBrand()
                     << setw(17) << item.getModel()
                     << setw(15) << fixed << setprecision(1) << item.getLength()     // engineSize
                     << setw(17) << item.getWidth()      // seatHeight
                     << setw(14) << item.getThickness()  // weight
                     << setw(10) << item.getQuantity()
                     << fixed << setprecision(2) << item.getPrice()
                     << endl;
            }
        }

    } while (choice != 5);

    cout << "\n~~~Goodbye!~~~\n";
    return 0;
}
