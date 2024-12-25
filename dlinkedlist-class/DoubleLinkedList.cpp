#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node() { prev = nullptr; next = nullptr; }
private:
    Node *prev;
    int data;
    Node *next;
    friend class DLinkedList;
};

class DLinkedList {
private:
    int numNodes;
    Node *head;

public:
    DLinkedList();
    ~DLinkedList();

    void addBack(int x);
    void addFront(int x);
    int removeFront();
    void print();
    int getSize() { return numNodes; }
    void addAfterIndex(int index, int x);
};

DLinkedList::DLinkedList() {
    numNodes = 0;
    head = nullptr;
}

DLinkedList::~DLinkedList() {
    Node *curr = head;
    while (curr != nullptr) {
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void DLinkedList::addBack(int x) {
    Node *newNode = new Node();
    newNode->data = x;

    if (head == nullptr) { 
        head = newNode;
    } else {
        Node *curr = head;
        while (curr->next != nullptr) { 
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
    numNodes++;
}

void DLinkedList::addFront(int x) {
    Node *newNode = new Node();
    newNode->data = x;

    if (head == nullptr) { 
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    numNodes++;
}

int DLinkedList::removeFront() {
    if (head == nullptr) { 
        return -1;
    }

    int value = head->data;
    Node *temp = head;
    head = head->next;
    if (head != nullptr) { 
        head->prev = nullptr;
    }
    delete temp;
    numNodes--;
    return value;
}

void DLinkedList::print() {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void DLinkedList::addAfterIndex(int index, int x) {
    if (index < 0 || index >= numNodes) {
        cout << "Index out of range" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = x;

    Node *curr = head;
    for (int i = 0; i < index; i++) { 
        curr = curr->next;
    }

    newNode->next = curr->next;
    newNode->prev = curr;

    if (curr->next != nullptr) {
        curr->next->prev = newNode;
    }

    curr->next = newNode;
    numNodes++;
}

int main() {
    DLinkedList list;
    list.addFront(3);
    list.addBack(4);
    list.addBack(5);
    list.addBack(7);
    list.addBack(12);
    list.addBack(15);
    list.addBack(19);
    list.addAfterIndex(4, 4);
    list.print();
    return 0;
}
