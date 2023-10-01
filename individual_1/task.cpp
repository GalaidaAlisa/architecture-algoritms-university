#include <iostream>

using namespace std;

struct tnode {
    int info;
    tnode* next;
};

typedef tnode* pnode;

pnode form_link_list(); // формування списку
void output(pnode head); // вивід списку
pnode form_new_list(pnode head1, pnode head2); // функція створення списку який просять в умові
void delete_list(pnode head); // видалення списку

pnode form_link_list() { 
    pnode head = new tnode;
    head->next = nullptr;
    int inf;
    cout << "Enter info: ";
    cin >> inf;
    head->info = inf;
    int choice;
    pnode new_elem;
    pnode cur = head;
    while (true) {
        cout << "Do you want to add one more item?" << endl;
        cout << "1) Yes\n2) No" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter info: ";
            cin >> inf;
            new_elem = new tnode;
            new_elem->info = inf;
            new_elem->next = nullptr;
            cur->next = new_elem;
            cur = cur->next;
            break;
        case 2:
            return head;
        default: 
            cout << "Invalid choice." << endl;
        }
    }
}

void output(pnode head) { 
    while(head) {
        cout << head->info << " ";
        head = head->next;
    }
}

pnode form_new_list(pnode head1, pnode head2) {
    pnode new_head = nullptr;
    pnode cur = nullptr;
    pnode new_item;
    int cur_inf;
    
    pnode cur1 = head1;
    pnode cur2;
    
    while (cur1) {
        bool flag = false;
        cur2 = head2;
        cur_inf = cur1->info;
        
        while (cur2) {
            if (cur2->info == cur_inf) {
                flag = true;
                break;
            }
            cur2 = cur2->next;
        }
        
        if (!flag) {
            new_item = new tnode;
            new_item->info = cur_inf;
            new_item->next = nullptr;
            
            if (new_head == nullptr) {
                new_head = new_item;
                cur = new_head;
            } else {
                cur->next = new_item;
                cur = cur->next;
            }
        }
        
        cur1 = cur1->next;
    }
    
    return new_head;
}

void delete_list(pnode head) {
    while(head) {
        pnode temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    cout << "Creating the first list: " << endl;
    pnode el1 = form_link_list();
    cout << endl << "First list: " << endl;
    output(el1);
    cout << endl;
    cout << "Creating the second list: " << endl;
    pnode el2 = form_link_list();
    cout << endl << "Second list: " << endl;
    output(el2);
    cout << endl;
    pnode new_el = form_new_list(el1, el2);
    cout << endl << "Result list: " << endl;
    if (new_el == nullptr) {
        cout << "Result list is empty." << endl;
    } else {
        output(new_el);
    }
    delete_list(el1);
    delete_list(el2);
    delete_list(new_el);
    return 0;
}
