#include<stdio.h>
void swap(int *number1, int* number2){
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}
void selection_sort(int size_of_array, int array[size_of_array]){
    for(int i=0; i<=size_of_array-2; i++){
        int mini_index = i;
        for(int j = i; j<size_of_array; j++){
            if(array[j]<array[mini_index]){
                mini_index = j;
            }
        }
        swap(&array[i], &array[mini_index]);
    }
}
void bubble_sort(int size_of_array, int array[size_of_array]){
    for(int i=size_of_array-1; i>=1; i--){
        for(int j=0; j<=i-1; j++){
            if(array[j]>array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
}
void insertion_sort(int size_of_array, int array[size_of_array]){
    for(int i=0; i<=size_of_array-1; i++){
        int j = i;
        while(j>0 && array[j]<array[j-1]){
            swap(&array[j], &array[j-1]);
            j--;
        }
    }
}
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
void merge_sort(int lower_bound, int higher_bound, int size_of_array, int array[size_of_array]){
    if(lower_bound>=higher_bound)return;
    int middle_index = lower_bound+(higher_bound-lower_bound)/2;
    merge_sort(lower_bound,middle_index,size_of_array,array);
    merge_sort(middle_index+1,higher_bound,size_of_array,array);
    merge(lower_bound, middle_index, higher_bound, size_of_array, array);
}

int partition(int lower_bound, int higher_bound, int size_of_array, int array[size_of_array]){
    int pivot = array[lower_bound];
    int i = lower_bound;
    int j= higher_bound;
    while(i<j){
        while(array[i]>=pivot && i<=j){
            i++;
        }
        while(array[j]<pivot && j>=i){
            j--;
        }
        if(i<j)swap(&array[j],&array[i]);
    }
    swap(&array[j],&array[lower_bound]);
    return j;
} 
void quicksort(int lower_bound, int higher_bound, int size_of_array, int array[size_of_array]){
    if(lower_bound>=higher_bound)return;
    int pivot_index = partition(lower_bound, higher_bound, size_of_array, array);
    quicksort(lower_bound,pivot_index-1,size_of_array,array);
    quicksort(pivot_index+1,higher_bound,size_of_array,array);
}
int main(){
    int array[100];
    int size_of_array = 0;
    printf("Enter the size of array\n");
    scanf("%d",&size_of_array);
    for(int i=0; i<size_of_array; i++){
        scanf("%d",&array[i]);
    }

    // selection_sort(size_of_array, array);
    // printf("Sorted array\n");
    // for(int i=0; i<size_of_array; i++){
    //     printf("%d ",array[i]);
    // }

    // bubble_sort(size_of_array, array);
    // printf("Sorted array\n");
    // for(int i=0; i<size_of_array; i++){
    //     printf("%d ",array[i]);
    // }

    // insertion_sort(size_of_array, array);
    // printf("Sorted array\n");
    // for(int i=0; i<size_of_array; i++){
    //     printf("%d ",array[i]);
    // }
    // merge_sort(0,size_of_array-1,size_of_array, array);
    // printf("Sorted array\n");
    // for(int i=0; i<size_of_array; i++){
    //     printf("%d ",array[i]);
    // }
    quicksort(0,size_of_array-1,size_of_array, array);
    printf("Sorted array\n");
    for(int i=0; i<size_of_array; i++){
        printf("%d ",array[i]);
    }
}