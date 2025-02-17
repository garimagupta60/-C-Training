#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 101
typedef struct node{
    int rating;
    char moviename[maxsize];
    struct node* next;
}node;

typedef struct movie{
    node* top;
    int size;
}stack;

stack* moviemanager;

node* createnode(char moviename[maxsize], int rating){
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->moviename,moviename);
    newnode->rating = rating;
    newnode->next = NULL;
    return newnode;
}

stack* createstack(){
    moviemanager = (stack*)malloc(sizeof(stack));
    moviemanager->top = NULL;
    moviemanager->size = 0;
    return moviemanager;
}

int isEmpty(){
    return(moviemanager->top == NULL);
}

void removemovie(char moviename[maxsize]){
    node* temp = moviemanager->top;
    node* prev = NULL;
    while (temp != NULL && strcmp(temp->moviename, moviename) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            moviemanager->top = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        moviemanager->size--;
    }
}

void rate(char moviename[maxsize], int rating){
    removemovie(moviename);
    node* newmovie = createnode(moviename,rating);
    if(isEmpty()|| moviemanager->top->rating<rating){
        newmovie->next = moviemanager->top;
        moviemanager->top = newmovie;
        moviemanager->size++;
    }
    else{
        node* current  = moviemanager->top;
        while(current->next!=NULL && (current->next->rating>rating || current->next->rating == rating) ){
            current = current->next;
        }
        newmovie->next = current->next;
        current->next = newmovie;
        moviemanager->size++;
    }
    
}
        

void top(){
    if(isEmpty()){
        printf("No movies rated\n");
    }else{
        printf("%s\n",moviemanager->top->moviename);
    }
}
int main(){
    int numberofoperations;
    moviemanager = createstack();
    printf("Input format:\n");
    printf("RATE <movie> <rating>\n");
    printf("REMOVE <movie>\n");
    printf("TOP\n");
    printf("Enter number of operations\n");
    scanf("%d",&numberofoperations);
    getchar();

    char choice[10];
    char moviename[maxsize];
    int rating;
    while(numberofoperations){
        scanf("%s",choice);
        if(choice[1] == 'A'){
            scanf("%s %d",moviename,&rating);
            rate(moviename,rating);
        }else if(choice[1] == 'E'){
            scanf("%s",moviename);
            removemovie(moviename);
        }else if(choice[1] == 'O'){
            top();
        }
        numberofoperations--;
    }
    return 0;
}