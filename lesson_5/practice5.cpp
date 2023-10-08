#include <iostream>
#include "two_sided_list.h"
#include "two_sided_list.cpp"

using namespace std;

int main() {
    pnode start = new tnode;
    start->info = NULL;
    start->prev = nullptr;
    pnode end = new tnode;
    end->info = NULL;
    end->next = nullptr;
    start->next = end;
    end->prev = start;
    int choice;
    bool flag = true;
    int n;
    int info;
    while(flag) {
        n = count_el(start);
        cout << "Menu" << endl;
        cout << "1. Creating list" << endl;
        if (n > 0) {
            cout << "2. Output primary list" << endl;
            cout << "3. Output reverse list" << endl;
            cout << "4. Add element before the given one" << endl;
            cout << "5. Add element after the given one" << endl;
            cout << "6. Delete the given one element" << endl;
            cout << "7. Check symmetry" << endl;
        } else {
            cout << "2. " << endl;
            cout << "3. " << endl;
            cout << "4. " << endl;
            cout << "5. " << endl;
            cout << "6. " << endl;
            cout << "7. " << endl;
        }
        cout << "8. Exit" << endl;
        cin >> choice;
        if (n == 0 && choice > 1 && choice < 8) {
            choice = -1;
        }
        switch(choice) {
            case 1:
                forming_list(start, end);
                break;
            case 2:
                output_primary(start);
                break;
            case 3:
                output_reverse(end);
                break;
            case 4:
                cout << "Enter info of element: " << endl;
                cin >> info;
                add_el_before(start, info);
                break;
            case 5:
                cout << "Enter info of element: " << endl;
                cin >> info;
                add_el_after(start, info);
                break;
            case 6:
                cout << "Enter info of element you want to delete: " << endl;
                cin >> info;
                del_el(start, info);
                break;
            case 7:
                symmetry(start, end);
                break;
            case 8:
                del_list(start, end);
                cout << "Thank you for using this program." << endl;
                flag = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } 
    return 0;
}
