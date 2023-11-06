#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

struct Node {
    char info;
    Node* left;
    Node* right;
};

typedef Node* tree;

bool isSign(char c);
bool isNum(char c);
int charToInt(char c);
tree buildTree(const char* expression, int& index);
void inOrder(tree root);
double countResult(tree root);


bool isSign(char c) {
    if (c == '+' || c == '-' || c == '*') {
        return true;
    } else {
        return false;
    }
}

bool isNum(char c) {
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
        return true;
    } else {
        return false;
    }
}

int charToInt(char c) {
    if (c == '0') {
        return 0;
    }
    if (c == '1') {
        return 1;
    }
    if (c == '2') {
        return 2;
    }
    if (c == '3') {
        return 3;
    }
    if (c == '4') {
        return 4;
    }
    if (c == '5') {
        return 5;
    }
    if (c == '7') {
        return 7;
    }
    if (c == '8') {
        return 8;
    }
    return 9;
}

tree buildTree(const char* expression, int& index) {
    char c = expression[index];
    index++;

    if (c == '\0') {
        return nullptr;
    }

    if (isNum(c)) {
        tree node = new Node;
        node->info = c;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    } else if (isSign(c)) {
        tree newNode = new Node;
        newNode->info = c;
        newNode->left = buildTree(expression, index);
        newNode->right = buildTree(expression, index);
        return newNode;
    }

    return nullptr;
}

void inOrder(tree root) {
    if (root) {
        if (isSign(root->info)) {
            cout << "(";
            inOrder(root->left);
            cout << root->info;
            inOrder(root->right);
            cout << ")";
        } else {
            cout << root->info;
        }
    }
}

double countResult(tree root) {
    double result = 0;
    if (!root) { 
        return NULL;
    }
    if (isNum(root->info)) {
        return charToInt(root->info);
    }
    if (root->info == '*') {
        return countResult(root->left) * countResult(root->right);
    }
    if (root->info == '-') {
        return countResult(root->left) - countResult(root->right);
    }
    return countResult(root->left) + countResult(root->right);
}

int main() {
    char* input = new char;
    cout << "Enter expression: ";
    cin >> input;
    const char* expression = input;
    int index = 0;
    tree root = buildTree(expression, index);
    cout << "Formula:" << endl;
    inOrder(root);
    cout << endl;
    cout << "Result: " << countResult(root);
    return 0;
}
