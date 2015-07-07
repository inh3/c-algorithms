#include <queue>
#include <stack>
#include <stdio.h>
#include "tree.h"

void preOrder(struct TreeNode* root);
void inOrder(struct TreeNode* root);
void postOrder(struct TreeNode* root);
void levelOrder(struct TreeNode* root);
void levelOrderZigZag(struct TreeNode* root);
void levelOrderPrintByLevel(struct TreeNode* root);

int main() {
    struct TreeNode* rootNode = createTree();

    printf("PRE-ORDER: ");
    preOrder(rootNode);
    printf("\n");

    printf("IN-ORDER: ");
    inOrder(rootNode);
    printf("\n");

    printf("POST-ORDER: ");
    postOrder(rootNode);
    printf("\n");

    printf("LEVEL-ORDER: ");
    levelOrder(rootNode);
    printf("\n");

    printf("LEVEL-ORDER ZIG-ZAG: ");
    levelOrderZigZag(rootNode);
    printf("\n");

    printf("LEVEL-ORDER - Print by Level: \n");
    levelOrderPrintByLevel(rootNode);
    printf("\n");

    return 0;
}

void preOrder(struct TreeNode* root) {
    if(root == NULL)
        return;

    printf("%c ", root->value);

    preOrder(root->leftNode);
    preOrder(root->rightNode);
}

void inOrder(struct TreeNode* root) {
    if(root == NULL)
        return;

    inOrder(root->leftNode);

    printf("%c ", root->value);

    inOrder(root->rightNode);
}

void postOrder(struct TreeNode* root) {
    if(root == NULL)
        return;

    postOrder(root->leftNode);
    postOrder(root->rightNode);

    printf("%c ", root->value);
}

void levelOrder(struct TreeNode* root) {

    std::queue<struct TreeNode*> nodeQueue;

    if(root == NULL)
        return;

    nodeQueue.push(root);

    while(!nodeQueue.empty()) {

        struct TreeNode* currentNode = nodeQueue.front();

        if(currentNode->leftNode)
            nodeQueue.push(currentNode->leftNode);
        if(currentNode->rightNode)
            nodeQueue.push(currentNode->rightNode);

        printf("%c ", currentNode->value);
        nodeQueue.pop();
    }
}

void levelOrderPrintByLevel(struct TreeNode* root) {

    std::queue<struct TreeNode*> nodeQueue;
    std::queue<unsigned int> nodeLevelQueue;

    if(root == NULL)
        return;

    unsigned int currentLevel = 0;
    nodeQueue.push(root);
    nodeLevelQueue.push(0);

    while(!nodeQueue.empty()) {

        struct TreeNode* currentNode = nodeQueue.front();
        unsigned int nodeLevel = nodeLevelQueue.front();

        if(currentNode->leftNode) {
            nodeQueue.push(currentNode->leftNode);
            nodeLevelQueue.push(nodeLevel + 1);
        }
        if(currentNode->rightNode) {
            nodeQueue.push(currentNode->rightNode);
            nodeLevelQueue.push(nodeLevel + 1);
        }

        if(nodeLevel != currentLevel) {
            printf("\n");
            currentLevel = nodeLevel;
        }

        printf("%c ", currentNode->value);
        nodeQueue.pop();
        nodeLevelQueue.pop();
    }
}

void levelOrderZigZag(struct TreeNode* root) {

    std::stack<struct TreeNode*> rightToLeftStack;
    std::stack<struct TreeNode*> leftToRightStack;

    if(root == NULL)
        return;

    rightToLeftStack.push(root);

    while(!rightToLeftStack.empty() || !leftToRightStack.empty()) {

        while(!rightToLeftStack.empty()) {
            struct TreeNode* treeNode = rightToLeftStack.top();
            rightToLeftStack.pop();
            printf("%c ", treeNode->value);

            // last in, first out
            if(treeNode->rightNode)
                leftToRightStack.push(treeNode->rightNode);
            if(treeNode->leftNode)
                leftToRightStack.push(treeNode->leftNode);
        }

        while(!leftToRightStack.empty()) {
            struct TreeNode* treeNode = leftToRightStack.top();
            leftToRightStack.pop();
            printf("%c ", treeNode->value);

            // last in, first out
            if(treeNode->leftNode)
                rightToLeftStack.push(treeNode->leftNode);
            if(treeNode->rightNode)
                rightToLeftStack.push(treeNode->rightNode);
        }
    }

    std::stack<struct TreeNode*> nodeStack;

}
