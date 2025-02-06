#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;
node* head1 = NULL;
node* head2 = NULL;

node* createNode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertnode(int value){
    node* newnode = createNode(value);
    if(head == NULL){
        head = newnode;
        newnode->next = newnode;
    }else{
        node* current = head;
        while(current->next != head){
            current = current->next;
        }
        newnode->next = head;
        current->next = newnode;
    }
    return;
}

void displaylist(node* head){
    node* current = head;
    if(head==NULL){
        printf("Empty list\n");
        return ;
    }
    while(current->next!=head){
        if(current->next!=head){
            printf("%d ",current->data);
        }else{
            printf("%d",current->data);
        }
        current = current->next;
    }
    printf("%d",current->data);
}

void splitList(){
    if(head == NULL || head->next == NULL){
        head1 = head;
        head2 = NULL;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast->next!=head && fast->next->next!=head){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next->next==head){
        fast=fast->next;
        slow = slow->next;
    }
    head1 = head;
    head2 = slow->next;
    fast->next = head2;
    slow->next = head1;
}
int main(){
    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        insertnode(value);
        int ch = getchar();
        if(ch == '\n' || ch == EOF){
            break;
        }
    }

    printf("Original list: ");
    displaylist(head);

    splitList();

    printf("\nSplit lists: ");
    displaylist(head1);
    printf("\n");

    displaylist(head2);

    return 0;
}