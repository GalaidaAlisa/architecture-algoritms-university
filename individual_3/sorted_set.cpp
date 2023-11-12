#include <iostream>
#include "header.h"
using namespace std;

bool isExist(pnode& head, int value) {
    pnode current = head;
    while (current) {
        if (current->info == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void insertSorted(pnode& head, int value) {
    if (isExist(head, value)) {
        return;
    }
    pnode newNode = new tnode;
    newNode->info = value;
    newNode->next = nullptr;

    if (!head || value < head->info) {
        newNode->next = head;
        head = newNode;
    } else {
        pnode current = head;
        while (current->next && current->next->info < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList(pnode head) {
    pnode current = head;
    while (current) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

void removeByValue(pnode& head, int value) {
    pnode current = head;
    pnode previous = nullptr;

    while (current && current->info != value) {
        previous = current;
        current = current->next;
    }

    if (current) {
        if (previous) {
            previous->next = current->next;
        } else {
            head = current->next;
        }

        delete current;
    }
}

void deleteList(pnode& head) {
    pnode current = head;
    pnode next;

    while (current) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}


int SortedSet::hash_map(int value) {
    return (value % SIZE + SIZE) % SIZE;
}

SortedSet::SortedSet() {
    for (int i = 0; i < SIZE; i++) {
        array[i] = nullptr;
    }
}

void SortedSet::insertInto(int value) {
    int index = hash_map(value);
    insertSorted(array[index], value);
}

void SortedSet::deleteItem(int value) {
    int index = hash_map(value);
    removeByValue(array[index], value);
}

bool SortedSet::isExistInSet(int value) {
    int index = hash_map(value);
    return isExist(array[index], value);
}

void SortedSet::output() {
    bool flag = false;
    for (int i = 0; i < SIZE; i++) {
        if (array[i]) {
            flag = true;
            cout << "Bucket " << i << ": ";
            displayList(array[i]);
        }
    }
    cout << endl;
    if (!flag) {
        cout << "Sorted set is empty." << endl;
    }
}

SortedSet::~SortedSet() {
    for (int i = 0; i < SIZE; i++) {
        deleteList(array[i]);
    }
}
