//  Valid Parentheses 
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. 
// An input string is valid if: 
// Open brackets must be closed by the same type of brackets. 

#include<stdio.h>
#include<stdlib.h>
#define maxsize 100000
typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct stack{
    int size;
    node* top;
}stack;

node* createNode(char value){
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

void pop(stack* newStack){
    if(isEmpty(newStack)){
        return;
    }else{
        node* temp = newStack->top;
        newStack->top = newStack->top->next;
        free(temp);
        newStack->size--;
    }
}
int checkvalid(stack* newstack, char* string){
    int index=0;
    while(string[index]!='\0'){
        char ch = string[index];
        if(ch =='(' || ch == '{' || ch == '['){
            push(newstack,ch);
        }
        if(ch ==')' || ch == '}' || ch == ']'){
            if(!isEmpty(newstack)){
                char top_char = newstack->top->data;
                if((ch == ')' && top_char == '(' ) || (ch == ']' && top_char == '[' )|| (ch == '}' && top_char == '{' ) ){
                    pop(newstack);
                }else{
                    return 0;
                }
            }else{
                return 0;
            }
        }
        index++;
    }
    return (isEmpty(newstack));
}
int main(){
    stack* newStack = createStack();
    char *string = (char*)malloc(maxsize* sizeof(char));
    scanf("%s",string);
    if(checkvalid(newStack,string)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}