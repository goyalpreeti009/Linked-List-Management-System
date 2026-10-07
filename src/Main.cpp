#include <iostream>
using namespace std;


int main() {
    int choice;
    do {
        cout << "\n1. Singly Linked List\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "You opened the Singly Linked List menu!\n";
        }
    } while (choice != 2);
    
    return 0;
}