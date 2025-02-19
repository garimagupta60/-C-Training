#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100000

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    node* top;
    int size;
}stack;

stack* newstack;
void createstack(){
    newstack = (stack*)malloc(sizeof(stack));
    newstack->top = NULL;
    newstack->size = 0;
}
node* createnode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    return  newnode;
}

int isempty(){
    return (newstack->top == NULL);
}

void push(int value){
    node* newnode = createnode(value);
    if(isempty()){
        newstack->top = newnode;
    }else{
        newnode->next = newstack->top;
        newstack->top = newnode;
    }
    newstack->size++;
}
int pop(){
    if(isempty()){
        return -1;
    }
    node* temp = newstack->top;
    int value = temp->data;
    newstack->top = newstack->top->next;
    newstack->size--;
    free(temp);
    return value;
}

int isoperator(char ch){
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch=='^');
}

int evaluatepostfix(char string[maxsize]){
    int index = 0;
    while(string[index]!='\0'){
        if(string[index] == ' '){
            index++;
            continue;
        }
        else if(isoperator(string[index])){
            int value = 0;
            int operand2 = pop();
            int operand1 = pop();
            switch (string[index]){
            case '+':
                value = operand1+operand2;
                break;
            case '-':
                value = operand1-operand2;
                break;
            case '*':
                value = operand1*operand2;
                break;
            case '/':
                value = operand1/operand2;
                break;
            default:
                break;
            }
            push(value);
        }
        else{
            int num = 0;
            while(string[index]>='0' && string[index]<='9'){
                num = num *10 +(string[index] - '0');
                index++;
            }
            index--;
            push(num);
        }
        index++;
    }
    return pop();
}
int main(){
    char string[maxsize];
    scanf("%[^\n]%*c",string);
    createstack();
    int answer = evaluatepostfix(string);
    printf("%d",answer);
}