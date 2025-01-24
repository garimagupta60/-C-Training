#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;

node* createnode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void insertnode(int value){
    node* newnode = createnode(value);
    if(head == NULL){
        head = newnode;
        return;
    }
    else{
        node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}
void display(){
    node* current = head;
    while(current!=NULL){
        if(current->next!=NULL){
            printf("%d ",current->data);
        }else{
            printf("%d",current->data);
        }
        current=current->next;
    }
}

void removenode(node* node_to_remove){
    node* temp = node_to_remove->next;
    node_to_remove->data = temp->data;
    node_to_remove->next = temp->next;
    free(temp);
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
}