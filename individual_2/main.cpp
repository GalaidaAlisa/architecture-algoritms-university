//main.cpp
#include <iostream>
#include "header.h"
#include "logic.cpp"

int main() {
    Tree root = builtTree("data1.txt");
    cout << "Preorder traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postOrderTraversal(root);
    cout << endl;
    cout << "Formula: ";
    getFormula(root);
    cout << endl;
    cout << "Result of formula: ";
    cout << getAnswer(root);
    return 0;
}
