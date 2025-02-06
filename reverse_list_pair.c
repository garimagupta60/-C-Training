#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node*  head = NULL;

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
        return;
    }else{
        node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

//Recurssive
node* reverse_in_pair(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    node* temp = head->next;
    head->next = temp->next;
    temp->next = head;
    head = temp;
    head->next->next = reverse_in_pair(head->next->next);
    return head;
}

//Iterative Approach
node* reverse(){
    node* temp1 = NULL;
    node* temp2 = NULL;
    node* current = head;
    while(current!=NULL && current->next!=NULL){
        if(temp1!=NULL){
            temp1->next->next = current->next;
        }
        temp1 = current->next;  
        current->next = temp1->next;
        temp1->next = current;
        if(temp2==NULL)
            temp2 = temp1;
        current = current->next;
    }
    return temp2;
}

void displaylist(){
    node* current = head;
    if(head==NULL){
        printf("Empty list\n");
        return ;
    }
    while(current!=NULL){
        if(current->next!=NULL){
            printf("%d->",current->data);
        }else{
            printf("%d",current->data);
        }
        current = current->next;
    }
}


int main(){
    while (1)
    {
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        insertnode(value);
        int ch = getchar();
        if(ch=='\n' || ch == EOF){
            break;
        }
    }

    printf("Original list: ");
    displaylist();

    head = reverse_in_pair(head);

    printf("Reversed list: ");

    displaylist();

    head = reverse(head);

    printf("Reversed list: ");

    displaylist();
    return 0;

    
}