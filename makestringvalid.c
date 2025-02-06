#include<stdio.h>
#include<string.h>
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
    node* nn = (node*)malloc(sizeof(node));
    nn->data = value;
    nn->next = NULL;
    return nn;
}

stack* createStack(){
    stack* newstack = (stack*)malloc(sizeof(stack));
    newstack->size = 0;
    newstack->top = NULL;
    return newstack;
}

int isEmpty(stack* newStack){
    return(newStack->top == NULL);
}

void push(stack* newstack, int value){
    node* newnode = createNode(value);
    if(isEmpty(newstack)){
        newstack->top = newnode;
    }else{
        newnode->next = newstack->top;
        newstack->top = newnode;
    }
    newstack->size++;
}

int pop(stack* newstack){
    if(isEmpty(newstack)){
        return -1;
    }else{
        node* temp = newstack->top;
        int value = temp->data;
        newstack->top= newstack->top->next;
        return value;
        free(temp);
    }
}
int no_make_valid(stack* newstack, char string[100]){
   for(int i=0; i<strlen(string);i++){
        char ch = string[i];
        if(ch == '('){
            push(newstack,ch);
        }else{
            if(!isEmpty(newstack) && newstack->top->data =='('){
                char new = pop(newstack);
            }else{
                push(newstack,ch);
            }
        }
   }
   int ans = 0;
   while(!isEmpty(newstack)){
        char final = pop(newstack);
        ans++;
   }
   return ans;

}
int main(){
    stack* newstack = createStack();
    char string[100];
    scanf("%s",string);
    int cost = no_make_valid(newstack,string);
    printf("%d\n",cost);
}
