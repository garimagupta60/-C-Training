#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;
node* evenhead = NULL;
node* eventail = NULL;
node* oddhead = NULL;
node* oddtail = NULL;


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

void separate(){
    if(head == NULL || head->next == NULL){
        return;
    }
    node* current = head;
    while(current!=NULL){
        if(current->data % 2 == 0){
            if(evenhead == NULL){
                evenhead = current;
                eventail = evenhead;
            }else{
                eventail->next = current;
                eventail = eventail->next;
            }
        }
        else{
            if(oddhead == NULL){
                oddhead = current;
                oddtail = oddhead;
            }else{
                oddtail->next = current;
                oddtail = oddtail->next;
            }
        }
        current = current->next;
    }
    if(evenhead!=NULL){
        head = evenhead;
        eventail->next = oddhead;
    }else{
        head = oddhead;
    }
    if(oddhead!=NULL){
        oddtail->next = NULL;
    }
}

void separate_indices(){
    node* evenindex = NULL;
    node* evenend = NULL;
    node* oddindex = NULL;
    node* oddend = NULL;
    int i=0;
    node* temp = head;
    while(temp!=NULL){
        if(i%2 == 0){
            if(evenindex == NULL){
                evenindex = temp;
                evenend = evenindex;
            }else{
                evenend->next = temp;
                evenend = evenend->next;
            }
        }else{
            if(oddindex == NULL){
                oddindex = temp;    
                oddend = oddindex;
            }else{
                oddend->next = temp;
                oddend = oddend->next;
            }
        }
        temp = temp->next;
        i++;
    }
    head = evenindex;
    evenend->next = oddindex;
    oddend->next = NULL;
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

    printf("Initial list\n");
    display();
    printf("\nData separated list\n");
    separate();
    display();

    printf("\nIndex separated list\n");
    separate_indices();
    display();

    return 0;

}