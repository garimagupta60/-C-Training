#include<stdio.h>
#include<math.h>
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
        }
        return sum;
    }
    return 0;
}
void create(int order_of_matrix, int array[order_of_matrix][order_of_matrix],int cofactor_matrix[order_of_matrix][order_of_matrix]){
    
    if(order_of_matrix==1)return;
    else if(order_of_matrix==2){
        cofactor_matrix[0][0] = array[1][1];
        cofactor_matrix[0][1] = -array[0][1];
        cofactor_matrix[1][0] = -array[1][0];
        cofactor_matrix[1][1] = array[0][0];
    }else{
        for (int rows = 0; rows < order_of_matrix; rows++) {
            for (int columns = 0; columns < order_of_matrix; columns++) {
                int row_index = 0;
                int temp[order_of_matrix - 1][order_of_matrix - 1];
                int term = ((rows + columns) % 2 == 0) ? 1 : -1;
                for (int i = 0; i < order_of_matrix; i++) {
                    if (i == rows) continue;
                    int index = 0;
                    for (int j = 0; j < order_of_matrix; j++) {
                        if (j == columns) continue;
                        temp[row_index][index++] = array[i][j];
                    }
                    row_index++;
                }
                int minor_determinant = calculate(order_of_matrix - 1, temp);
                cofactor_matrix[rows][columns] = term * minor_determinant;
            }
        }
    }
}

void transpose(int order_of_matrix, int adjoint_matrix[order_of_matrix][order_of_matrix],int cofactor_matrix[order_of_matrix][order_of_matrix]){
    for(int i=0; i<order_of_matrix; i++){
        for(int j=0; j<order_of_matrix; j++){
            adjoint_matrix[i][j] = cofactor_matrix[j][i];
        }
    }
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
    printf("\nMatrix is:\n");
    for(int i=0; i<order_of_matrix; i++){
        for(int j=0; j<order_of_matrix; j++){
            printf("%d  ",array[i][j]);
        }
        printf("\n");
    }
    int determinant = calculate(order_of_matrix, array);
    printf("\nDeterminant = %d\n",determinant);
    
    if(determinant==0){
        printf("inverse of matrix not exist\n");
        return 0;
    }
    int cofactor_matrix[order_of_matrix][order_of_matrix];
    create(order_of_matrix, array,cofactor_matrix);

    printf("\nCofactor Matrix is:\n");
    for(int i=0; i<order_of_matrix; i++){
        for(int j=0; j<order_of_matrix; j++){
            printf("%d  ",cofactor_matrix[i][j]);
        }
        printf("\n");
    }
    int adjoint_matrix[order_of_matrix][order_of_matrix];
    transpose(order_of_matrix,adjoint_matrix,cofactor_matrix);
    
    printf("\nAdjoint Matrix is:\n");
    for(int i=0; i<order_of_matrix; i++){
        for(int j=0; j<order_of_matrix; j++){
            printf("%d  ",adjoint_matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("\nInverse Matrix is:\n");
    for(int i=0; i<order_of_matrix; i++){
        for(int j=0; j<order_of_matrix; j++){
            if(adjoint_matrix[i][j]%determinant != 0)
                printf("%d/%d  ",adjoint_matrix[i][j],determinant);
            else
                printf("%d     ",(adjoint_matrix[i][j]/determinant));

        }
        printf("\n");
    }
}