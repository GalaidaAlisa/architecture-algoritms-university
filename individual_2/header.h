#ifndef INDIVIDUAL_TREES_HEADER_H
#define INDIVIDUAL_TREES_HEADER_H

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    char info;
};

typedef TreeNode* Tree;

Tree builtTree(Tree root, char formula[]);
Tree getData(const char* filename);
void preOrderTraversal(Tree root);
void postOrderTraversal(Tree root);
void getFormula(Tree root);
int getNumber(char s);
int getAnswer(Tree root);
bool isSign(char s);
bool isNum(char s);
bool isValid(Tree root);

#endif //INDIVIDUAL_TREES_HEADER_H
