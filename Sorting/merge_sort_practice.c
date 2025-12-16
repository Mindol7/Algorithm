#include <stdio.h>
#include <limits.h>
#define SIZE 6

int* merge_sort(int* arr, int p, int r){
    int q;
    if(p < r){
        q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }

    return arr;
}

void merge(int* arr, int p, int q, int r){
    // STEP 1: 새로운 배열 생성을 위한 준비 (거리 확인, 배열 생성)
    int n1 = q - p + 1;
    int n2 = r - q;
    int left_arr[n1+1], right_arr[n2+1];

    // STEP 2: 배열 복사
    for(int i = 0; i < n1; i++) {
        left_arr[i] = arr[p+i];
    }
    for(int j = 0; j < n2; j++) {
        right_arr[j] = arr[q+j+1];
    }
    left_arr[n1] = INT_MAX;
    right_arr[n2] = INT_MAX;

    // STEP 3: 정렬
    int i = 0, j = 0;
    for(int k = p; k <= r; k++) {
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }
        else{
            arr[k] = right_arr[j];
            j++;
        }
    }
}



int main() {
    int unsorted_arr[6] = {8,2,4,9,3,6};

    printf("Before Sorted: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", unsorted_arr[i]);
    }
    printf("\n");

    // int* sorted_arr = insertion_sort(unsorted_arr);
    int* sorted_arr = merge_sort(unsorted_arr, 0, 5);
    printf("After Sorted: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    return 0;
}