#include <cstdlib>
#include <iostream>
#include "list.h"

using namespace std;

list::list() {
    head = NULL;
    current = NULL;
    temp = NULL;
}

void list::addNode(int addData) {
    nodePtr n = new node;
    n->next = NULL;
    n->data = addData;

    if (head != NULL) {
        current = head;
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = n;
    } else {
        head = n;
    }
}

void list::deleteNode(int delData) {
    nodePtr delPtr = NULL;
    temp = head;
    current = head;

    while(current != NULL && current->data != delData) {
        temp = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << delData << " was not in the list" << endl;
        delete delPtr;
    } else {
        delPtr = current;
        current = current->next;
        temp->next = current;
        delete delPtr;
        cout << "The value " << delData << " was deleted" << endl;
    }
}

void list::printList() {
    current = head;
    while(current != NULL) {
        cout << current->data << endl;
        current = current -> next;
    }
}

