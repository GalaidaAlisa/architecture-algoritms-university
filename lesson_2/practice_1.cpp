#include <iostream>

struct tnode {
    int info;
    tnode* next;
};

typedef tnode* pnode; // далі по коду, якщо бачите pnode можете його заміняти в думках tnode* (tnode* == pnode)

using namespace std;

pnode initialization_linked_list() {
    cout << "Enter number of elements: ";
    int amount;
    cin >> amount;

    pnode head = new tnode;
    cout << "Enter info: ";
    cin >> head->info;

    pnode prev = head;
    for (int i = 1; i < amount; i++) {
        pnode new_item = new tnode;
        cout << "Enter info: ";
        cin >> new_item->info;

        prev->next = new_item;
        prev = new_item;
    }
    prev->next = nullptr;

    return head;
}

void init(pnode head) {
    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    cout << "Enter info: ";
    cin >> head->info;
    pnode prev = head;
    
    for (int i = 1; i < n; i ++) {
        pnode new_elem = new tnode; 
        cout << "Enter info: ";
        cin >> new_elem->info;
        prev->next = new_elem;
        prev = new_elem;
    }
    prev->next = nullptr;
}

void linked_list_to_console(pnode head) {
    pnode cur = head;
    while (cur) {
        cout << cur->info << ' ';
        cur = cur->next;
    }
}

int main() {
    pnode first_head = initialization_linked_list();


    linked_list_to_console(first_head);

    // clearing memory
    while (first_head) {
        pnode temp = first_head;
        first_head = first_head->next;
        delete temp;
    }
    cout << endl;

    // новий head
    pnode second_head = new tnode;
    init(second_head);
    linked_list_to_console(second_head);

    while (second_head) {
        pnode temp = second_head;
        second_head = second_head->next;
        delete temp;
    }

    return 0;
}