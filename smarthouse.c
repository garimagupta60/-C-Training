#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char roomname[101];
    struct node* next;
}node;

node* head = NULL;

node* createnode(char roomname[101]){
    node* newroom = (node*)malloc(sizeof(node));
    strcpy(newroom->roomname,roomname);
    newroom->next = NULL;
    return newroom;
}
void addlist(char roomname[101]){
    node* newroom = createnode(roomname);
    if(head == NULL){
        head = newroom;
        return;
    }
    node* currentroom = head;
    node* prev = NULL;
    while(currentroom!=NULL){
        if(strcmp(head->roomname, roomname) == 0) {
            return;
        }
        prev = currentroom;
        currentroom = currentroom->next;
    }
    prev->next = newroom;
}

void removefrom(char roomname[101]){
    if(head == NULL){
        return;
    }
    node* currentroom = head;
    node* prev = NULL;
    if(strcmp(head->roomname, roomname) == 0) {
        head = head->next;
        free(currentroom);
        return;
    }
    while(currentroom!=NULL){
        if(strcmp(currentroom->roomname,roomname)==0){
            prev->next = currentroom->next;
            free(currentroom);
        }
        prev = currentroom;
        currentroom = currentroom->next;
    }
}

void status(char roomname[101]){
    if(head == NULL){
        printf("OFF\n");
        return;
    }
    node* currentroom = head;
    while(currentroom!=NULL){
        if(strcmp(currentroom->roomname,roomname)==0){
            printf("ON\n");
            return;
        }
        currentroom = currentroom->next;
    }
    printf("OFF\n");
}


int main(){
    int numberofoperations = 0;
    printf("Input format:\n");
    printf("TURN_ON <room>\n");
    printf("TURN_OFF <room>\n");
    printf("STATUS\n");
    printf("Enter number of operations\n");
    scanf("%d",&numberofoperations);
    getchar();
    char choice[100];
    char roomname[101];
    while(numberofoperations){
        scanf("%s",choice);
        if(choice[6]=='N'){
            scanf("%s",roomname);
            addlist(roomname);
        }else if(choice[6] == 'F'){
            scanf("%s",roomname);
            removefrom(roomname);
        }else{
            scanf("%s",roomname);
            status(roomname);
        }
        numberofoperations--;
    }
    return 0;
}