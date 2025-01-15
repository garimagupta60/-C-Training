#include<string.h>
#include<stdio.h>
int get_length(char string[100]){
    int length = 0;
    while(string[length]!='\0'){
        length++;
    }
    return length;
}
void remove_char(char string[1000]){
    int i=0;
    int index=0;
    while(string[i]!='\0'){
        if((string[i]>='a' && string[i]<='z') || (string[i]>='A' && string[i]<='Z'))
        string[index] = string[i];
        index++;
        i++;
    }
    string[index] = '\0';
}
void string_modify(char string[1000]){
    int length = get_length(string);
    for(int i=0; i<length; i++){
        if((i+1)%2==0 && (string[i]>='a' && string[i]<='z')){
            string[i] = string[i]-32;
        }
    }
}   
int main(){
    char string[1000];
    printf("Enter the string\n");
    scanf("%14c",string);
    remove_char(string);
    string_modify(string);

    printf("The string is: %s\n",string);
    
    for(int i=0; i<strlen(string);i++){
        if((string[i]>='a' && string[i]<='z') || (string[i]>='A' && string[i]<='Z')){
            printf("%c",string[i]);
        }
    }
    return 0;
}