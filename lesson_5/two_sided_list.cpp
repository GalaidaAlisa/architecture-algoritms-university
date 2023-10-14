#include <iostream>
#include "two_sided_list.h"

using namespace std;

void forming_list(pnode start, pnode& end) {
    int info;
    cout << "Enter info: (if you enter 0, operation will stop)" << endl;
    cin >> info;
    pnode new_el;
    while(info) {
        new_el = new tnode;
        new_el->info = info;
        new_el->next = end;
        new_el->prev = end->prev;
        end->prev->next = new_el;
        end->prev = new_el;
        cout << "Enter info: " << endl;
        cin >> info;
    }
}

void output_primary(pnode start) {
    pnode head = start->next;
    while(head->info) {
        cout << head->info << ' ';
        head = head->next;
    }
    cout << endl;
}

void output_reverse(pnode end) {
    pnode tail = end->prev;
    while(tail->info) {
        cout << tail->info << ' ';
        tail = tail->prev;
    }
    cout << endl;
}

void symmetry(pnode start, pnode end) {
    pnode head = start->next;
    pnode tail = end->prev;
    while(head->info && (head->info == tail->info)) {
        head = head->next;
        tail = tail->prev;
    }
    if (head->info) {
        cout << "List is not symmetrical." << endl;
    } else {
        cout << "List is symmetrical." << endl;
    }
}

void del_el(pnode start, int info_to_del) {
    pnode head = start->next;
    while(head->info) {
        if (head->info == info_to_del) {
            head->prev->next = head->next;
            head->next->prev = head->prev;
            delete head;
            return;
        }
        head = head->next;
    }
}

void add_el_before(pnode start, int info) {
    pnode head = start->next;
    pnode new_el;
    int new_info;
    while(head->info) {
        if (head->info == info) {
            new_el = new tnode;
            cout << "Enter info for new elem: " << endl;
            cin >> new_info;
            new_el->info = new_info;
            new_el->next = head;
            new_el->prev = head->prev;
            head->prev->next = new_el;
            head->prev = new_el;
            return;
        }
        head = head->next;
    }
    cout << "There is no such element." << endl;
}

void add_el_after(pnode start, int info) {
    pnode head = start->next;
    pnode new_el;
    int new_info;
    while(head->info) {
        if (head->info == info) {
            new_el = new tnode;
            cout << "Enter info for new elem: " << endl;
            cin >> new_info;
            new_el->info = new_info;
            new_el->next = head->next;
            new_el->prev = head;
            head->next->prev = new_el;
            head->next = new_el;
            return;
        }
        head = head->next;
    }
    cout << "There is no such element." << endl;
}

int count_el(pnode start) {
    pnode head = start->next;
    int count = 0;
    while(head->info) {
        count++;
        head = head->next;
    }
    return count;
}

void del_list(pnode start, pnode end) {
    pnode head = start->next;
    pnode temp;
    while(head->info) {
        temp = head;
        head = head->next;
        delete temp;
    }
    delete start;
    delete end;
}