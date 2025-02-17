#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 101
typedef struct node{
    char moviename[maxsize];
    int rating;
    struct node* next;
}node;

typedef struct movie{
    int capacity;
    int size;
    node** array;
}movie;

movie* moviemanager;

node* createnode(char moviename[maxsize], int rating){
    node* newmovie = (node*)malloc(sizeof(node));
    strcpy(newmovie->moviename,moviename);
    newmovie->rating = rating;
    newmovie->next = NULL;
    return newmovie;
}
void createmap(){
    moviemanager = (movie*)malloc(sizeof(movie)*10);
    moviemanager->capacity = 10;
    moviemanager->size = 0;
    moviemanager->array = (node**)malloc(sizeof(node*)*10);
    for(int i=0; i<10; i++){
        moviemanager->array[i] = NULL;
    }
}

void rate(char moviename[maxsize], int rating){
    int flag = 0;
    for(int i=0; i<10; i++){
        node* currentmovie = moviemanager->array[i];
        node* prev = NULL;
        while(currentmovie!=NULL){
            if(strcmp(currentmovie->moviename,moviename)==0){
                if(prev == NULL){
                    moviemanager->array[i] = currentmovie->next;
                }else{
                    prev->next = currentmovie->next;
                }
                free(currentmovie);
                moviemanager->size--;
                flag = 1;
                break;
            }
            prev = currentmovie;
            currentmovie = currentmovie->next;
        }
        if(flag)break;
    }
    node* newmovie = createnode(moviename,rating);
    if(moviemanager->array[rating-1] == NULL){
        moviemanager->array[rating-1] = newmovie;
    }else{
        node* temp = moviemanager->array[rating - 1];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newmovie;
    }
    moviemanager->size++;
}

void removemovie(char moviename[maxsize]){
    for(int i=0; i<10; i++){
        node* currentmovie = moviemanager->array[i];
        if(currentmovie == NULL)continue;
        node* prev = NULL;
        while(currentmovie!=NULL){
            if(strcmp(currentmovie->moviename,moviename) == 0){
                if(prev == NULL){
                    moviemanager->array[i] = currentmovie->next;
                }else{
                    prev->next = currentmovie->next;
                }
                free(currentmovie);
                moviemanager->size--;
                return;
            }
            prev = currentmovie;
            currentmovie = currentmovie->next;
        }
    }
}

void top(){
    int flag = 0;
    for(int i=9; i>=0; i--){
        node* currentmovie = moviemanager->array[i];
        if(currentmovie == NULL)continue;
        if(currentmovie!=NULL){
            printf("%s\n",currentmovie->moviename);
            flag = 1;
            return;
        }
    }
    if(flag == 0){
        printf("No movies rated\n");
    }
}
int main(){
    int numberofoperations;
    createmap();
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