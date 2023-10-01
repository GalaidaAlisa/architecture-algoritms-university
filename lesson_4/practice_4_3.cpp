#include <iostream>

using namespace std;

struct tnode {
    int info;
    tnode* next;
};

typedef tnode* pnode;

pnode creating_link_list(); // створення списку
void output(pnode top); // виведення списку
void delete_elem(pnode& head, int info); // видалення елементу
void add_elem(pnode& head, int info); // додавання елементу
void delete_list(pnode head); // видалення списку


pnode creating_link_list() {
    pnode head = new tnode;
    int info;
    cout << "Enter info: " << endl;
    cin >> info;
    head->info = info;
    head->next = nullptr;
    int choice;
    pnode new_elem;
    pnode cur;
    while (true) {
        cout << "Do you want to add new element?" << endl;
        cout << "1) Yes\n2) No" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cur = head;
                cout << "Enter info: " << endl;
                cin >> info;
                new_elem = new tnode;
                new_elem->info = info;
                if (head->info > info) {
                    new_elem->next = head;
                    head = new_elem;
                } else {
                    while (cur->next) {
                        if (cur->next->info > info) {
                            new_elem->next = cur->next;
                            cur->next = new_elem;    
                            break;                        
                        } 
                        cur = cur->next;
                    }
                    if (cur->next == nullptr) {
                        cur->next = new_elem;
                        new_elem->next = nullptr;
                    }
                }
                break;
            case 2: 
                return head;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}

void output(pnode top) {
    while(top) {
        cout << top->info << ' ';
        top = top->next;
    }
}

void delete_elem(pnode& head, int info) {
    if (head->info == info) {
        pnode temp = head;
        head = head->next;
        delete temp;
        return;
    }
    pnode cur = head->next;
    pnode prev = head;
    while(cur) {
        if (cur->info == info) {
            prev->next = cur->next;
            delete cur;
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
    cout << "There is no such elements." << endl;
}

void add_elem(pnode& head, int info) {
    pnode cur = head->next;
    pnode prev = head;
    pnode new_elem = new tnode;
    new_elem->info = info;
    new_elem->info = info;
    if (head->info > info) {
        new_elem->next = head;
        head = new_elem;
        return;
    }
    while(cur) {
        if (cur->info > info) {
            prev->next = new_elem;
            new_elem->next = cur;
            return;
        }
        cur = cur->next;
        prev = prev->next;
    }
    prev->next = new_elem;
    new_elem->next = nullptr;
}

void delete_list(pnode head) {
    while(head) {
        pnode temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    bool flag = true;
    int choice;
    int info;
    pnode head;
    while(flag) {
        cout << "Menu: " << endl;
        cout << "1. Create a list" << endl;
        cout << "2. Output list" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Add element" << endl;
        cout << "5. Delete list" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;
        switch(choice) {
            case 1:
                head = creating_link_list();
                break;
            case 2:
                output(head);
                break;
            case 3:
                cout << "Enter element to delete: " << endl;
                cin >> info;
                delete_elem(head, info);
                break;
            case 4:
                cout << "Enter element to add: " << endl;
                cin >> info;
                add_elem(head, info);
                break;
            case 5:
                delete_list(head);
                break;
            case 6:
                cout << endl << "The program is finished." << endl;
                flag = false;
                break;
            default: 
                cout << endl << "Wrong choice." << endl;
        }        
    }
    return 0;
}