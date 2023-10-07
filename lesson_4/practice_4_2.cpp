#include <iostream>

using namespace std;

struct tnode {
    int info;
    tnode* next;
};

typedef tnode* pnode;

void output_rec(pnode head); // вивід списку
void del_list_rec(pnode head); // видалення списку
int number_of_elem_rec(pnode head); // пошук кількості елементів у списку
pnode form_link_list_rec(); // формування списку
void add_elem_rec_after(pnode head, int info_of_el); // додавання елементу після заданого
void add_elem_rec_before(pnode& head, int info_of_el, pnode prev = nullptr); // додавання елементу перед заданим
void del_el_rec(pnode& head, int info_to_del, pnode prev = nullptr); // видалення заданого елементу


void output_rec(pnode head) {
    cout << head->info << ' ';
    if (head->next) {
        output_rec(head->next);
    }
}

void del_list_rec(pnode head) {
    if (!head) {
        return;
    }
    del_list_rec(head->next);
    delete head;
}

int number_of_elem_rec(pnode head) {
    if (!head) {
        return 0;
    }
    return 1 + number_of_elem_rec(head->next);
} 

pnode form_link_list_rec() {
    pnode head = new tnode;
    int info;
    cout << "Enter info: " << endl;
    cin >> info;
    head->info = info;
    cout << "Do you want to add more elements?" << endl;
    cout << "Yes - 1, no - other symbol" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {
        head->next = form_link_list_rec();
    } else {
        head->next = nullptr;
    }
    return head;
}

void add_elem_rec_after(pnode head, int info_of_el) {
    if (!head) {
        return;
    }
    if (head->info == info_of_el) {
        pnode new_el = new tnode;
        cout << "Enter info of new info: " << endl;
        cin >> new_el->info;
        new_el->next = head->next;
        head->next = new_el;
        return;
    } else {
        add_elem_rec_after(head->next, info_of_el);
    }
}

void add_elem_rec_before(pnode& head, int info_of_el, pnode prev) {
    if (!head) {
        return;
    }
    if (head->info == info_of_el) {
        pnode new_el = new tnode;
        cout << "Enter info of new info: " << endl;
        cin >> new_el->info;
        new_el->next = head;
        if (prev) {
            prev->next = new_el;
        } else {
            head = new_el;
        }
        return;
    } else {
        add_elem_rec_before(head->next, info_of_el, head);
    }
}

void del_el_rec(pnode& head, int info_to_del, pnode prev) {
    if (!head) {
        return;
    }
    if (head->info == info_to_del) {
        if (!prev) {
            pnode temp = head;
            head = head->next;
            delete temp;
        } else {
            prev->next = head->next;
            delete head;
        }
        return;
    }
    del_el_rec(head->next, info_to_del, head);
}

int main() {
    pnode head = nullptr;
    int info_of_el;
    bool flag = true;
    int choice;
    int number_of_elem;
    while(flag) {
        number_of_elem = number_of_elem_rec(head);
        cout << "\nMenu:" << endl;
        cout << "1) Creating list" << endl;
        if (number_of_elem > 0) {
            cout << "2) Number of elements" << endl;
            cout << "3) Output list" << endl;
            cout << "4) Add element before the given one" << endl;
            cout << "5) Add element after the given one" << endl;
            cout << "6) Delete the given one element" << endl;
        } else { 
            cout << "2)" << endl;
            cout << "3)" << endl;
            cout << "4)" << endl;
            cout << "5)" << endl;
            cout << "6)" << endl;
        }
        cout << "7) Exit" << endl;
        cin >> choice;
        if (number_of_elem == 0 && choice > 1 && choice < 7) {
            choice = -1;
        }
        switch(choice) {
            case 1: 
                head = form_link_list_rec();
                break;
            case 2:
                cout << "Lest contains " << number_of_elem_rec(head) << " elements." << endl;
                break;
            case 3:
                output_rec(head);
                break;
            case 4:
                cout << "Enter info of element: " << endl;
                cin >> info_of_el;
                add_elem_rec_before(head, info_of_el);
                break;
            case 5:
                cout << "Enter info of element: " << endl;
                cin >> info_of_el;
                add_elem_rec_after(head, info_of_el);
                break;
            case 6:
                cout << "Enter info of element: " << endl;
                cin >> info_of_el;
                del_el_rec(head, info_of_el);
                break;
            case 7:
                del_list_rec(head);
                cout << "Program finished successfully." << endl;
                flag = false;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
