//delete_occurrences.c
#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* createNode(int d){ struct Node* n = malloc(sizeof(struct Node)); if(!n){ perror("malloc"); exit(EXIT_FAILURE);} n->data=d; n->next=NULL; return n; }

void push_end(struct Node** headRef, int data){
    struct Node* n = createNode(data);
    if(*headRef==NULL){ *headRef = n; return; }
    struct Node* cur = *headRef; while(cur->next) cur = cur->next; cur->next = n;
}

int deleteOccurrences(struct Node** headRef, int key){
    int count = 0;
    /* remove matching heads */
    while(*headRef && (*headRef)->data == key){
        struct Node* tmp = *headRef;
        *headRef = tmp->next;
        free(tmp);
        count++;
    }
    struct Node* cur = *headRef;
    while(cur && cur->next){
        if (cur->next->data == key){
            struct Node* tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
            count++;
        } else cur = cur->next;
    }
    return count;
}

void printList(struct Node* head){ while(head){ printf("%d -> ", head->data); head=head->next; } printf("NULL\n"); }

void freeList(struct Node** headRef){ struct Node* cur=*headRef; while(cur){ struct Node* nxt=cur->next; free(cur); cur=nxt;} *headRef=NULL; }

int main(){
    struct Node* head = NULL;
    push_end(&head, 1);
    push_end(&head, 2);
    push_end(&head, 1);
    push_end(&head, 2);
    push_end(&head, 1);
    push_end(&head, 3);
    push_end(&head, 1);

    printf("Original list:\n"); printList(head);
    int key = 1;
    int removed = deleteOccurrences(&head, key);
    printf("Removed %d occurrences of %d\n", removed, key);
    printf("Updated list:\n"); printList(head);
    freeList(&head);
    return 0;
}
