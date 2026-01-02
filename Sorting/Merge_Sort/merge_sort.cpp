#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> left(n1+1, 0);
    vector<int> right(n2+1, 0);

    for(int i = 1; i < n1; ++i){
        left[i] = arr[p+i-1]; // p ~ q
    }
    for(int j = 1; j < n2; ++j){
        right[j] = arr[q+j]; // q+1 ~ r
    }

    int i = 1, j = 1;

    for(int k = p; k < r; ++k){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            ++i;
        }
        else{
            arr[k] = right[j];
            ++j;
        }
    }
}

vector<int> merge_sort(vector<int> arr, int p, int r){
    if (p < r){
        int q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    vector<int> unsorted_arr = {8,2,4,9,3,6};

    printf("Before Sorted: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", unsorted_arr[i]);
    }
    printf("\n");

    // int* sorted_arr = insertion_sort(unsorted_arr);
    vector<int> sorted_arr = merge_sort(unsorted_arr, 0, 5);
    printf("After Sorted: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");


    return 0;
}