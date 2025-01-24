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

void insertnode(){
    printf("\nEnter the value to insert\n");
    int value;
    scanf("%d",&value);
    struct node* newnode = createNode(value);
    if(head == NULL || head->data>value){
        newnode->next = head;
        head = newnode;
    }else{
        struct node* current = head;
        while(current->next!=NULL && current->next->data<value){
            current = current->next;
        }
        if(current->next != NULL){

            newnode->next = current->next;
        }
        current->next = newnode;
    }
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



int main(){
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    // int number_of_operations = 0;
    // scanf("%d",&number_of_operations);
    // while (number_of_operations>0)
    // {
    //     displaylist();
    //     insertnode();
    //     number_of_operations--;
    //     /* code */
    // }

    printf("Initial List:\n");
    displaylist(head);

    insertnode();
    printf("\nList After Insertion:\n");
    displaylist(head);

   
    return 0;
}
