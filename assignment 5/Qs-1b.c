// push_end.c
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int d){
    struct Node* n = malloc(sizeof(struct Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = d; n->next = NULL; return n;
}

void push_end(struct Node** headRef, int data){
    struct Node* n = createNode(data);
    if (*headRef == NULL) { *headRef = n; return; }
    struct Node* cur = *headRef;
    while(cur->next) cur = cur->next;
    cur->next = n;
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
    push_end(&head, 30);
    push_end(&head, 20);
    push_end(&head, 10);
    printf("After push_end calls:\n");
    printList(head);
    freeList(&head);
    return 0;
}
