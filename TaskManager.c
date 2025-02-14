#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct map{
    int pending;
    char taskname[101];
}map;

map* taskmanager;
int mapsize = 0;
int searchinmap(char task[101]){
    for(int i=0; i<mapsize; i++){
        if(strcmp(taskmanager[i].taskname,task) == 0)return i;
    }
    return -1;
}

void add(char task[101]){
    if(mapsize>100){
        printf("Task Manager is Full\n");
        return;
    }
    int index = searchinmap(task);
    if(index == -1){
        strcpy(taskmanager[mapsize].taskname,task);
        taskmanager[mapsize].pending = 1;
        mapsize++;
    }
}

void complete(char task[101]){
    int index = searchinmap(task);
    if(index == -1){
        printf("Task not found\n");
        return;
    }
    taskmanager[index].pending = 0;
}

void pendingprint(){
    int flag = 0;
    for(int i=0; i<mapsize; i++){
        if(taskmanager[i].pending != 0){
            printf("%s ",taskmanager[i].taskname);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("All task complete");
    }
    printf("\n");
}
void createmap(){
    taskmanager  = (map*)malloc(100*sizeof(map));
}
int main(){
    int numberofoperations = 0;
    createmap();
    printf("Input format:\n");
    printf("ADD <task>\n");
    printf("COMPLETE <task>\n");
    printf("PENDING\n");
    
    printf("Enter no of operations: ");
    scanf("%d", &numberofoperations);
    getchar();
    char choice[10];
    char task[101];
    int pending = 0;
    while(numberofoperations){
        scanf("%s",choice);
        if(choice[0] == 'A'){
            scanf("%s", task);
            add(task);
        }
        else if(choice[0] == 'C'){
            scanf("%s", task);
            complete(task);
        }
        else if(choice[0] == 'P'){
            pendingprint();
        }
        numberofoperations--;
    }
    return 0;
}