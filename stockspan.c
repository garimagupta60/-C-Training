#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    int size;
    node* top;
}stack;

node* createNode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

stack* createStack(){
    stack* newStack = (stack*)malloc(sizeof(stack));
    if(newStack == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newStack->size = 0;
    newStack->top = NULL;
    return newStack;
}


int isEmpty(stack* newStack){
    return(newStack->top == NULL);
}

void push(stack* newStack, int value){
    node* newnode = createNode(value);
    if(isEmpty(newStack)){
        newStack->top = newnode;
    }else{
        newnode->next = newStack->top;
        newStack->top = newnode;
    }
    newStack->size++;
}

int pop(stack* newStack){
    if(isEmpty(newStack)){
        return -1;
    }else{
        node* temp = newStack->top;
        int value = temp->data;
        newStack->top = newStack->top->next;
        free(temp);
        return value;
        newStack->size--;
    }
}

void stockspan(int size, int array[size],int result[size],stack* stack1,stack* stack2){
    for(int i=0; i<size; i++){
        if(!isEmpty(stack1)){
            while (!isEmpty(stack1) && stack1->top->data < array[i]){
                push(stack2,pop(stack1));
                result[i]++;
            }
            while(!isEmpty(stack2)){
                push(stack1,pop(stack2));
            }
            push(stack1,array[i]);
        }else{
            push(stack1,array[i]);
        }
    }
}
int main(){
    stack* stack1 = createStack();
    stack* stack2 = createStack();
    int array[1000];
    int index = 0;
    while(1){
        int value;
        scanf("%d",&value);
        array[index++] = value;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)break;
    }

    int result[index];
    for(int i=0; i<index; i++){
        result[i] = 1;
    }
    stockspan(index, array,result,stack1,stack2);
    for(int i=0; i<index; i++){
        printf("%d ",result[i]);
    }

}
