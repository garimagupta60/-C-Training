#include<stdio.h>
int getlength(char string[100]){
    int length = 0;
    while(string[length]!='\0'){
        length++;
    }
    return length;
}
int isrotation(char string1[100], char string2[100]){
    int length1 = getlength(string1);
    int length2 = getlength(string2);
    if(length1!=length2)return 0;
    char double_string[(2*length1)+1];

    for(int i=0; i<length1; i++){
        double_string[i] = string1[i];
        double_string[i+length1] = string1[i];
    }

    for(int i=0; i<length1; i++){
        int j = 0;
        while(double_string[i+j]==string2[j] && string2[j]!='\0'){
            j++;
        }
        if(string2[j]=='\0')return 1;
    }
    return 0;

}
int main(){
    char string1[100], string2[100];
    printf("Enter string1:\n");
    scanf("%[^\n]%*c",string1);

    printf("Enter string2:\n");
    scanf("%[^\n]%*c",string2);

    if(isrotation(string1,string2)){
        printf("True");
    }
    else{
        printf("False");
    }

    return 0;
}