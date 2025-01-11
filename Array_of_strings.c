#include<stdio.h>

int main(){

    int number_of_strings = 0;
    int max_length  = 0;
    printf("Enter the number of strings\n");
    scanf("%d",&number_of_strings);
    getchar();
    printf("Enter the max length of strings\n");
    scanf("%d",&max_length);
    getchar();

    char strings[number_of_strings][max_length];

    for(int i=0; i<number_of_strings; i++){
        scanf("%[^\n]%*c",strings[i]);
    }

    printf("The strings entered are: \n");
    for(int i=0; i<number_of_strings; i++){
        printf("%s\n",strings[i]);
    }


    return 0;
}