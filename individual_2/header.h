//header.h
#ifndef INDIVIDUAL_TREES_HEADER_H
#define INDIVIDUAL_TREES_HEADER_H

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    char* info;
};

typedef TreeNode* Tree;

Tree builtTree(const char* filename);
void preOrderTraversal(Tree root);
void postOrderTraversal(Tree root);
void getFormula(Tree root);
int getNumber(char* s);
int getAnswer(Tree root);

#endif //INDIVIDUAL_TREES_HEADER_H
