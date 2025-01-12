#include<stdio.h>
int getlength(char string[100]){
    int i = 0;
    while(string[i]!='\0'){
        i++;
    }
    return i;
}
void remove_duplicates(int hash[256], int string_length, char string[string_length], char final_string[string_length]){
    int index = 0;
    for(int i=0; string[i]!='\0'; i++){
        if(hash[string[i]-'a']==0){
            hash[string[i]-'a']=1;
            final_string[index++] = string[i];
        }
    }
    final_string[index] = '\0';
}
int main(){
    char string[100];
    printf("Enter string\n");
    scanf("%[^\n]%*c",string);
    int string_length = getlength(string);
    char final_string[string_length];
    int hash[256] = {0};
    remove_duplicates(hash,string_length,string,final_string);
    printf("Final string is: ");
    printf("%s",final_string);

}