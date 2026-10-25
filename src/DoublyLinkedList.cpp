
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void DoublyLinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Node inserted successfully.\n";
}

void DoublyLinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);

    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Node inserted successfully.\n";
}

void DoublyLinkedList::insertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position.\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* current = head;

    for (int i = 1; current != nullptr && i < position; i++)
        current = current->next;

    if (current == nullptr) {
        if (position == countNodes() + 1) {
            insertAtEnd(value);
        } else {
            cout << "Invalid position.\n";
        }
        return;
    }

    Node* newNode = new Node(value);
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;

    cout << "Node inserted successfully.\n";
}

void DoublyLinkedList::insertAfterValue(int target, int value) {
    Node* current = head;

    while (current != nullptr && current->data != target)
        current = current->next;

    if (current == nullptr) {
        cout << "Target value not found.\n";
        return;
    }

    if (current == tail) {
        insertAtEnd(value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;

    cout << "Node inserted successfully.\n";
}

void DoublyLinkedList::insertBeforeValue(int target, int value) {
    Node* current = head;

    while (current != nullptr && current->data != target)
        current = current->next;

    if (current == nullptr) {
        cout << "Target value not found.\n";
        return;
    }

    if (current == head) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    cout << "Node inserted successfully.\n";
}

void DoublyLinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    cout << "First node deleted.\n";
}

void DoublyLinkedList::deleteFromEnd() {
    if (tail == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = tail;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    cout << "Last node deleted.\n";
}

void DoublyLinkedList::deleteAtPosition(int position) {
    if (position < 1 || head == nullptr) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* current = head;

    for (int i = 1; current != nullptr && i < position; i++)
        current = current->next;

    if (current == nullptr) {
        cout << "Invalid position.\n";
        return;
    }

    if (current == tail) {
        deleteFromEnd();
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;

    cout << "Node deleted successfully.\n";
}

void DoublyLinkedList::deleteByValue(int value) {
    Node* current = head;

    while (current != nullptr && current->data != value)
        current = current->next;

    if (current == nullptr) {
        cout << "Value not found.\n";
        return;
    }

    if (current == head) {
        deleteFromBeginning();
        return;
    }

    if (current == tail) {
        deleteFromEnd();
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;

    cout << "Node deleted successfully.\n";
}

void DoublyLinkedList::search(int value) const {
    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        if (current->data == value) {
            cout << "Value found at position "
                 << position << ".\n";
            return;
        }

        current = current->next;
        position++;
    }

    cout << "Value not found.\n";
}

void DoublyLinkedList::update(int oldValue, int newValue) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == oldValue) {
            current->data = newValue;
            cout << "Node updated successfully.\n";
            return;
        }

        current = current->next;
    }

    cout << "Value not found.\n";
}

void DoublyLinkedList::displayForward() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "NULL <- ";

    Node* current = head;

    while (current != nullptr) {
        cout << current->data;

        if (current->next != nullptr)
            cout << " <-> ";

        current = current->next;
    }

    cout << " -> NULL\n";
}

void DoublyLinkedList::displayBackward() const {
    if (tail == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "NULL <- ";

    Node* current = tail;

    while (current != nullptr) {
        cout << current->data;

        if (current->prev != nullptr)
            cout << " <-> ";

        current = current->prev;
    }

    cout << " -> NULL\n";
}

int DoublyLinkedList::countNodes() const {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void DoublyLinkedList::findMaximum() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    int maximum = head->data;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data > maximum)
            maximum = current->data;

        current = current->next;
    }

    cout << "Maximum value: " << maximum << '\n';
}

void DoublyLinkedList::findMinimum() const {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    int minimum = head->data;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->data < minimum)
            minimum = current->data;

        current = current->next;
    }

    cout << "Minimum value: " << minimum << '\n';
}

void DoublyLinkedList::findMiddle() const {
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

void DoublyLinkedList::reverse() {
    Node* current = head;

    while (current != nullptr) {
        Node* oldNext = current->next;
        current->next = current->prev;
        current->prev = oldNext;
        current = oldNext;
    }

    Node* oldHead = head;
    head = tail;
    tail = oldHead;

    cout << "List reversed successfully.\n";
}

void DoublyLinkedList::sort() {
    if (head == nullptr || head->next == nullptr)
        return;

    bool swapped;

    do {
        swapped = false;
        Node* current = head;

        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                int value = current->data;
                current->data = current->next->data;
                current->next->data = value;
                swapped = true;
            }

            current = current->next;
        }
    } while (swapped);

    cout << "List sorted successfully.\n";
}

void DoublyLinkedList::removeDuplicates() {
    Node* current = head;

    while (current != nullptr) {
        Node* runner = current->next;

        while (runner != nullptr) {
            if (runner->data == current->data) {
                Node* duplicate = runner;

                if (runner == tail)
                    tail = runner->prev;

                runner->prev->next = runner->next;

                if (runner->next != nullptr)
                    runner->next->prev = runner->prev;

                runner = runner->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }

    cout << "Duplicates removed successfully.\n";
}
