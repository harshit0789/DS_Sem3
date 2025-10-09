//insert_after.c
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int d){
    struct Node* n = malloc(sizeof(struct Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = d; n->next = NULL; return n;
}

void push_front(struct Node** headRef, int data){
    struct Node* n = createNode(data);
    n->next = *headRef; *headRef = n;
}

void insertAfter(struct Node* head, int key, int data){
    struct Node* cur = head;
    while(cur && cur->data != key) cur = cur->next;
    if (!cur){ printf("Key %d not found\n", key); return; }
    struct Node* n = createNode(data);
    n->next = cur->next; cur->next = n;
}

void printList(struct Node* head){
    while(head){ printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

void freeList(struct Node** headRef){
    struct Node* cur = *headRef;
    while(cur){ struct Node* nxt = cur->next; free(cur); cur = nxt; }
    *headRef = NULL;
}

int main(){
    struct Node* head = NULL;
    push_front(&head, 30);
    push_front(&head, 20);
    push_front(&head, 10); // list: 10->20->30
    printf("Before insert:\n"); printList(head);
    insertAfter(head, 20, 25); // insert 25 after 20
    printf("After insert 25 after 20:\n"); printList(head);
    freeList(&head);
    return 0;
}
