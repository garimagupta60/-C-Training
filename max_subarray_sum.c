#include<stdio.h>
#define max_size 400
int isnumber(char ch){
    if(ch>='0' && ch<='9')return 1;
    return 0;
}
int maxi(int *number1, int *number2){
    if(*number1>*number2){
        return *number1;
    }else{
        return *number2;
    }
}
int parse_string(char string[max_size], int array[max_size]){
    int index = 0;
    int negative = 0;
    int array_index = 0;
    while(string[index]!='\0'){
        if(string[index] == '-'){
            negative =1;
        }else if(isnumber(string[index])){
            int number = 0;
            while (isnumber(string[index]))
            {
                number = number *10 + (string[index]-'0');
                index++;
            }
            index--;
            if(negative){
                number = -number;
                negative = 0;
            }
            array[array_index++] = number;
            
        }
        index++;
    }
    return array_index;
}
int calculate_sum(int size,int array[size]){
    int sum = 0;
    int max_sum = 0;
    for(int i=0; i<size; i++){
        sum +=array[i];
        if(sum>max_sum){
            max_sum = sum;
        }
        if(sum<0){
            sum = 0;
        }
    }
    return max_sum;
}

int main(){
    char string[max_size];
    int array[max_size];
    printf("Enter the string\n");
    scanf("%[^\n]%*c",string);
    int size = parse_string(string,array);
    printf("%d\n",size);
    for(int i=0; i<size; i++){
        printf("%d ",array[i]);
    }

    int max_subarray_sum = calculate_sum(size,array);
    printf("Maxium Sum = %d",max_subarray_sum);
}