// delete_end.c
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

void deleteEnd(struct Node** headRef){
    if (*headRef == NULL) return;
    if ((*headRef)->next == NULL){ free(*headRef); *headRef = NULL; return; }
    struct Node* cur = *headRef;
    while(cur->next->next) cur = cur->next;
    free(cur->next);
    cur->next = NULL;
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
    push_front(&head, 10); // 10->20->30
    printf("Before deleteEnd:\n"); printList(head);
    deleteEnd(&head);
    printf("After deleteEnd:\n"); printList(head);
    freeList(&head);
    return 0;
}
