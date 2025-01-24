#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;
node* createNode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void createCircularList(int value){
    node* newnode = createNode(value);
    if(head == NULL){
        head = newnode;
        newnode->next = newnode;
    }else{
        node* current = head;
        while(current->next!=head){
            current = current->next;
        }
        current->next = newnode;
        newnode->next = head;
    }
}

void removePerson(int k){
    node* temp=head;
    while(temp->next!=temp){
        for(int i=1; i<k-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp = temp->next;
    }
    head = temp;
}

void display(){
    node* current = head;
    while(current->next!=head){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("%d ",current->data);
}

int main(){

    printf("Enter the list\n");
    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        createCircularList(value);
        int ch = getchar();
        if(ch == '\n' || ch == EOF)break;
    }

    int k;
    printf("Enter the value of K\n");
    scanf("%d",&k);

    display();
    removePerson(k);
    printf("\n");
    display();
    return 0;
}