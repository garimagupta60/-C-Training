#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;

node* createnode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
} 
  
void insertnode(int value){
    node* newnode = createnode(value);
    if(head==NULL){
        head = newnode;
        return;
    }else{
        node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}
node* reverse(node* head, int k){
    if(head == NULL || head->next == NULL){
        return head;
    }
    int count = 0;
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    while(current!=NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next!=NULL){
        head->next = reverse(next,k);
    }
    return prev;
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

int main(){
    printf("Enter the list\n");
    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        insertnode(value);
        int ch = getchar();
        if(ch == '\n' || ch == EOF) break;
    }

    int k;
    printf("Enter the value of K\n");
    scanf("%d",&k);

    display();
    head = reverse(head,k);
    printf("\n");
    display();

    return 0;

}