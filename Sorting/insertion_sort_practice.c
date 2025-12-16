#include <stdio.h>
#define SIZE 6

int* asc_insertion_sort(int* arr) {
    int key, i;
    // 이중 반복 사용 (key 복사, 끝도달확인 및 비교)
    for(int j = 1; j < SIZE; j++){
        key = arr[j];
        i = j-1;
        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }

    return arr;
}

int* desc_insertion_sort(int* arr) {
    int key, i;
    for(int j = 1; j < SIZE; j++){
        key = arr[j];
        i = j-1;
        while(i >= 0 && arr[i] < key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
    return arr;
}
    

int main() {
    int unsorted_arr[SIZE] = {8,2,4,9,3,6};
    int* sorted_arr;

    printf("Before Sorted: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", unsorted_arr[i]);
    }
    printf("\n");

    // sorted_arr = asc_insertion_sort(unsorted_arr);
    sorted_arr = desc_insertion_sort(unsorted_arr);
    printf("After Sorted: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");


    return 0;
}