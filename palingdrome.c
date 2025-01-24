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

void insertnode(int value){
    node* newnode = createNode(value);
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

node* findmiddle(node* head){
    node* slow = head;
    node* fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* reverse(node* head){
    node* current = head;
    node* prev = NULL;
    node* next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int isPalingdrome(node* head){
    if(head==NULL || head->next == NULL){
        return 1;
    }
    node* mid = findmiddle(head);
    node* list2Head = mid->next;
    mid->next = reverse(list2Head);
    node* temp = mid->next ;
    node* current = head;
    while(temp!=NULL){
        if(temp->data != current->data){
            return 0;
        }
        temp = temp->next;
        current=current->next;
    }
    return 1;
}

int main(){

    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        insertnode(value);
        int ch = getchar();
        if(ch=='\n' || ch== EOF){
            break;
        }
    }
    if(isPalingdrome(head)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}