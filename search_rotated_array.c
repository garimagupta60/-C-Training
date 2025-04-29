#include<stdio.h>
int mini(int *number1, int *number2){
    if(*number1>*number2){
        return *number2;
    }else{
        return *number1;
    }
}
int search_in_array(int sizeofarray, int array[sizeofarray], int element){
    int low = 0;
    int high = sizeofarray-1;
    while(low<=high){
        int mid_index = low + (high-low)/2;
        if(array[mid_index] == element)return 1;
        if(array[low]<=array[mid_index]){
            if(array[low]<=element && element<=array[mid_index]){
                high = mid_index-1;
            }else{
                low = mid_index + 1;
            }
        }else{
            if(array[mid_index]<=element && element<=array[high]){
                low = mid_index+1;
            }else{
                high = mid_index - 1;
            }
        }
    }
    return 0;
}
int min_in_array(int sizeofarray, int array[sizeofarray]){
    int low = 0;
    int high = sizeofarray-1;
    int ans = __INT_MAX__;
    
    while(low<=high){
        int mid_index = low + (high-low)/2;
        if(array[low]<=array[mid_index]){
            ans = mini(&ans,&array[low]);
            low = mid_index+1;
        }else{
            ans = mini(&ans,&array[mid_index]);
            high = mid_index-1;
        }
    }
    return ans;
}
int index_of_element(int sizeofarray, int array[sizeofarray]){
    int low = 0;
    int high = sizeofarray-1;
    int ans = __INT_MAX__;
    int index = 0;
    while(low<=high){
        int mid_index = low + (high-low)/2;
        if(array[low]<=array[mid_index]){
            if(ans>array[low]){
                ans = array[low];
                index = low;
            }
            low = mid_index+1;
        }else{
            if(ans>array[mid_index]){
                ans = array[mid_index];
                index = mid_index;
            }
            high = mid_index-1;
        }
    }
    return index;
}
int find_peak(int sizeofarray, int array[sizeofarray]){
    if(sizeofarray==1)return 0;
    if(array[0]>array[1])return 0;
    if(array[sizeofarray-1]>array[sizeofarray-2])return sizeofarray-1;

    int low = 1;
    int high = sizeofarray-2;
    while(low<=high){
        int mid_index = low + (high-low)/2;
        if((array[mid_index-1]<array[mid_index]) && (array[mid_index]>array[mid_index+1])){
            return mid_index;
        }
        else if(array[mid_index-1]<array[mid_index]){
            low = mid_index+1;
        }else{
            high = mid_index-1;
        }
    }
}
int main(){
    int sizeofarray = 0;
    printf("Enter the size of array\n");
    scanf("%d",&sizeofarray);
    int array[sizeofarray];
    printf("Enter the rotated sorted array\n");
    for(int i=0; i<sizeofarray; i++){
        scanf("%d",&array[i]);
    }
    int element = 0;
    printf("Enter the element to search\n");
    scanf("%d",&element);
    int found = search_in_array(sizeofarray,array,element);
    if(found){
        printf("Element found in array\n");
    }else{
        printf("Element is not found\n");
    }

    // int min_element = min_in_array(sizeofarray,array);
    // printf("%d",min_element);

    // int index1 = index_of_element(sizeofarray,array);
    // printf("No. of times array is rotated\n");
    // printf("%d",index1);

    printf("Peak element in array\n");
    int peak_element = find_peak(sizeofarray,array);
    printf("%d",peak_element);


    return 0;
}