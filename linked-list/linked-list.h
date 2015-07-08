#include <stdlib.h>

typedef struct ListNodeStruct ListNode;
struct ListNodeStruct {
    char value;
    ListNode* nextNode;
};

ListNode* createLinkedList() {
    ListNode* listHead = (ListNode*)malloc(sizeof(ListNode));
    listHead->value = 'A';

    ListNode* currNode = listHead;
    for(int i = 0; i < 6; i++) {
        ListNode* nextNode = (ListNode*)malloc(sizeof(ListNode));
        nextNode->value = currNode->value + 1;

        currNode->nextNode = nextNode;
        currNode = nextNode;
    }

    return listHead;
}

void printLinkedList(ListNode* listHead) {
    while(listHead) {
        printf("%c ", listHead->value);
        listHead = listHead->nextNode;
    }
    printf("\n");
}
