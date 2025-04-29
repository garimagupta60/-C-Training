#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
        newStack->size--;
        return value;
    }
    return 0;
}

int redundant_brackets(stack* newstack,char string[100]){
    for(int i=0; i<strlen(string); i++){
        if(string[i]=='(' || string[i]=='+' || string[i]=='-' || string[i]=='*' || string[i] == '/'){
            push(newstack,string[i]);
        }else if(string[i] == ')'){
            int is_redundant = 1;
            while(newstack->top->data!='('){
                char ch = pop(newstack);
                if(ch =='+' || ch =='-' || ch =='*' || ch == '/'){
                    is_redundant = 0;
                }
            }
            char character = pop(newstack);
            if(is_redundant == 1){
                return 1;
            }
        }
    }
    return 0; 
}
int main(){
    stack* newstack = createStack();
    char string[100];
    scanf("%s",string);
    if(redundant_brackets(newstack,string)){
        printf("No\n");
    }else{
        printf("yes\n");
    }
}
