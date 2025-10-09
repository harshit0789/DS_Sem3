// AQ4_reverse_list.c
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int d){ struct Node* n = malloc(sizeof(struct Node)); if(!n){ perror("malloc"); exit(EXIT_FAILURE);} n->data=d; n->next=NULL; return n; }

void push_end(struct Node** headRef, int data){ struct Node* n = createNode(data); if(*headRef==NULL){*headRef=n; return;} struct Node* cur=*headRef; while(cur->next) cur=cur->next; cur->next=n; }

void reverseList(struct Node** headRef){
    struct Node* prev = NULL;
    struct Node* cur = *headRef;
    while(cur){
        struct Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *headRef = prev;
}

void printList(struct Node* head){ while(head){ printf("%d -> ", head->data); head=head->next; } printf("NULL\n"); }

void freeList(struct Node** headRef){ struct Node* cur=*headRef; while(cur){ struct Node* nxt=cur->next; free(cur); cur=nxt;} *headRef=NULL; }

int main(){
    struct Node* head = NULL;
    push_end(&head, 1);
    push_end(&head, 2);
    push_end(&head, 3);
    push_end(&head, 4);
    printf("Original list:\n"); printList(head);
    reverseList(&head);
    printf("Reversed list:\n"); printList(head);
    freeList(&head);
    return 0;
}
