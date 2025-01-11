 //prints the Fibonacci words of order 0 through 5. 

 #include<stdio.h>
 #include<string.h>
 #define MAX_LEN 100
int get_length(char str[MAX_LEN]){
    int length = 0;
    while(str[length]!='\0'){
        length++;
    }
    return length;
}
void xstrcpy(char target[MAX_LEN], char source[MAX_LEN]){
    int index = 0;
    int target_index = 0;
    while(source[index]!='\0'){
        target[target_index++] = source[index++];
    }
    target[target_index]='\0';
}
void xstrcat(char target[MAX_LEN], char source[MAX_LEN]){
    int target_index = get_length(target);
    int source_index = 0;
    while(source[source_index]!='\0'){
        target[target_index++] = source[source_index++];
    }
    target[target_index] = '\0';
}

 int main(){
    
    char temp[MAX_LEN];
    char first[MAX_LEN] = "A";
    printf("f(0) = %s\n",first);
    char second[MAX_LEN] = "B";
    printf("f(1) = %s\n",second);
    for(int i=1; i<=5; i++){
        char strings[MAX_LEN];
        xstrcpy(temp,second);
        xstrcat(temp,first);
        xstrcpy(strings,temp);
        printf("f(%d) = %s\n",i,strings);
        xstrcpy(first,second);
        xstrcpy(second,strings);
    }
 }