#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    node* top;
    int size;
}stack;

stack* elementstack;
stack* minstack;

stack* createstack(stack* newstack){
    newstack = (stack*)malloc(sizeof(stack));
    newstack->top = NULL;
    newstack->size = 0;
    return newstack;
}

node* createnode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    return  newnode;
}

int isempty(stack* newstack){
    return (newstack->top == NULL);
}

void push(stack* newstack, int element){
    node* newnode = createnode(element);
    if(isempty(newstack)){
        newstack->top = newnode;
    }
    else{
        newnode->next = newstack->top;
        newstack->top = newnode;
    }
    newstack->size++;
}

void pop(stack* newstack){
    if(isempty(newstack)){
        return;
    }
    node* temp = newstack->top;
    newstack->top = newstack->top->next;
    newstack->size--;
    free(temp);
    return;
}

int peek(stack* newstack){
    return (newstack->top->data);
}

void pushminstack(int element){
    if(isempty(minstack) || (element<= peek(minstack))){
        push(minstack,element);
    }
    push(elementstack,element);
}

void popminstack(){
    if(peek(elementstack) == peek(minstack)){
        pop(minstack);
    }
    pop(elementstack);
}

void getmin(){
    if(isempty(minstack)){
        printf("No element\n");
    }
    else{
        printf("%d\n",peek(minstack));
    }
}

int main(){
    elementstack = createstack(elementstack);
    minstack = createstack(minstack);

    int value;
    int choice;
    while(1){
        printf("Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. getMin\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        getchar();
        switch(choice){
            case 1 : 
            printf("Enter element\n");
            scanf("%d",&value);
            pushminstack(value);
            break;
            case 2: popminstack(); break;
            case 3: getmin();break;
            default: printf("Invalid choice\n");exit(0);
        }        
    }
    return 0;
}