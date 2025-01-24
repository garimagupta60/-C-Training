
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

struct node* deleteMiddle(struct node* head) {
     if(head->next==NULL || head==NULL){
        free(head);
        return NULL;
    }
    struct node* slow = head;
    struct node* fast = head;
    struct node* prev = slow;
    while(fast && fast->next){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    } 
    prev->next = slow->next;
    free(slow);
    return head;
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

    head = deleteMiddle(head);
    printf("\nList After deletion:\n");
    displaylist(head);

   
    return 0;
}
