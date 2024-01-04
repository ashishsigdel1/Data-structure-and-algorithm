#include <stdio.h>
#include <stdlib.h>

struct Node
{
   int data;
   struct Node* next;
};

void linkedListTransversal(struct Node*ptr) {
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    //Allocate memory for nodes in linked list in Heap
    head = (struct Node*) malloc (sizeof(struct Node));
    second = (struct Node*) malloc (sizeof(struct Node));
    third = (struct Node*) malloc (sizeof(struct Node));
    fourth = (struct Node*) malloc (sizeof(struct Node));

    //Link first and second
    head->data = 7;
    head->next = second;
    //Link second and third
    second->data = 47;
    second->next = third;
    //Link third and fourth
    third->data = 65;
    third->next = fourth;
    //terminate the linked list at last
    fourth->data = 74;
    fourth->next = NULL;

    linkedListTransversal(head);
}