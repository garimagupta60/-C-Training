#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100
typedef struct map{
    char itemname[maxsize];
    int count;
}hashmap;

hashmap* map;
int mapsize = 0;

int searchinmap(char itemname[maxsize]){
    for(int i=0; i<mapsize; i++){
        if(strcmp(map[i].itemname, itemname) == 0)return i;
    }
    return -1;
}

void insertinmap(char itemname[maxsize], int quantity){
    if(mapsize>100){
        printf("Inventory is Full\n");
        return;
    }
    int index = searchinmap(itemname);
    if(index != -1){
        map[index].count += quantity;
    }else{
        strcpy(map[mapsize].itemname,itemname);
        map[mapsize].count = quantity;
        mapsize++;
    }
}

void updateinmap(char itemname[maxsize], int quantity){
    int index = searchinmap(itemname);
    if(index == -1){
        printf("Item not found\n");
        return;
    }else{
        map[index].count = quantity;
        printf("Updated\n");
    }
}

void query(char itemname[maxsize]){
    int index = searchinmap(itemname);
    if(index == -1){
        printf("Item not found\n");
        return;
    }
    printf("Quantity: %d\n",map[index].count);
}

void createmap(){
    map = (hashmap*)malloc(100 * sizeof(hashmap));
}

int main(){
    int numberofoperations = 0;
    createmap();
    printf("Input format:\n");
    printf("Add <item> <quantity>\n");
    printf("Update <item> <quantity>\n");
    printf("Query <item>\n");
    
    printf("Enter no of operations: ");
    scanf("%d", &numberofoperations);
    getchar();
    char choice[5];
    char item[maxsize];
    int quantity = 0;

    while(numberofoperations){
        scanf("%s",choice);
        if(choice[0] == 'A'){
            scanf("%s %d", item, &quantity);
            insertinmap(item, quantity);
        }
        else if(choice[0] == 'U'){
            scanf("%s %d", item, &quantity);
            updateinmap(item, quantity);
        }
        else if(choice[0] == 'Q'){
            scanf("%s", item);
            query(item);
        }
        numberofoperations--;
    }
    return 0;
}