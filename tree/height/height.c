#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

#define max(a,b) (((a) > (b)) ? (a) : (b))

unsigned int treeHeight(struct TreeNode* root);

int main() {

    struct TreeNode* rootNode = createTree();
    printf("TREE HEIGHT: %u\n", treeHeight(rootNode));
    return 0;
}

unsigned int treeHeight(struct TreeNode* root) {
    if(!root)
        return 0;
    return 1 + max(treeHeight(root->leftNode), treeHeight(root->rightNode));
}
