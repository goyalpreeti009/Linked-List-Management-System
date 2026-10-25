
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

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
    void display() const;

    int countNodes() const;
    void findMaximum() const;
    void findMinimum() const;
    void findMiddle() const;

    void reverse();
    void sort();
    void removeDuplicates();
};

#endif
