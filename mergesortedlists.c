#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;


node* createNode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data= value;
    newnode->next = NULL;
    return newnode;
}

node* insertnode(node* head, int value){
    node* newnode = createNode(value);
    if(head==NULL){
        head = newnode;
        return head;
    }else{
        node* current = head;
        while(current->next!=NULL){
            current= current->next;
        }
        current->next = newnode;
    }
    return head;
}
node* merge(node* head1, node* head2){
    node* ans = createNode(-1);
    node* temp = ans;
    node* current = head1;
    node* current2 = head2;
    while(current!=NULL && current2!=NULL){
        if(current->data <= current2->data){
            temp->next = current;
            temp = temp->next;
            current =  current->next;
        }else{
            temp->next = current2;
            temp = temp->next;
            current2 =  current2->next;
        }
    }

    if(current){
        temp->next = current;
    }
    if(current2){
        temp->next = current2;
    }

    return ans->next;
}

void displaylist(node* head){
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
    node* head1 = NULL;
    node* head2 = NULL;
    
    node* head = NULL;
    printf("Enter the list1\n");
    while(1){
        int value;
        if(scanf("%d",&value)!=1)
            break;
        head1 = insertnode(head1,value);
        int ch = getchar();
        if(ch == '\n' || ch == EOF){
            break;
        }
        
    }

    printf("Enter the list2\n");
    while(1){
        int value;
        if(scanf("%d",&value)!=1)
            break;
        head2 = insertnode(head2,value);
        int ch = getchar();
        if(ch == '\n' || ch == EOF){
            break;
        }
        
    }

    printf("List1\n");
    displaylist(head1);
    printf("List2\n");
    displaylist(head2);
    head = merge(head1, head2);

    printf("Merged list\n");
    displaylist(head);
}