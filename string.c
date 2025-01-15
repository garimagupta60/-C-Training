#include<string.h>
#include<stdio.h>
int get_length(char string[100]){
    int length = 0;
    while(string[length]!='\0'){
        length++;
    }
    return length;
}
void string_modify(char string[100]){
    int length = get_length(string);
    for(int i=0; i<length; i++){
        if((i+1)%2==0){
            string[i] = string[i]-32;
        }
    }
}   
int main(){
    char string[1000];
    printf("Enter the string\n");
    scanf("%14c",string);
    string_modify(string);

    printf("The string is: %s",string);
    return 0;
}