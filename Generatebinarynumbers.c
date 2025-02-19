#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100000
typedef struct node{
    char* data;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
    int size;
}queue;

queue* newqueue;

queue* createqueue(){
    queue* newqueue = (queue*)malloc(sizeof(queue)*maxsize);
    newqueue->front = NULL;
    newqueue->rear = NULL;
    newqueue->size = 0;
    return newqueue;
}

node* createnode(char* value){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = (char*)malloc(sizeof(char));
    strcpy(newnode->data,value);
    newnode->next = NULL;
    return newnode;
}

int isempty(){
    return(newqueue->front == NULL);
}
void enqueue(char* string){
    node* newnode = createnode(string);
    if(isempty()){
        newqueue->front = newnode;
        newqueue->rear = newnode;
    }else{
        newqueue->rear->next = newnode;
        newqueue->rear = newnode;
    }
    newqueue->size++;
}
char* dequeue(){
    if(isempty()){
        printf("Underflow\n");
        return NULL;
    }
    node* temp = newqueue->front;
    char* value = (char*)malloc(maxsize*sizeof(char));
    strcpy(value,temp->data);
    newqueue->front = newqueue->front->next;
    free(temp->data);
    free(temp);
    newqueue->size--;
    return value;
}

void generatenumbers(int number){
    int numberofbits = 0;
    int temp = number;
    while(temp>0){
        numberofbits++;
        temp/=2;
    }
    enqueue("1");
    for(int i=0; i<number; i++){
        char* string = dequeue();
        int len = strlen(string);
        for(int i=0; i<numberofbits-len; i++){
            printf("0");
        }
        printf("%s\n", string);
        char string2[maxsize], string3[maxsize];
        int index = 0;
        while(string[index]!='\0'){
            string2[index] = string[index];
            string3[index] = string[index];
            index++;
        }
        string2[index] = '0';
        string3[index] = '1';
        string2[index+1] = '\0';
        string3[index+1] = '\0';

        enqueue(string2);
        enqueue(string3);
        
        free(string);
    }
    
}
int main(){
    int number = 0;
    scanf("%d",&number);
    newqueue = createqueue();
    generatenumbers(number);
}