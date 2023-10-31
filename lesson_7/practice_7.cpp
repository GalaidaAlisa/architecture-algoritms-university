#include <iostream>
#include <cstring>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int mark;
    char* name;
};

typedef TreeNode* Tree;
using namespace std;

Tree Insert(Tree root, char* name, int mark) {
    if (!root) {
        root = new TreeNode;
        root->left = nullptr;
        root->right = nullptr;
        root->name = new char[strlen(name) + 1];
        strcpy(root->name, name);
        root->mark = mark;

        return root;
    }
    if (mark < root->mark) {
        root->left = Insert(root->left, name, mark);
    } else if (mark > root->mark) {
        root->right = Insert(root->right, name, mark);
    }
    return root;
}

Tree BuiltTree() {
    Tree root = nullptr;
    int mark;
    char name[100];
    bool flag = true;
    int choice;

    while (flag) {
        cout << "Do you want to add new student?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student`s name: ";
                cin >> name;
                cout << "Enter student`s mark: ";
                cin >> mark;
                root = Insert(root, name, mark);
                break;
            case 2:
                cout << "All students added successfully!" << endl;
                flag = false;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return root;
}

void InOrderTraversal(Tree root) {
    if (!root) {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->name << " - " << root->mark << endl;
    InOrderTraversal(root->right);
}

void StudentsWithBadMark(Tree root, int mark) {
    if (!root) {
        return;
    }
    StudentsWithBadMark(root->left, mark);
    if (root->mark < mark) {
        cout << root->name << " - " << root->mark << endl;
    }
    StudentsWithBadMark(root->right, mark);
}

Tree FindMinRight(Tree root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

Tree RemoveStudent(Tree root, char* name, int mark) {
    if (!root) {
        return root;
    }

    if (root->mark < mark) {
        root->right = RemoveStudent(root->right, name, mark);
    } else if (root->mark > mark) {
        root->left = RemoveStudent(root->left, name, mark);
    } else if (strcmp(root->name, name) == 0) {
        if (root->right && root->left) {
            Tree min = FindMinRight(root->right);
            root->mark = min->mark;
            root->name = new char[strlen(min->name) + 1];
            strcpy(root->name, min->name);
            root->right = RemoveStudent(root->right, min->name, min->mark);
        } else {
            Tree temp = root;
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
            delete temp;
        }
    }

    return root;
}

void DeleteTree(Tree root) {
    if (!root) {
        return;
    }

    DeleteTree(root->left);
    DeleteTree(root->right);

    delete root;
}

int main() {
    Tree root = BuiltTree();
    bool flag = true;
    int choice;
    char name[100];
    int mark;

    while (flag) {
        cout << "MENU:" << endl;
        cout << "1. Output students in-order" << endl;
        cout << "2. Add new student" << endl;
        cout << "3. Remove student by name & mark" << endl;
        cout << "4. Output students with mark less than given" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;


        switch (choice)
        {
            case 1:
                InOrderTraversal(root);
                break;
            case 2:
                cout << "Enter new student`s name: ";
                cin >> name;
                cout << "Enter new student`s mark: ";
                cin >> mark;
                root = Insert(root, name, mark);
                break;
            case 3:
                cout << "Enter new student`s name: ";
                cin >> name;
                cout << "Enter new student`s mark: ";
                cin >> mark;
                root = RemoveStudent(root, name, mark);
                break;
            case 4:
                cout << "Enter mark: ";
                cin >> mark;
                cout << "Students with mark, less than " << mark << ":" << endl;
                StudentsWithBadMark(root, mark);
                break;
            case 5:
                cout << "Program has been finished successfully!";
                flag = false;
                DeleteTree(root);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}
