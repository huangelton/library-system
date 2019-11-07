#include <iostream>
#include <iomanip>
#include "project1.h"

using namespace std;

Library::Library() {

    head = nullptr;
}

Library::~Library() {

    Node *nodePtr;
    Node *newNode;
    nodePtr = head;
    
    while (nodePtr) {

        newNode = nodePtr->next;
        delete nodePtr;
        nodePtr = newNode;
    }
    head = nullptr;
}

Library::Library(const Library &objList) {
    
    Node * nodePtr = objList.head;
    head = nullptr;
    
    while (nodePtr != nullptr) {
        
        addData(nodePtr->bookTitle, nodePtr->authorName, nodePtr->ID, nodePtr->price);
        nodePtr = nodePtr->next;
    }
}

Library & Library::operator=(const Library &objList) {

    if (this == &objList) {

        return *this;
    }
    
    while (head != nullptr) {

        deleteItem();
    }
    Node *nodePtr = objList.head;

    while (nodePtr != nullptr) {
        
        addData(nodePtr->bookTitle, nodePtr->authorName, nodePtr->ID, nodePtr->price);
        nodePtr = nodePtr->next;
    }
    return *this;
}

void Library::deleteItem() {
    
    Node* temp = temp->next;
    delete head;
    head = temp;
}

void Library::addData(string book, string author, double num, double cost) {

    Node *prevPtr;
    Node *nodePtr;
    Node *newNode = new Node;
    newNode->bookTitle = book;
    newNode->authorName = author;
    newNode->ID = num;
    newNode->price = cost;
    
    if (head == nullptr) {

        head = newNode;
        newNode->next = nullptr;
    }

    else {

        prevPtr = nullptr;
        nodePtr = head;

        while (nodePtr != nullptr) {

            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (prevPtr == nullptr) {

            head = nodePtr;
            newNode->next = nodePtr;
        }

        else {

            prevPtr->next = newNode;
            newNode->next = nodePtr;
        }
    }    
}

void Library::searchData(int num) {

    Node *nodePtr;
    int locate = 0;
    nodePtr = head;

    while (nodePtr != nullptr) {

        locate++;

        if (nodePtr->ID == num) {

            cout << endl << nodePtr->bookTitle << " by " 
            << nodePtr->authorName << " is in the library database." << endl;
            exit(1);
        }

        else {

            nodePtr = nodePtr->next;
        }
    }
    cout << endl << "The book is not found in the library database.\n";
}

void Library::deleteData(int num) {

    Node *nodePtr;
    Node *prevPtr;

    if (!head)

        return;
    
    if (head->ID == num) {

        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }

    else {

        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->ID != num) {

            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr) {

            prevPtr->next = nodePtr->next;
            delete prevPtr;
        }
    }
}

int Library::getTotalBooks() {

    Node *nodePtr = head;
    int total = 0;

    while (nodePtr != nullptr) {

        total++;
        nodePtr = nodePtr->next;
    }
    return total;
}

void Library::displayList() const {

    Node *nodePtr = head;
    cout << endl;
    cout << left << setw(26) << "Book Title" << setw(22) << 
    "Author" << setw(19) << "ISBN" << setw(17) << "Price($)" << endl;

    while (nodePtr != nullptr) {

        cout << left << setw(26) << nodePtr->bookTitle << setw(22) 
        << nodePtr->authorName << setw(19) << nodePtr->ID 
        << setw(17) << nodePtr->price << endl;
        nodePtr = nodePtr->next;
    }
}