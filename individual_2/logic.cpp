//logic.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include "header.h"

using namespace std;

Tree builtTree(const char* filename) {
    Tree root = nullptr;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error while opening file" << endl;
    }

    const int length_line = 10;
    char line[length_line];

    if (file.getline(line, length_line)) {
        root = new TreeNode;
        root->info = new char[2];
        strncpy(root->info, line + 2, 1);
        root->info[1] = '\0';

        Tree leftNode = new TreeNode;
        leftNode->info = new char[2];
        strncpy(leftNode->info, line + 1, 1);
        leftNode->info[1] = '\0';

        root->left = leftNode;
        leftNode->left = nullptr;
        leftNode->right = nullptr;

        Tree subRoot = new TreeNode;
        subRoot->info = new char[2];
        strncpy(subRoot->info, line + 5, 1);  // Copy the characters at position 5 and 6
        subRoot->info[1] = '\0';

        Tree leftChild = new TreeNode;
        leftChild->info = new char[2];
        strncpy(leftChild->info, line + 4, 1);  // Copy the characters at position 4 and 5
        leftChild->info[1] = '\0';

        leftChild->left = nullptr;
        leftChild->right = nullptr;

        Tree rightChild = new TreeNode;
        rightChild->info = new char[2];
        strncpy(rightChild->info, line + 6, 1);  // Copy the characters at position 7 and 8
        rightChild->info[1] = '\0';

        rightChild->left = nullptr;
        rightChild->right = nullptr;

        subRoot->left = leftChild;
        subRoot->right = rightChild;

        root->right = subRoot;
    }

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
    cout << root->left->info;
    cout << root->info;
    cout << '(' << root->right->left->info << root->right->info << root->right->right->info << ')';
}

int getNumber(char* s) {
    if (strcmp(s, "0") == 0) {
        return 0;
    } else if (strcmp(s, "1") == 0) {
        return 1;
    } else if (strcmp(s, "2") == 0) {
        return 2;
    } else if (strcmp(s, "3") == 0) {
        return 3;
    } else if (strcmp(s, "4") == 0) {
        return 4;
    } else if (strcmp(s, "5") == 0) {
        return 5;
    } else if (strcmp(s, "6") == 0) {
        return 6;
    } else if (strcmp(s, "7") == 0) {
        return 7;
    } else if (strcmp(s, "8") == 0) {
        return 8;
    } 
    return 9;
}

int getAnswer(Tree root) {
    int n1 = getNumber(root->left->info);
    int n2 = getNumber(root->right->left->info);;
    int n3 = getNumber(root->right->right->info);;
    int preResult;
    if (strcmp((root->right->info), "+") == 0) {
        preResult = n2 + n3;
    } else if (strcmp((root->right->info), "-") == 0) {
        preResult = n2 - n3;
    } else {
        preResult = n2 * n3;
    }
    if (strcmp((root->info), "+") == 0) {
        return n1 + preResult;
    }
    if (strcmp((root->info), "-") == 0) {
        return n1 - preResult;
    }
    return n1 * preResult;
}
