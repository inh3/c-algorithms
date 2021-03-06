#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

struct TreeNode {

    struct TreeNode*    leftNode;
    struct TreeNode*    rightNode;
    char                value;
};

struct TreeNode* createTreeNode(char value) {
    struct TreeNode* treeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    memset(treeNode, 0, sizeof(struct TreeNode));
    treeNode->value = value;
    return treeNode;
}

struct TreeNode* createTree() {
    // root
    struct TreeNode* root = createTreeNode('F');

    // first level
    root->leftNode = createTreeNode('B');
    root->rightNode = createTreeNode('G');

    // second level
    root->leftNode->leftNode = createTreeNode('A');
    root->leftNode->rightNode = createTreeNode('D');
    root->rightNode->rightNode = createTreeNode('I');

    // third level
    root->leftNode->rightNode->leftNode = createTreeNode('C');
    root->leftNode->rightNode->rightNode = createTreeNode('E');
    root->rightNode->rightNode->leftNode = createTreeNode('H');

    return root;
}

struct TreeNode* createBalancedTree() {
    // root
    struct TreeNode* root = createTreeNode('F');

    // first level
    root->leftNode = createTreeNode('B');
    root->rightNode = createTreeNode('G');

    // second level
    root->leftNode->leftNode = createTreeNode('A');
    root->leftNode->rightNode = createTreeNode('D');
    root->rightNode->rightNode = createTreeNode('I');

    // third level
    root->leftNode->rightNode->leftNode = createTreeNode('C');
    root->leftNode->rightNode->rightNode = createTreeNode('E');

    return root;
}

struct TreeNode* createLeafUnbalancedTree() {
    // root
    struct TreeNode* root = createTreeNode('F');

    // first level
    root->leftNode = createTreeNode('B');
    root->rightNode = createTreeNode('G');

    // second level
    root->leftNode->leftNode = createTreeNode('A');
    root->leftNode->rightNode = createTreeNode('D');

    // third level
    root->leftNode->rightNode->leftNode = createTreeNode('C');
    root->leftNode->rightNode->rightNode = createTreeNode('E');

    return root;
}
