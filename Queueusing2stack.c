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

typedef struct queue{
    stack* stack1;
    stack* stack2;
    int size;
}queue;

node* createnode(int element){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = element;
    newnode->next = NULL;
    return newnode;
}
stack* createstack(){
    stack* newstack = (stack*)malloc(sizeof(stack));
    if(newstack == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
    newstack->top = NULL;
    newstack->size = 0;
    return newstack;
}

queue* createqueue(){
    queue* newqueue = (queue*)malloc(sizeof(queue));
    if(newqueue == NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
    newqueue->stack1 = createstack();
    newqueue->stack2 = createstack();
    newqueue->size = 0;
    return newqueue;
}

int isempty(stack* newstack){
    return (newstack->top == NULL);
}

void push(stack* newstack, int element){
    node* newnode = createnode(element);
    if(isempty(newstack)){
        newstack->top = newnode;
    }else{
        newnode->next = newstack->top;
        newstack->top = newnode;
    }
    newstack->size++;
}

int pop(stack* newstack){
    if(isempty(newstack)){
        return -1;
    }
    node* temp = newstack->top;
    int value = newstack->top->data;
    newstack->top = newstack->top->next;
    newstack->size--;
    free(temp);
    return value;
}

int sizeofstack(stack* newstack){
    return newstack->size;
}
int peek(stack* newstack){
    if(isempty(newstack)){
        return -1;
    }
    node* temp = newstack->top;
    int value = newstack->top->data;
    return value;
}

void displaystack(node* top){
    if(top == NULL)return;
    while(top){
        printf("%d",top->data);
        top = top->next;
    }
}

void printreverse(node* top){
    if (top == NULL) return;
    printreverse(top->next);
    printf("%d ", top->data);
}

void enqueue(queue* newqueue, int element){
    push(newqueue->stack1,element);
    newqueue->size++;
}

int dequeue(queue* newqueue){
    if(newqueue->stack1->size == 0 && newqueue->stack2->size == 0){
        return -1;
    }
    if(isempty(newqueue->stack2)){
        while(!isempty(newqueue->stack1)){
            push(newqueue->stack2,pop(newqueue->stack1));
        }
    }
    newqueue->size--;
    return pop(newqueue->stack2);
}

int peekqueue(queue* newqueue){
    if(newqueue->stack1->size == 0 && newqueue->stack2->size == 0){
        return -1;
    }
    if(isempty(newqueue->stack2)){
        while(!isempty(newqueue->stack1)){
            push(newqueue->stack2,pop(newqueue->stack1));
        }
    }
    return peek(newqueue->stack2);
}

int sizequeue(queue* newqueue){
    return newqueue->stack1->size + newqueue->stack2->size;
}

int isemptyqueue(queue* newqueue) {
    return isempty(newqueue->stack1) && isempty(newqueue->stack2);
}
void displayqueue(queue*newqueue){
    if(isempty(newqueue->stack1) && isempty(newqueue->stack2)){
        printf("Empty\n");
    }
    if(!isempty(newqueue->stack2)){
        displaystack(newqueue->stack2->top);
    }
    if(!isempty(newqueue->stack1)){
        printreverse(newqueue->stack2->top);
    }
}

int main(){
    queue* newqueue = createqueue();
    int choice;
    int value;
    int dequeuedvalue = 0;
    int peekvalue = 0;
    while(1){
        
        printf("\nMenu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Size\n");
        printf("5. Peek\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            scanf("%d",&value);
            enqueue(newqueue, value);
            break;
            
            case 2:
            int dequeuedvalue = dequeue(newqueue);
            if(dequeuedvalue == -1)printf("None\n");
            else printf("%d\n",dequeuedvalue);
            break;
            
            case 3:
            if(isemptyqueue(newqueue)){
                printf("true\n");
            }else{
                printf("false\n");
            }
            break;
            
            case 4:
            printf("%d",sizequeue(newqueue));
            break;
            
            case 5:
            int peekvalue = peekqueue(newqueue);
            if(peekvalue == -1)printf("None\n");
            else printf("%d\n",peekvalue);
            break;
            
            case 6:
            displayqueue(newqueue);
            break;
            
            default: exit(0);
        }
    }
    return 0;
}

