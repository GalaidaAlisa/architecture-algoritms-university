#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "header.h"

using namespace std;

bool isSign(char s) {
    return (s == '*' || s == '+' || s == '-');
}

bool isNum(char s) {
    return (s == '1' || s == '2' || s == '3' || s == '4' || s == '5' || s == '6' || s == '7' || s == '8' || s == '9' || s == '0');
}

Tree builtTree(Tree root, char formula[]) {
    int formula_length = strlen(formula);
    root = new TreeNode;
    root->left = nullptr;
    root->right = nullptr;
    if (!formula) {
        return nullptr;
    }
    if (strlen(formula) == 1) {
        root->info = formula[0];
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    if (formula[0] != '(' || formula[strlen(formula) - 1] != ')') {
        cerr << "Wrong formula!";
        exit(EXIT_FAILURE);
    }
    int parenthesis_counter = 0;
    int sign_index = 0;
    for (int i = 0; i < formula_length; i++) {
        if (parenthesis_counter == 1 && isSign(formula[i])) {
            sign_index = i;
            break;
        }
        if (formula[i] == '(') {
            parenthesis_counter++;
        }
        if (formula[i] == ')') {
            parenthesis_counter--;
        }
    }
    root->info = formula[sign_index];

    char left_side[sign_index];
    for (int i = 1; i < sign_index; i++) {
        left_side[i - 1] = formula[i];
    }
    left_side[sign_index - 1] = '\0';
    root->left = builtTree(root->left, left_side);

    char right_side[formula_length - sign_index - 1];
    for (int i = sign_index + 1, j = 0; i < formula_length - 1; i++, j++) {
        right_side[j] = formula[i];
    }
    right_side[formula_length - sign_index - 2] = '\0';
    root->right = builtTree(root->right, right_side);

    return root;
}

Tree getData(const char* filename) {
    Tree root = nullptr;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error while opening file" << endl;
        return root;
    }

    const int max_formula_length = 100; 
    char formula[max_formula_length];

    if (file.getline(formula, max_formula_length)) {
        root = builtTree(root, formula);
    }

    file.close(); // Close the file after reading

    return root;
}

void preOrderTraversal(Tree root) {
    if (!root) {
        return;
    }
    cout << root->info;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Tree root) {
    if (!root) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->info;
}

void getFormula(Tree root) {
    if (!root) {
        return;
    }
    if (isSign(root->info)) {
        cout << '(';
        getFormula(root->left);
        cout << root->info;
        getFormula(root->right);
        cout << ')';
    } else {
        getFormula(root->left);
        cout << root->info;
        getFormula(root->right);
    }
}

int getNumber(char s) {
    if (s == '0') {
        return 0;
    } else if (s == '1') {
        return 1;
    } else if (s == '2') {
        return 2;
    } else if (s == '3') {
        return 3;
    } else if (s == '4') {
        return 4;
    } else if (s == '5') {
        return 5;
    } else if (s == '6') {
        return 6;
    } else if (s == '7') {
        return 7;
    } else if (s == '8') {
        return 8;
    } 
    return 9;
}

int getAnswer(Tree root) {
    if (!isSign(root->info)) {
        return getNumber(root->info);
    }
    if (root->info == '+') {
        return getAnswer(root->left) + getAnswer(root->right);
    }
    if (root->info == '-') {
        return getAnswer(root->left) - getAnswer(root->right);
    }
    return getAnswer(root->left) * getAnswer(root->right);
}

bool isValid(Tree root) {
    if (!isNum(root->info) && !isSign(root->info)) {
        return false;
    }
    if (isNum(root->info)) {
        return root->left == nullptr && root->right == nullptr;
    }
    // root is sign
    return root->left != nullptr && root->right != nullptr;
}
