//All distinct pairs having sum = target
#include<stdio.h>
void merge(int lower_bound, int middle_index, int higher_bound, int size_of_array, int array[size_of_array]){
    int index1=lower_bound;
    int index2 = middle_index+1;
    int temp[size_of_array];
    int temp_array_index = lower_bound;
    while(index1<=middle_index && index2<=higher_bound){
        if(array[index1]<=array[index2]){
            temp[temp_array_index] = array[index1];
            index1++;
            temp_array_index++;
        }else{
            temp[temp_array_index] = array[index2];
            index2++;
            temp_array_index++;
        }
    }
    while(index1<=middle_index ){
        temp[temp_array_index] = array[index1];
        index1++;
        temp_array_index++;
        
    }
    while(index2<=higher_bound){
        temp[temp_array_index] = array[index2];
        index2++;
        temp_array_index++;
        
    }

    for (int i = lower_bound; i <= higher_bound; i++) {
        array[i] = temp[i];
    }
}
void mergesort(int low, int high, int size_of_array, int array[size_of_array]){
    if(low>=high){
        return;
    }
    int mid = low+(high-low)/2;
    mergesort(0,mid,size_of_array,array);
    mergesort(mid+1,high,size_of_array,array);
    merge(low,mid,high,size_of_array,array);
}
void twosum(int size_of_array, int array[size_of_array], int target){
    int i =0;
    int j = size_of_array-1;
    while(i<j){
        if(i>0 && array[i]==array[i-1]){
            i++;
            continue;
        }
        if(j<size_of_array-1 && array[j]==array[j+1]){
            j--;
            continue;
        }
        int sum = array[i] + array[j];
        if(sum<target){
            i++;
        }else if(sum>target){
            j--;
        }else{
            printf("{%d,%d}",i,j);
            i++;
            j--;
        }
    }
}
int main(){

    int size_of_array = 0;
    printf("Enter the size of array\n");
    scanf("%d",&size_of_array);
    int array[size_of_array];

    printf("Enter the elements of array\n");
    for(int i=0; i<size_of_array; i++){
        scanf("%d",&array[i]);
    }

    mergesort(0,size_of_array-1,size_of_array,array);

    int target = 0;
    printf("Enter the target\n");
    scanf("%d",&target);


    twosum(size_of_array,array,target);
}