#include <stdio.h>
#define INT_MAX 65536

int* merge_sort(int* unsorted_arr, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        merge_sort(unsorted_arr, p, q);
        merge_sort(unsorted_arr, q+1, r);
        merge(unsorted_arr, p, q, r);
    }

    return unsorted_arr;
}

void merge(int* unsorted_arr, int p, int q, int r) {
    // STEP 1) left, right 배열 크기 계산 후 주기
    int n1 = q - p + 1;
    int n2 = r - q;
    int left_arr[n1+1];
    int right_arr[n2+1];

    // STEP 2) left, right 배열 복사
    for(int i = 0; i < n1; i++) {
        left_arr[i] = unsorted_arr[p + i]; 
    }

    for(int j = 0; j < n2; j++) {
        right_arr[j] = unsorted_arr[q + 1 + j];
    }
    left_arr[n1] = INT_MAX;
    right_arr[n2] = INT_MAX;

    int i=0, j=0;

    for(int k = p; k <= r; k++) {
        if(left_arr[i] <= right_arr[j]){
            unsorted_arr[k] = left_arr[i];
            i++;
        }
        else {
            unsorted_arr[k] = right_arr[j];
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