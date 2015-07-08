#include <stdio.h>
#include "linked-list.h"

ListNode* reverseIterative(ListNode* listHead);
ListNode* reverseRecursive(ListNode* listNode);

int main() {

    ListNode* listHead = createLinkedList();
    printf("ORIGINAL LINKED LIST: ");
    printLinkedList(listHead);

    printf("REVERSE LINKED LIST - Iterative: ");
    printLinkedList(reverseIterative(listHead));

    printf("REVERSE LINKED LIST - Iterative: ");
    ListNode* otherListHead = createLinkedList();
    printLinkedList(reverseRecursive(otherListHead));
    return 0;
}

ListNode* reverseIterative(ListNode* listHead) {

    ListNode* currNode = listHead;
    ListNode* prevNode = NULL;
    ListNode* tempNode = NULL;

    if(!currNode)
        return currNode;

    while(currNode) {
        tempNode = currNode->nextNode;
        currNode->nextNode = prevNode;
        prevNode = currNode;
        currNode = tempNode;
    }

    return prevNode;
}

ListNode* reverseRecursive(ListNode* listNode) {

    if(!listNode || !listNode->nextNode) {
        return listNode;
    }

    ListNode* reverseNode = reverseRecursive(listNode->nextNode);
    listNode->nextNode->nextNode = listNode;
    listNode->nextNode = NULL;
    return reverseNode;
}
