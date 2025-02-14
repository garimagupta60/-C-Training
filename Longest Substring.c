#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100000
int longestatmostk(char string[1000], int k){
    int left = 0;
    int right = 0;
    int count = 0;
    int longest  = 0;
    int length = strlen(string);
    int frequency[maxsize]={0};
    while(right<length){
        if(frequency[string[right]] == 0)count++;
        frequency[string[right]]++;
        while(count>k){
            frequency[string[left]]--;
            if(frequency[string[left]] == 0)count--;
            left++;
        }
        if((right-left+1)>longest){
            longest = right-left+1;
        }
        right++;
    }
    return  longest;
}
int main(){
    char string[100];
    scanf("%[^\n]%*c",string);
    int k = 0;
    scanf("%d",&k);
    int answer = longestatmostk(string,k);
    printf("%d",answer);
    return 0;
}