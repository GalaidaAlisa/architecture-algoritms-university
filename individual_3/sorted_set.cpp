#include <iostream>
#include "header.h"
using namespace std;

// перевірка на існування елементу у списку
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

// вставка нового елементу
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

// вивід списку
void displayList(pnode head) {
    pnode current = head;
    while (current) {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

// функція видалення елементу 
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

// видалення всього списку
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

// розписування методів класу SortedSet


int SortedSet::hash_map(int value) {
    return (value % SIZE + SIZE) % SIZE;
}

// конструктор класу
SortedSet::SortedSet() {
    for (int i = 0; i < SIZE; i++) {
        array[i] = nullptr;
    }
}

void SortedSet::insertInto(int value) {
    int index = hash_map(value);
    insertSorted(array[index], value);
}

bool SortedSet::isExistInSet(int value) {
    int index = hash_map(value);
    return isExist(array[index], value);
}

void SortedSet::deleteItem(int value) {
    int index = hash_map(value);
    if (isExist(array[index], value)) {
        removeByValue(array[index], value);
        cout << "Operation success." << endl;
    } else {
        cout << "Such number does not exist in the set." << endl;
    }
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

int SortedSet::number_of_elem() {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (array[i]) { 
            count++;
        }
    }
    return count;
}

SortedSet::~SortedSet() {
    for (int i = 0; i < SIZE; i++) {
        deleteList(array[i]);
    }
}
