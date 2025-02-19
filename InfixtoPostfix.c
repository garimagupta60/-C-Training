#include<stdio.h>
#include<stdlib.h>
#define maxsize 100000
#include<string.h>
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

char pop(stack* newStack){
    if(isEmpty(newStack)){
        return '\0';
    }else{
        node* temp = newStack->top;
        char value = temp->data;
        newStack->top = newStack->top->next;
        free(temp);
        newStack->size--;
        return value;
    }
    
}
int isoperator(char ch){
    if(ch =='^' || ch =='*' || ch == '-' || ch=='+'|| ch=='/')return 1;
    return 0;
}
int precedence(char ch){
    if(ch == '^')return 3;
    else if(ch == '*' || ch == '/')return 2;
    else if(ch == '+' || ch == '-')return 1;
    return 0;
}
void infixtopostfix(stack* newstack, char *string,char *postfix){
    int j = 0;
    for(int index = 0; index<strlen(string); index++){
        char ch = string[index];
        if(!isoperator(ch) && ch !='(' && ch!=')'){
            postfix[j++] = ch;
        }
        else if(ch =='('){
            push(newstack,ch);
        }else if(ch == ')'){
            while(!isEmpty(newstack) && newstack->top->data!='('){
                postfix[j++] = pop(newstack);
            }
            char newch = pop(newstack);
        }else{
            while(!isEmpty(newstack) && precedence(newstack->top->data)>=precedence(ch)){
                postfix[j++] = pop(newstack);
            }
            push(newstack,ch);
        }
    }
    while(!isEmpty(newstack)){
        postfix[j++] = pop(newstack);
    }
    postfix[j] = '\0';
}
int main(){
    stack* newStack = createStack();
    char *string = (char*)malloc(maxsize* sizeof(char));
    scanf("%s",string);
    char*postfix = (char*)malloc(maxsize*sizeof(char));
    infixtopostfix(newStack,string,postfix);
    printf("\n%s",postfix);
    return 0;
}