#include <iostream>

struct t_tree {
    int info;
    t_tree* left;
    t_tree* right;
};

using namespace std;
typedef t_tree* ptree;

ptree formTree(); // функція формування бінарного дерева
int findNodes(ptree node, int info_to_comp); // функція пошуку елементів рівних заданому
void directOrder(ptree node); // виведення дерева у прямому порядку
void symmetricalOrder(ptree node); // виведення дерева у симетричному порядку
void reversedOrder(ptree node); // виведення дерева у зворотньому порядку


ptree formTree() {
    ptree new_node;
    int info;
    cin >> info;
    if (!info) {
        return nullptr;
    }
    new_node = new t_tree;
    new_node->info = info;
    new_node->left = formTree();
    new_node->right = formTree();
    return new_node;
}

int findNodes(ptree node, int info_to_comp) {
    int counter = 0;
    if (node->info == info_to_comp) {
        counter++;
    }
    if (node->left){
        counter += findNodes(node->left, info_to_comp);
    }
    if (node->right) {
        counter += findNodes(node->right, info_to_comp);
    }
    return counter;
}

void directOrder(ptree node) {
    if (node) {
        cout << node->info << ' ';
        directOrder(node->left);
        directOrder(node->right);
    }
}

void symmetricalOrder(ptree node) {
    if (node) {
        symmetricalOrder(node->left);
        cout << node->info << ' ';
        symmetricalOrder(node->right);
    }
}

void reversedOrder(ptree node) {
    if (node) {
        reversedOrder(node->left);
        reversedOrder(node->right);
        cout << node->info << ' ';
    }
}

int main() {
    ptree main_node;
    main_node = formTree();
    int info;
    cout << endl << "Enter info to compare: " << endl;
    cin >> info;
    cout << endl << "In your tree " << findNodes(main_node, info) << " item(s) with value " << info << "." << endl;
    cout << "In direct order: ";
    directOrder(main_node);
    cout << endl;
    cout << "In symmetrical order: ";
    symmetricalOrder(main_node);
    cout << endl;
    cout << "In reversed order: ";
    reversedOrder(main_node);
    return 0;
}