#include<stdio.h>
#include<stdlib.h>
int inbound(int i, int j, int n){
    if((i>=1 && i<=n) && (j>=1 && j<=n)){
        return 1;
    }
    return 0;
}
void levelrotate(int n, int array[n+1][n+1]){
    int i=0; 
    int j=0;
    scanf("%d %d",&i,&j);
    if(!inbound(i,j,n)){
        printf("Invalid");
        exit(0);
    }
    else{
        if(array[i][j] ==0){
            array[i][j] = 1;
        }else{
            array[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}
void transpose(int n, int array[n+1][n+1]){
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
}
void reverse(int low, int high, int n, int array[n]){
    int i=low;
    int j=high;
    while(i<=j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}
void rotate_clockwise(int n, int array[n+1][n+1]){
    transpose(n,array);
    for(int i=1; i<=n; i++){
        reverse(1,n,n,array[i]);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}

void flip_horizontally(int n, int array[n+1][n+1]){
    for(int i=1; i<=n; i++){
        reverse(1,n,n,array[i]);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n = 0;
    scanf("%d",&n);
    int m = 0;
    scanf("%d",&m);
    
    int array[n+1][n+1];
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            array[i][j] = 0;
        }
    }
    
    while(m>0){
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: levelrotate(n,array);break;
            case 2: flip_horizontally(n,array);break;
            case 3: rotate_clockwise(n,array);break;
            default: exit(0);
        }
        m--;
    }
    
}