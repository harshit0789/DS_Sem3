// delete_node.c
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int d){
    struct Node* n = malloc(sizeof(struct Node));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = d; n->next = NULL; return n;
}

void push_front(struct Node** headRef, int data){
    struct Node* n = createNode(data); n->next = *headRef; *headRef = n;
}

void deleteNode(struct Node** headRef, int key){
    struct Node* cur = *headRef;
    struct Node* prev = NULL;
    while(cur && cur->data != key){ prev = cur; cur = cur->next; }
    if (!cur) return; /* not found */
    if (!prev){ *headRef = cur->next; free(cur); return; }
    prev->next = cur->next; free(cur);
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
    printf("Before deleteNode(20):\n"); printList(head);
    deleteNode(&head, 20);
    printf("After deleteNode(20):\n"); printList(head);
    freeList(&head);
    return 0;
}
