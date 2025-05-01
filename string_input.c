#include<stdio.h>
int main(){
    printf("Entre the string\n");
    char string[100000];
    scanf("%99[^\n]%*c",string);

    printf("The string enterd is\n");
    printf("%s",string);
}