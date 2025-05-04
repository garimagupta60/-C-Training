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

void remove_k_node(int k){
    struct node* current = head;
    struct node* prev = NULL;
    if(head==NULL || k<=0){
        return head;
    }
    int count=0;
    while(current!=NULL){
        count++;
        if(count%k==0){
            if(prev!=NULL){

                prev->next = current->next;
                free(current);
                current = prev->next;
            }else{
                head = current->next;
                free(current);
                current = head;
            }
        }else{
            prev = current;
            current=current->next;
        }
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

    int k = 0;
    printf("Enter k: ");
    scanf("%d",&k);

    remove_k_node(k);
    displaylist(head);
    return 0;
}