#include <bits/stdc++.h>

using namespace std;

int PARTITION(vector<int> &arr, int p, int r){
    int x = arr[r];
    int i = p-1;
    for(int j = p; j <= r-1; ++j){
        if(arr[j] <= x){
            i = i+1;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void QUICKSORT(vector<int> &arr, int p, int r){
    if(p<r){
        int q = PARTITION(arr, p, r); // pivot 위치 찾기
        QUICKSORT(arr, p, q-1);  // 왼쪽부분 정렬
        QUICKSORT(arr, q+1, r);  // 오른쪽 부분 정렬
    }
}

int main(){

    return 0;
}