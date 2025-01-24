#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->next = NULL;
    newnode->data = value;
    return newnode;
}
void displaylist(struct node* head){
    struct node* current = head;
    while(current!=NULL){
        if(current->next!=NULL){
            printf("%d->",current->data);
        }else{
            printf("%d->X",current->data);
        }
        current = current->next;
    }
}

//changinging original list
void reverseList(){
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

struct node* recurReverse(struct node* head){
    if(head == NULL || head->next ==NULL)return head;
    struct node* rest = recurReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
int main(){
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    printf("Initial List:\n");
    displaylist(head);

    printf("\nReversed Linked List:\n");
    reverseList();
    displaylist(head);

    printf("\nReversed Linked List Recursively:\n");
    struct node* reverseHead = recurReverse(head);
    displaylist(reverseHead);

    return 0;
}