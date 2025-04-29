#include<stdio.h>
int getlength(char string[100]){
    int length = 0;
    while(string[length]!='\0'){
        length++;
    }
    return length;
}
int isanagram(char string1[100],char string2[100] ){
    int length1 = getlength(string1);
    int length2 = getlength(string2);
    if(length1!=length2)return 0;
    int hash[256] = {0};
    for(int i=0; i<length1; i++){
        hash[string1[i]-'a']++;
        hash[string2[i]-'a']--;
    }
    for(int i=0; i<255; i++){
        if(hash[i]!=0)return 0;
    }
    return 1;
}
int main(){
    char string1[100];
    char string2[100];

    printf("Enter string1\n");
    scanf("%[^\n]%*c",string1);
    printf("Enter string2\n");
    scanf("%[^\n]%*c",string2);

    if(isanagram(string1,string2)){
        printf("True");
    }
    else{
        printf("False");
    }
    return 0;
}