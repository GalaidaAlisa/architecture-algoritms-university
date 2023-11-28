#include <iostream>
#include "sorted_set.cpp"

using namespace std;

int main() {
    int choice;
    int value;
    bool flag = true;
    SortedSet sorted_set;

    while (flag) {
        if (sorted_set.number_of_elem() == 0) {
            cout << "\n1. Add element to sorted set" << endl;
            cout << "2. " << endl;
            cout << "3. " << endl;
            cout << "4. " << endl;
            cout << "5. Finish program" << endl;
        } else {
            cout << "\n1. Add element to sorted set" << endl;
            cout << "2. Check is element exist in sorted set" << endl;
            cout << "3. Output sorted set" << endl;
            cout << "4. Delete element from sorted set" << endl;
            cout << "5. Finish program" << endl;
        }
        cout << "Your choice: ";
        cin >> choice;

        if (sorted_set.number_of_elem() == 0 && choice > 1 && choice < 5) {
            choice = -1;
        }
        switch (choice) {
        case 1:
            cout << endl;
            cout << "Enter value: ";
            cin >> value;
            sorted_set.insertInto(value);
            break;
        case 2:
            cout << endl;
            cout << "Enter value: ";
            cin >> value;
            if (sorted_set.isExistInSet(value)) {
                cout << "Value " << value << " exists in sorted set" << endl;
            } else {
                cout << "Value " << value << " is not exist in sorted set" << endl;
            }
            break;
        case 3:
            cout << endl;
            sorted_set.output();
            break;
        case 4:
            cout << endl;
            cout << "Enter value: ";
            cin >> value;
            sorted_set.deleteItem(value);
            break;
        case 5:
            cout << endl;
            flag = false;
            cout << "Program finished successfully!";
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
