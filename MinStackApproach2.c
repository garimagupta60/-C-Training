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
int mini;

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

int isempty(){
    return (elementstack->top == NULL);
}

void push(int element){
    node* newnode = createnode(element);
    if(isempty(elementstack)){
        elementstack->top = newnode;
    }
    else{
        newnode->next = elementstack->top;
        elementstack->top = newnode;
    }
    elementstack->size++;
}

int pop(){
    if(isempty(elementstack)){
        return -1;
    }
    node* temp = elementstack->top;
    int value = temp->data;
    elementstack->top = elementstack->top->next;
    elementstack->size--;
    free(temp);
    return value;
}

int peek(){
    return (elementstack->top->data);
}

void pushminstack(int element){
    if(isempty(elementstack)){
        push(element);
        mini = element;
    }else{
        if(element>mini){
            push(element);
        }else{
            int value = 2*element- mini;
            push(value);
            mini = element;
        }
    }
}

int popminstack(){
    if(isempty(elementstack)){
        return -1;
    }
    if(peek()>mini){
        return pop();
    }else{
        int prevmin = mini;
        int value = 2*mini - pop();
        mini = value;
        return prevmin;
    }
    return -1;
}

void getmin(){
    if(isempty()){
        printf("No element\n");
    }
    else{
        printf("%d\n",mini);
    }
}

int main(){
    elementstack = createstack(elementstack);
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