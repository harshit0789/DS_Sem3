//find_middle.c
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int d){ struct Node* n = malloc(sizeof(struct Node)); if(!n){ perror("malloc"); exit(EXIT_FAILURE);} n->data=d; n->next=NULL; return n; }

void push_end(struct Node** headRef, int data){ struct Node* n = createNode(data); if(*headRef==NULL){*headRef=n; return;} struct Node* cur=*headRef; while(cur->next) cur=cur->next; cur->next=n; }

int findMiddle(struct Node* head){
    if (!head) { fprintf(stderr,"findMiddle: empty list\n"); exit(EXIT_FAILURE); }
    struct Node* slow = head;
    struct Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

void printList(struct Node* head){ while(head){ printf("%d -> ", head->data); head=head->next; } printf("NULL\n"); }

void freeList(struct Node** headRef){ struct Node* cur=*headRef; while(cur){ struct Node* nxt=cur->next; free(cur); cur=nxt;} *headRef=NULL; }

int main(){
    struct Node* head = NULL;
    push_end(&head, 1);
    push_end(&head, 2);
    push_end(&head, 3);
    push_end(&head, 4);
    push_end(&head, 5);
    printf("List: "); printList(head);
    printf("Middle element: %d\n", findMiddle(head)); // should print 3
    freeList(&head);
    return 0;
}
