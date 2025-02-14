#include<stdio.h>
#include<stdlib.h>
#define maxsize 100000
int findinmap(int hashmap[maxsize], int element,int mapsize){
    for(int i=0; i<mapsize; i++){
        if(hashmap[i] == element)return i;
    }
    return -1;
}
int findlongestsubsequence(int length, int array[length]){
    int hashmap[maxsize] = {0};
    int mapsize = 0;
    int longest = 0;
    for(int i=0; i<length; i++){
        int index = findinmap(hashmap,array[i],mapsize);
        if(index == -1){
            hashmap[mapsize++] = array[i];
        }
    }
    for(int i=0; i<mapsize; i++){
        int start = hashmap[i];
        if(findinmap(hashmap,start-1,mapsize)==-1){
            int count = 1;
            while(findinmap(hashmap,start+1,mapsize)!=-1){
                start = start+1;
                count++;
            }
            if(count>longest)longest = count;
        }
    }
    return longest;
}
int main(){
    int value;
    int array[maxsize];
    int index = 0;
    while(1){
        scanf("%d",&value);
        array[index++] = value;
        char ch = getchar();
        if(ch == '\n' || ch == EOF)break;
    }

    int longest = findlongestsubsequence(index, array);
    printf("%d",longest);
    return 0;

}