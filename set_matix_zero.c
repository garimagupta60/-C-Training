#include<stdio.h>
void set_matrix(int rows, int columns, int matrix[rows][columns]){
    int column_zero = 1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(matrix[i][j]==0){
                if(i==0){
                    matrix[0][0] = 0;
                }else if(j==0){
                    column_zero = 0;
                }else{
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    }
    for(int i=1; i<rows; i++){
        for(int j=1; j<columns; j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j=1; j<columns; j++){
            matrix[0][j] = 0;
        }
    }
    if(column_zero==0){
        for(int i=1; i<rows; i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    int rows = 0;
    int columns = 0;
    printf("Enter rows and columns\n");
    scanf("%d %d",&rows,&columns);
    int matrix[rows][columns];
    printf("Enter matrix\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("matrix\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    set_matrix(rows, columns, matrix);

    printf("Set matrix\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

}