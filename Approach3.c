#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 101
typedef struct node{
    char moviename[maxsize];
    int rating;
    struct node* next;
}node;

node* head = NULL;

node* createnode(char moviename[maxsize], int rating){
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->moviename,moviename);
    newnode->rating = rating;
    newnode->next = NULL;
    return newnode;
}

void removemovie(char moviename[maxsize]){
    if(head == NULL)return;
    node* current = head;
    node* prev = NULL;
    while(current!=NULL && strcmp(current->moviename, moviename) != 0){
        prev = current;
        current = current->next;
    }
    if(current != NULL) {
        if(prev == NULL) {
            head = current->next;
        }else{
            prev->next = current->next;
        }
        free(current);
    }
}

void rate(char moviename[maxsize], int rating){
    removemovie(moviename);
    node* newnode =  createnode(moviename,rating);
    if (head == NULL || head->rating < rating) {
        newnode->next = head;
        head = newnode;
        return;
    }

    node* current = head;
    node* prev = NULL;
    while(current!=NULL && (current->rating>rating || current->rating == rating)){
        prev = current;
        current = current->next;
    }
    if(current!=NULL){
        newnode->next = current;
    }
    if(prev)prev->next = newnode;
}


void top(){
    if(head == NULL){
        printf("No movies rated\n");
    }else{
        printf("%s\n",head->moviename);
    }
}
int main(){
    int numberofoperations;
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