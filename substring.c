#include<stdio.h>
int getlength(char string[100]){
    int length = 0;
    while(string[length]!='\0'){
        length++;
    }
    return length;
}
int sub_string(char string1[100],char string2[100] ){
    int length1 = getlength(string1);
    int length2 = getlength(string2);
    for(int i=0; i<length1; i++){
        int j=0;
        int index = i;
        while(string1[index] == string2[j] && string2[j]!='\0'){
            j++;
            index++;
        }if(string2[j]=='\0')return i;
    }
    return -1;
}
int main(){
    char string1[100];
    char string2[100];

    printf("Enter string1\n");
    scanf("%[^\n]%*c",string1);
    printf("Enter string2\n");
    scanf("%[^\n]%*c",string2);

    int index = sub_string(string1,string2);
    printf("%d",index);
    return 0;
}