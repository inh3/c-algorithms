#include <stack>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
using namespace std;

int isBalancedRecursive(struct TreeNode* treeNode);
bool isLeafBalancedIterative(struct TreeNode* treeNode);

int main() {
    printf("IS THE THREE BALANCED?\n");

    struct TreeNode* rootNode = createTree();
    printf("Unbalanced Recursive: %d\n", isBalancedRecursive(rootNode));

    struct TreeNode* balancedRootNode = createBalancedTree();
    printf("Balanced Recursive: %d\n", isBalancedRecursive(balancedRootNode));

    printf("\n");

    struct TreeNode* leafUnbalancedRootNode = createLeafUnbalancedTree();
    printf("Leaf Balanced: %u\n", isLeafBalancedIterative(balancedRootNode));
    printf("Leaf Unbalanced: %u\n", isLeafBalancedIterative(leafUnbalancedRootNode));

    return 0;
}

int isBalancedRecursive(struct TreeNode* treeNode) {

    // there is no node so it is balanced
    if(!treeNode) {
        return 0;
    }

    int leftHeight = isBalancedRecursive(treeNode->leftNode);
    int rightHeight = isBalancedRecursive(treeNode->rightNode);

    if(leftHeight == -1 || rightHeight == -1) {
        return -1;
    }

    int heightDiff = abs(leftHeight - rightHeight);

    // the heights differ by too much
    if(heightDiff > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

// this is not for actual balanced tree
// this is for only if the leaf levels are not balanced
//
// A tree is "superbalanced" if the difference between the depths
// of any two leaf nodes is no greater than one.
bool isLeafBalancedIterative(struct TreeNode* treeNode) {

    stack<TreeNode*> nodeStack;
    stack<int> nodeDepth;
    set<int> depthSet;

    nodeStack.push(treeNode);
    nodeDepth.push(0);

    while(!nodeStack.empty()) {

        struct TreeNode* currNode = nodeStack.top();
        int currDepth = nodeDepth.top();
        nodeStack.pop();
        nodeDepth.pop();

        // have found a leaf
        if(!currNode->leftNode && !currNode->rightNode) {

            // this is a new depth
            set<int>::iterator depthIterator = depthSet.find(currDepth);
            if(depthIterator == depthSet.end()) {

                // add the depth because it is a new depth
                depthSet.insert(currDepth);

                // there are more than 3 unique depths OR
                // the two depths are different in size by 1
                if(depthSet.size() > 2 ||
                    (depthSet.size() == 2 &&
                        (*(depthSet.begin()) - *(++depthSet.begin()) > 1))) {
                    return false;
                }
            }
        }
        // not a leaf so add it to the stack with its new depth
        else {
            if(currNode->leftNode) {
                nodeStack.push(currNode->leftNode);
                nodeDepth.push(currDepth + 1);
            }
            if(currNode->rightNode) {
                nodeStack.push(currNode->rightNode);
                nodeDepth.push(currDepth + 1);
            }
        }
    }

    return true;
}
