#include<stdio.h>
int union_of_arrays(int size_of_array1,int size_of_array2,int array1[size_of_array1],int array2[size_of_array2],int array3[size_of_array1+size_of_array2]){
    int i=0;
    int j = 0;
    int index = 0;
    while(i<size_of_array1 && j<size_of_array2){
        if(array1[i]<=array2[j]){
            if(index==0 || array3[index-1]!=array1[i]){
                array3[index++] = array1[i];

            }
            i++;
            
        }else{
            if(index==0 || array3[index-1]!=array2[j]){
                array3[index++] = array2[j];

            }
            j++;
            
        }
    }
    while(i<size_of_array1){
        if(index==0 || array3[index-1]!=array1[i]){
            array3[index++] = array1[i];
        }
        i++;
        
    }
    while(j<size_of_array2){
        if(index==0 || array3[index-1]!=array2[j]){
            array3[index++] = array2[j];
        }
        j++;
        
    }
    return index;

}
int main(){
    int size_of_array1 = 0;
    printf("Enter the size of array 1\n");
    scanf("%d",&size_of_array1);
    int size_of_array2 = 0;
    printf("Enter the size of array 2\n");
    scanf("%d",&size_of_array2);

    int array1[size_of_array1];
    int array2[size_of_array2];
    printf("Enter array1:\n");
    for(int i=0; i<size_of_array1;i++){
        scanf("%d",&array1[i]);
    }
    printf("Enter array2:\n");
    for(int i=0; i<size_of_array2;i++){
        scanf("%d",&array2[i]);
    }

    int array3_size = size_of_array1 + size_of_array2;
    int array3[array3_size];


    int size = union_of_arrays(size_of_array1,size_of_array2,array1,array2,array3);

    for(int i=0; i<size; i++){
        printf("%d ",array3[i]);
    }
}