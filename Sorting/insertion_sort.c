#include <stdio.h>
#include <stdlib.h>

int* insertion_sort(int* unsorted_arr) {
    int key;
    int i,j;

    for(int j = 1; j < 6; j++){
        key = unsorted_arr[j];
        i = j-1;
        while(i >= 0 && key < unsorted_arr[i]) {
            unsorted_arr[i+1] = unsorted_arr[i];
            i--;
        }

        unsorted_arr[i+1] = key;
    }

    return unsorted_arr;
}

int* desc_insertion_sort(int* unsorted_arr) {
    int key;
    int i,j;

    for(j = 1; j < 6; j++) {
        key = unsorted_arr[j];
        i = j-1;

        while(i >= 0 && key > unsorted_arr[i]) {
            unsorted_arr[i+1] = unsorted_arr[i];
            i = i-1;
        }
        unsorted_arr[i+1] = key;
    }

    return unsorted_arr;
}

int main() {
    int unsorted_arr[6] = {8,2,4,9,3,6};

    printf("Before Sorted: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", unsorted_arr[i]);
    }
    printf("\n");

    // int* sorted_arr = insertion_sort(unsorted_arr);
    int* sorted_arr = desc_insertion_sort(unsorted_arr);
    printf("After Sorted: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    return 0;
}