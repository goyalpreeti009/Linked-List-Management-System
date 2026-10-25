
#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
using namespace std;

void singlyLinkedListMenu(SinglyLinkedList& list) {
    int choice, value, position, target, newValue;

    do {
        cout << "\n===== SINGLY LINKED LIST =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Insert Before a Node\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete from Position\n";
        cout << "9. Delete by Value\n";
        cout << "10. Search\n";
        cout << "11. Update\n";
        cout << "12. Display\n";
        cout << "13. Count Nodes\n";
        cout << "14. Find Maximum\n";
        cout << "15. Find Minimum\n";
        cout << "16. Find Middle Element\n";
        cout << "17. Reverse\n";
        cout << "18. Sort\n";
        cout << "19. Remove Duplicates\n";
        cout << "20. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                list.insertAtPosition(value, position);
                break;

            case 4:
                cout << "Enter target value and new value: ";
                cin >> target >> value;
                list.insertAfterValue(target, value);
                break;

            case 5:
                cout << "Enter target value and new value: ";
                cin >> target >> value;
                list.insertBeforeValue(target, value);
                break;

            case 6:
                list.deleteFromBeginning();
                break;

            case 7:
                list.deleteFromEnd();
                break;

            case 8:
                cout << "Enter position: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;

            case 9:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteByValue(value);
                break;

            case 10:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 11:
                cout << "Enter old value and new value: ";
                cin >> target >> newValue;
                list.update(target, newValue);
                break;

            case 12:
                list.display();
                break;

            case 13:
                cout << "Total nodes: " << list.countNodes() << '\n';
                break;

            case 14:
                list.findMaximum();
                break;

            case 15:
                list.findMinimum();
                break;

            case 16:
                list.findMiddle();
                break;

            case 17:
                list.reverse();
                break;

            case 18:
                list.sort();
                break;

            case 19:
                list.removeDuplicates();
                break;

            case 20:
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 20);
}

void doublyLinkedListMenu(DoublyLinkedList& list) {
    int choice, value, position, target, newValue;

    do {
        cout << "\n===== DOUBLY LINKED LIST =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Insert Before a Node\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete from Position\n";
        cout << "9. Delete by Value\n";
        cout << "10. Search\n";
        cout << "11. Update\n";
        cout << "12. Display Forward\n";
        cout << "13. Display Backward\n";
        cout << "14. Count Nodes\n";
        cout << "15. Find Maximum\n";
        cout << "16. Find Minimum\n";
        cout << "17. Find Middle Element\n";
        cout << "18. Reverse\n";
        cout << "19. Sort\n";
        cout << "20. Remove Duplicates\n";
        cout << "21. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                list.insertAtPosition(value, position);
                break;

            case 4:
                cout << "Enter target value and new value: ";
                cin >> target >> value;
                list.insertAfterValue(target, value);
                break;

            case 5:
                cout << "Enter target value and new value: ";
                cin >> target >> value;
                list.insertBeforeValue(target, value);
                break;

            case 6:
                list.deleteFromBeginning();
                break;

            case 7:
                list.deleteFromEnd();
                break;

            case 8:
                cout << "Enter position: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;

            case 9:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteByValue(value);
                break;

            case 10:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 11:
                cout << "Enter old value and new value: ";
                cin >> target >> newValue;
                list.update(target, newValue);
                break;

            case 12:
                list.displayForward();
                break;

            case 13:
                list.displayBackward();
                break;

            case 14:
                cout << "Total nodes: " << list.countNodes() << '\n';
                break;

            case 15:
                list.findMaximum();
                break;

            case 16:
                list.findMinimum();
                break;

            case 17:
                list.findMiddle();
                break;

            case 18:
                list.reverse();
                break;

            case 19:
                list.sort();
                break;

            case 20:
                list.removeDuplicates();
                break;

            case 21:
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 21);
}

void compareLists() {
    cout << "\n===== SINGLY VS DOUBLY LINKED LIST =====\n";
    cout << "Singly Linked List:\n";
    cout << "- Each node has data and a next pointer.\n";
    cout << "- Traversal is forward only.\n";
    cout << "- Requires less memory per node.\n\n";

    cout << "Doubly Linked List:\n";
    cout << "- Each node has data, prev and next pointers.\n";
    cout << "- Traversal is forward and backward.\n";
    cout << "- Requires more memory per node.\n";
}

int main() {
    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;

    int choice;

    do {
        cout << "\n========================================\n";
        cout << "      LINKED LIST MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Compare Singly vs Doubly Linked List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                singlyLinkedListMenu(singlyList);
                break;

            case 2:
                doublyLinkedListMenu(doublyList);
                break;

            case 3:
                compareLists();
                break;

            case 4:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
