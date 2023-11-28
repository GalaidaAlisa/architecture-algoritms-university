#include <iostream>
#include "header.h"
#include "logic.cpp"

int main() {
    Tree root = getData("data.txt");
    if (!isValid(root)) {
        cerr << "Wrong formula!";
        return 0;
    }
    cout << "Preorder traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;
    cout << "Formula: " << endl;
    getFormula(root);
    cout << " = " << getAnswer(root);
    return 0;
}
