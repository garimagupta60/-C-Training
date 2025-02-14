#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 1000
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    node* top;
    int size;
}stack;

int array[maxsize] = {0};
stack* newstack;
int index1 = 0;

node* createnode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next =  NULL;
    return newnode;
}

stack* createstack(){
    stack* newstack = (stack*)malloc(sizeof(stack));
    newstack->top = NULL;
    newstack->size = 0;
    return newstack;
}



int isEmpty(){
    return (newstack->top == NULL);
}

void bookmark(int pagenumber){
    if(isEmpty()){
        array[index1++] = pagenumber;
        newstack->top = createnode(pagenumber);
        newstack->size++;
        return;
    }
    node* newnode = createnode(pagenumber);
    newnode->next = newstack->top;
    newstack->top = newnode;
    int i = index1-1;
    while(i>=0 && array[i]>pagenumber){
        array[i+1] = array[i];
        i--;
    }
    array[i+1] = pagenumber;
    index1++;
    newstack->size++;
}

int deletefromstack(){
    if(isEmpty()){
        printf("List Empty\n");
        return -1;
    }else{
        node* temp = newstack->top;
        newstack->top = temp->next;
        int value = temp->data;
        int i = index1-1;
        while(i>=0 && array[i] !=value){
            i--;
        }
        array[i] = 0;
        newstack->size--;
        free(temp);
    }
}

void listfromstack(){
    int flag = 0;
    for(int i=0; i<index1; i++){
        if(array[i]!=0){
            printf("%d ",array[i]);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Empty");
    }
    printf("\n");
}

void parseandexecute(char input[maxsize]){
    int index = 0;
    char functionname[maxsize];
    int functionindex = 0;
    int pagenumber = 0;
    while(input[index] == '"' || input[index] == ' ')index++;
    while(input[index]!=' ' && input[index]!='\0'){
        functionname[functionindex++] = input[index];
        index++;
    }
    functionname[functionindex] = '\0';
    while(input[index] == '"' || input[index] == ' ' || input[index] == '<')index++;
    while(input[index]!='>'  && input[index]!='\0'){
        pagenumber = pagenumber* 10 + (input[index] - '0');
        index++;
    }
    while(input[index] == '"' || input[index] == ' ' || input[index] == '>')index++;
    if(strcmp(functionname,"BOOKMARK") == 0){
        bookmark(pagenumber);
    }else if(strcmp(functionname,"DELETE") == 0){
        deletefromstack();
    }else{
        listfromstack();
    }
}

int main(){
    int numberofoperations = 0;
    scanf("%d",&numberofoperations);
    char input[maxsize];
    newstack = createstack();
    getchar();
    while(numberofoperations){
        scanf("%[^\n]%*c",input);
        parseandexecute(input);
        numberofoperations--;
    }
    return 0;
}

