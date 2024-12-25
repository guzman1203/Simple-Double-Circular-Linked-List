#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    Node() { next = nullptr; }
private:
    int data;
    Node* next;
    friend class SLinkedList;
};

class SLinkedList {
private:
    int numNodes;
    Node* head;

public:
    SLinkedList();
    ~SLinkedList();
    void addBack(int x);
    void addFront(int x);
    int removeFront();
    void print();
    int getSize() { return numNodes; }
    void addAfterIndex(int index, int x);
};

SLinkedList::SLinkedList() {
    numNodes = 0;
    head = nullptr;
}

SLinkedList::~SLinkedList() {
    while (head != nullptr) {
        removeFront();
    }
}

void SLinkedList::addBack(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    numNodes++;
}

void SLinkedList::addFront(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    numNodes++;
}

int SLinkedList::removeFront() {
    if (head == nullptr) {
        return -1;
    }
    Node* temp = head;
    int data = temp->data;
    head = head->next;
    delete temp;
    numNodes--;
    return data;
}

void SLinkedList::print() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void SLinkedList::addAfterIndex(int index, int x) {
    if (index < 0 || index >= numNodes) {
        cout << "Index out of bounds" << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = current->next;
    current->next = newNode;
    numNodes++;
}

int main() {
    SLinkedList list;
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
