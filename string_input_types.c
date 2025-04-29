#include<stdio.h>
#include<stdlib.h>
#define max_size 100
int hasspace(char string_input[max_size]){
    int i=0;
    while(string_input[i]!='\0'){
        if(string_input[i] == ' ')return 1;
        i++;
    }
    return 0;
}
int iscomma(char string_input[max_size]){
    int i=0;
    while(string_input[i++]!='\0'){
        if(string_input[i] == ',')return 1;
    }
    return 0;
}
int is_only_digit(char string_input[max_size]){
    int i=0;
    while(string_input[i]!='\0'){
        if(string_input[i]>='0' && string_input[i]<='9')i++;
        else{
            return 0;
        }
    }
    return 1;
}
int is_only_alphabet(char string_input[max_size]){
    int i=0;
    while(string_input[i]!='\0'){
        if((string_input[i]>='A'&& string_input[i]<='Z') || (string_input[i]>='a' && string_input[i]<='z'))i++;
        else{
            return 0;
        }
    }
    return 1;
}
void with_spaces(){
    while(1){
        char string_input[max_size];
        printf("Enter the string with spaces\n");
        scanf("%[^\n]%*c",string_input);
        if(hasspace(string_input)){
            printf("%s", string_input);
            break;
        }else{
            printf("you did not enter the string with spaces\n");
        }
    }
}
void without_spaces(){
    while(1){
        char string_input[max_size];
        printf("Enter the string without spaces\n");
        scanf("%[^\n]%*c",string_input);
        if(!hasspace(string_input)){
            printf("%s", string_input);
            break;
        }else{
            printf("you did not enter the string without spaces\n");
        }
    }
}
void with_comma(){
    while(1){
        char string_input[max_size];
        printf("Enter the string with comma\n");
        scanf("%[^\n]%*c",string_input);
        if(iscomma(string_input)){
            printf("%s", string_input);
            break;
        }
        else{
            printf("you did not enter the string with comma\n");
        }
    }
}
void only_digits(){
    while(1){
        char string_input[max_size];
        printf("Enter the string with only digits\n");
        scanf("%[^\n]%*c",string_input);
        if(is_only_digit(string_input)){
            printf("%s", string_input);
            break;
        }else{
            printf("you did not enter the string with only digits\n");
        }
    }
}
void only_alphabets(){
    while(1){
        char string_input[max_size];
        printf("Enter the string with only alphabets\n");
        scanf("%[^\n]%*c",string_input);
        if(is_only_alphabet(string_input)){
            printf("%s", string_input);
            break;
        }else{
            printf("you did not enter the string with only alphabets\n");
        }
    }
}
int main(){
    int choice;
    while(1){
        
        printf("\n1. With spaces\n");
        printf("2. Without spaces\n");
        printf("3. With Comma\n");
        printf("4. Only digits\n");
        printf("5. Only alphabets\n");
        printf("6. Exit of Menu\n");
        printf("Enter choice \n");
        if(scanf("%d",&choice)!=1){
            while (getchar() != '\n');
            printf("Enter valid choice from 1 to 5\n");
            continue;
        }
        getchar();
        switch(choice){
            case 1: with_spaces();break;
            case 2: without_spaces();break;
            case 3: with_comma();break;
            case 4: only_digits();break;
            case 5: only_alphabets();break;
            case 6: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }

    }

    return 0;

}