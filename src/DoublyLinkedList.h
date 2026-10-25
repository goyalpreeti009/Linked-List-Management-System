
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value)
            : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);
    void insertAfterValue(int target, int value);
    void insertBeforeValue(int target, int value);

    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteAtPosition(int position);
    void deleteByValue(int value);

    void search(int value) const;
    void update(int oldValue, int newValue);

    void displayForward() const;
    void displayBackward() const;

    int countNodes() const;
    void findMaximum() const;
    void findMinimum() const;
    void findMiddle() const;

    void reverse();
    void sort();
    void removeDuplicates();
};

#endif
