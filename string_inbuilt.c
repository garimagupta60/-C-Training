#include<stdio.h>
#include<string.h>
#define MAX_LEN 50
int get_length(char str[MAX_LEN]){
    int length = 0;
    while(str[length]!='\0'){
        length++;
    }
    return length;
}
void user_definedstrcpy(char target[MAX_LEN], char source[MAX_LEN]){
    int index = 0;
    int target_index = 0;
    while(source[index]!='\0'){
        target[target_index++] = source[index++];
    }
    target[target_index]='\0';
}
void user_definedstrcat(char target[MAX_LEN], char source[MAX_LEN]){
    int target_index = get_length(target);
    int source_index = 0;
    while(source[source_index]!='\0'){
        target[target_index++] = source[source_index++];
    }
    target[target_index] = '\0';
}

int user_definedstrcmp(char target[MAX_LEN], char source[MAX_LEN]){
    int target_index = 0;
    int source_index = 0;

    while(source[source_index] !='\0' && target[target_index]!='\0'){
        if(source[source_index] != target[target_index]){
            return ((source[source_index] -'0')-(target[target_index]-'0'));
        }
        source_index++;
        target_index++;
    }
    if(source[source_index]=='\0' && target[target_index]=='\0')
        return 0;
    return 1;
}

void create_sub_string(char substring[MAX_LEN], char str[MAX_LEN], int position, int no_of_chars){
    int index = 0;
    while(no_of_chars>0){
        substring[index] = str[position-1];
        index++;
        position++;
        no_of_chars--;
    }
    substring[index]='\0';
}
int main(){
    char source[MAX_LEN];
    char target[MAX_LEN];
    printf("Enter Source string\n");
    scanf("%[^\n]%*c",source);
    printf("Enter Target string\n");
    scanf("%[^\n]%*c",target);
    int source_length = get_length(source);
    int target_length = get_length(target);
    printf("Length of %s = %d\t",source, source_length);
    printf("Length of %s = %d\n",target,target_length);

    // user_definedstrcpy(target,source);
    // printf("After copying\n Source= %s\t Target = %s\n",source,target);

    // printf("After concatination\n");
    // user_definedstrcat(target,source);
    // printf("Target string is %s\n",target);

    printf("Compare strings\n");
    int ans = user_definedstrcmp(target,source);
    printf("ASCII VAlue is %d\n",ans);
    if(ans)
        printf("Not equal\n");
    else
        printf("Strings are equal\n");


    char str[MAX_LEN];
    printf("Enter string\n");
    scanf("%[^\n]%*c",str);
    printf("Enter position\n");
    int position = 0;
    scanf("%d",&position);
    printf("Enter number of characters\n");
    int no_of_chars = 0;
    scanf("%d",&no_of_chars);

    char substring[MAX_LEN];
    create_sub_string(substring,str,position,no_of_chars);
    printf("Substring is %s\n", substring);

}
