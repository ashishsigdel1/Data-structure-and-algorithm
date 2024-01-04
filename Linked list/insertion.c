#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkListTransversal(struct Node*ptr) {
    while (ptr != NULL)
    {
        printf("Number : %d\n", ptr->data);
        ptr = ptr -> next;
    }
    
}

struct Node * insertAtFirst (struct Node *head , int data){
    struct Node* ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct Node * insertAtEnd (struct Node *head , int data){
    struct Node* ptr = (struct Node *) malloc (sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }

    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct Node * insertAtIndex (struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *) malloc (sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p  = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main() {

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*) malloc (sizeof (struct Node));
    second = (struct Node*) malloc (sizeof (struct Node));
    third = (struct Node*) malloc (sizeof (struct Node));
    fourth = (struct Node*) malloc (sizeof (struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

linkListTransversal(head);
// head = insertAtFirst(head , 0);
// head = insertAtIndex(head, 10, 3);
head = insertAtEnd(head, 10);
printf("After insertion: \n");
linkListTransversal(head);
    return 0;
}
