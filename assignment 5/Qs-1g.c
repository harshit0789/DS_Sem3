// show_position.c
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int d){
    struct Node* n = malloc(sizeof(struct Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = d; n->next = NULL; return n;
}

void push_front(struct Node** headRef, int data){ struct Node* n = createNode(data); n->next = *headRef; *headRef = n; }

void showPosition(struct Node* head, int key){
    int pos = 0;
    while(head && head->data != key){ head = head->next; pos++; }
    if (!head) printf("Key %d not found\n", key);
    else printf("Position from head (0-based) of %d: %d\n", key, pos);
}

void printList(struct Node* head){ while(head){ printf("%d -> ", head->data); head = head->next; } printf("NULL\n"); }

void freeList(struct Node** headRef){
    struct Node* cur = *headRef;
    while(cur){ struct Node* nxt = cur->next; free(cur); cur = nxt; }
    *headRef = NULL;
}

int main(){
    struct Node* head = NULL;
    push_front(&head, 30);
    push_front(&head, 20);
    push_front(&head, 10);
    push_front(&head, 5); // 5->10->20->30
    printList(head);
    showPosition(head, 20);
    showPosition(head, 99); // not found
    freeList(&head);
    return 0;
}
