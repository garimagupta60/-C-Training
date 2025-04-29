#include<stdio.h>
int count_words(char string[100]){
    int i=0;
    int count = 0;
    while(string[i]!='\0'){
        while(string[i]==' '){
            i++;
        }
        if(string[i]!='\0'){
            count++;
            while(string[i]!=' ' && string[i]!='\0')i++;
        }
    }
    return count;
}
int main(){
    char string[100];
    printf("Entre string\n");
    scanf("%[^\n]%*c",string);

    int number_of_words = count_words(string);
    printf("%d",number_of_words);
    return 0;
}