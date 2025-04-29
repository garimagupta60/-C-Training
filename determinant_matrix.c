#include<stdio.h>
#include<math.h>
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int calculate(int order_of_matrix, int array[order_of_matrix][order_of_matrix]){
    
    if(order_of_matrix==1)return array[0][0];
    else if(order_of_matrix==2){
        int value = ((array[0][0]*array[1][1]) - (array[0][1]*array[1][0]));
        return value;
    }else{
        int sum = 0;
        for(int columns = 0; columns<order_of_matrix; columns++){
            //printf("Column is %d\n",columns);
            int temp[order_of_matrix-1][order_of_matrix-1];
            // int exponent = 0  + columns;
            // printf("Enponent= %d ",exponent);
            int term = (columns % 2 == 0) ? 1 : -1;
            //printf("term= %d\n\n",term);
            for(int i=1; i<order_of_matrix; i++){
                int index = 0;
                for(int j=0; j<order_of_matrix; j++){
                    if(j==columns){
                        continue;
                    }else{
                        temp[i-1][index++] = array[i][j];
                    }
                }
            }
            // printf("Minor is:\n");
            //     for(int i=0; i<order_of_matrix-1; i++){
            //         for(int j=0; j<order_of_matrix-1; j++){
            //             printf("%d ",temp[i][j]);
            //         }
            //         printf("\n");
            //     }
            int minor_determinant = calculate(order_of_matrix-1,temp);
            // printf("minor_determinant= %d\n\n",minor_determinant);
            int result = array[0][columns]*(term*minor_determinant);
            sum += result;
            printf("sum= %d\n",sum);
        }
        return sum;
    }
    return 0;
}
int main(){
    int order_of_matrix=0;
    printf("Enter the value of order of matrix\n");
    scanf("%d",&order_of_matrix);
    
    int array[order_of_matrix][order_of_matrix];
    printf("Enter the matrix\n");
    for(int i=0; i<order_of_matrix; i++){
        for(int j=0; j<order_of_matrix; j++){
            scanf("%d",&array[i][j]);
        }
    }
    printf("Matrix is:\n");
    for(int i=0; i<order_of_matrix; i++){
        for(int j=0; j<order_of_matrix; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    int determinant = calculate(order_of_matrix, array);
    printf("Determinant = %d",determinant);
}