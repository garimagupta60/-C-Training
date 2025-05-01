#include<stdio.h>
void modify_array(int rows, int columns, int array[rows][columns]){
    for(int index1=0; index1<rows; index1++){
        for(int index2 = 0; index2<columns; index2++){
            int value = index1 + index2;
            if(value%2==0){
                array[index1][index2] = 0;
            }else{
                continue;
            }
        }
    }
}
int main(){
    int rows = 0;
    int columns = 0;
    printf("ENtre rows and columns\n");
    scanf("%d %d",&rows, &columns);

    int array[rows][columns];
    for(int index1=0; index1<rows; index1++){
        for(int index2 = 0; index2<columns; index2++){
            scanf("%d",&array[index1][index2]);
        }
    }
    
    modify_array(rows,columns,array);

    printf("Modified array is:\n");
    for(int index1=0; index1<rows; index1++){
        for(int index2 = 0; index2<columns; index2++){
            printf("%d",array[index1][index2]);
        }
        printf("\n");
    }
}