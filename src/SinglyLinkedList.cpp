
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void SinglyLinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "Node inserted successfully.\n";
}

void SinglyLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        cout << "Node inserted successfully.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    cout << "Node inserted successfully.\n";
}

void SinglyLinkedList::insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;

    for (int i = 1; temp != nullptr && i < position - 1; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Invalid position.\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

void SinglyLinkedList::insertAfterValue(int target, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Target value not found.\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

void SinglyLinkedList::insertBeforeValue(int target, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == target) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != target)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Target value not found.\n";
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted successfully.\n";
}

void SinglyLinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "First node deleted.\n";
}

void SinglyLinkedList::deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last node deleted.\n";
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;

    cout << "Last node deleted.\n";
}

void SinglyLinkedList::deleteAtPosition(int position) {
    if (position < 1 || head == nullptr) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; temp != nullptr && i < position - 1; i++)
        temp = temp->next;

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Invalid position.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    cout << "Node deleted successfully.\n";
}

void SinglyLinkedList::deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Value not found.\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;

    cout << "Node deleted successfully.\n";
}

void SinglyLinkedList::search(int value) const {
    Node* temp = head;
    int position = 1;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value found at position " << position << ".\n";
            return;
        }

        temp = temp->next;
        position++;
    }

    cout << "Value not found.\n";
}

void SinglyLinkedList::update(int oldValue, int newValue) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            cout << "Node updated successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Value not found.\n";
}

void SinglyLinkedList::display() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int SinglyLinkedList::countNodes() const {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

void SinglyLinkedList::findMaximum() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    int maximum = head->data;
    Node* temp = head->next;

    while (temp != nullptr) {
        if (temp->data > maximum)
            maximum = temp->data;

        temp = temp->next;
    }

    cout << "Maximum value: " << maximum << '\n';
}

void SinglyLinkedList::findMinimum() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    int minimum = head->data;
    Node* temp = head->next;

    while (temp != nullptr) {
        if (temp->data < minimum)
            minimum = temp->data;

        temp = temp->next;
    }

    cout << "Minimum value: " << minimum << '\n';
}

void SinglyLinkedList::findMiddle() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << '\n';
}

void SinglyLinkedList::reverse() {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
    cout << "List reversed successfully.\n";
}

void SinglyLinkedList::sort() {
    if (head == nullptr || head->next == nullptr)
        return;

    bool swapped;

    do {
        swapped = false;
        Node* temp = head;

        while (temp->next != nullptr) {
            if (temp->data > temp->next->data) {
                int value = temp->data;
                temp->data = temp->next->data;
                temp->next->data = value;
                swapped = true;
            }

            temp = temp->next;
        }
    } while (swapped);

    cout << "List sorted successfully.\n";
}

void SinglyLinkedList::removeDuplicates() {
    Node* current = head;

    while (current != nullptr) {
        Node* runner = current;

        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }

    cout << "Duplicates removed successfully.\n";
}
