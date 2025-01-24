#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;
node* head1 = NULL;
node* addhead = NULL;

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
node* insertnode(node* head,int value){
    node* newnode = createnode(value);
    if(head==NULL){
        head = newnode;
    }else{
        node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newnode;
    }
    return head;
}

void display(node* head){
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

node* reverse(node* head){
    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void addlist(){
    node* temp1 = head;
    node* temp2 = head1;
    int carry = 0;
    while(temp1!=NULL && temp2!=NULL){
        int sum = temp1->data + temp2->data + carry;
        int value = sum%10;
        carry = sum/10;
        addhead = insertnode(addhead,value);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1){
        while(temp1!=NULL){
            int sum = temp1->data + carry;
            int value = sum%10;
            carry = sum/10;
            addhead = insertnode(addhead,value);
            temp1 = temp1->next;
        }
    }
    if(temp2){
        while(temp2!=NULL){
            int sum = temp2->data + carry;
            int value = sum%10;
            carry = sum/10;
            addhead = insertnode(addhead,value);
            temp2 = temp2->next;
        }
    }
    if(carry){
        insertnode(addhead,carry);        
    }

}
int main(){
    printf("Enter the list1\n");
    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        head = insertnode(head,value);
        int ch = getchar();
        if(ch == '\n' || ch == EOF) break;
    }

    printf("Enter the list2\n");
    while(1){
        int value;
        if(scanf("%d",&value)!=1){
            break;
        }
        head1 = insertnode(head1,value);
        int ch = getchar();
        if(ch == '\n' || ch == EOF) break;
    }

    printf("Initial list1\n");
    display(head);
    printf("\nInitial list2\n");
    display(head1);
    head = reverse(head);
    head1 = reverse(head1);

    printf("\nFinal added list\n");
    addlist();
    addhead = reverse(addhead);
    display(addhead);

    return 0;

}