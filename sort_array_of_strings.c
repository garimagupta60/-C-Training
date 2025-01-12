//Sort array of strings lexicographically

#include<stdio.h>
void user_defined_strcpy(int max_length,char target[max_length], char source[max_length]){
    int index = 0;
    int target_index = 0;
    while(source[index]!='\0'){
        target[target_index++] = source[index++];
    }
    target[target_index]='\0';
}
int user_defined_strcmp(int max_length,char target[max_length], char source[max_length]){
    int target_index = 0;
    int source_index = 0;

    while(source[source_index] !='\0' && target[target_index]!='\0'){
        if(source[source_index] != target[target_index]){
            return ((source[source_index])-(target[target_index]));
        }
        source_index++;
        target_index++;
    }
    if(source[source_index]=='\0' && target[target_index]=='\0')
        return 0;
    return (target[target_index] == '\0') ? -1 : 1;
}
void sort_strings(int number_of_strings, int max_length, char strings[number_of_strings][max_length]){
    for(int i=number_of_strings - 1; i>=0; i--){
        for(int j=0; j<=i-1; j++){
            if(user_defined_strcmp(max_length, strings[j],strings[j+1])<0){
                char temp[max_length];
                user_defined_strcpy(max_length, temp,strings[j]);
                user_defined_strcpy(max_length, strings[j],strings[j+1]);
                user_defined_strcpy(max_length, strings[j+1],temp);
            }
        }
    }
}
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

    sort_strings(number_of_strings, max_length, strings);
    printf("Sorted strings are: \n");
    for(int i=0; i<number_of_strings; i++){
        printf("%s\n",strings[i]);
    }
}