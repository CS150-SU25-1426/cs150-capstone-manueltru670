#include <iostream>
#include "Item.h"
using namespace std;

int main() {
    Item item1("Keyboard", 10);
    Item item2("Mouse", 5);
    Item item3("Keyboard", 10);

    cout << item1 << endl;
    cout << item2 << endl;
    cout << "item1 == item2? " << (item1 == item2) << endl;
    cout << "item1 == item3? " << (item1 == item3) << endl;

    return 0;
}