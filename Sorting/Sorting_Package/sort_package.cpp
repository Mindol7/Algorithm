#include <bits/stdc++.h>
using namespace std;

/**
 * n: 배열 A의 크기
 * 1. Bubble Sort: 이중 for문으로 최댓값들을 마지막에 위치 시키는 IDEA
 * 2. Selection Sort: last와 최댓값을 바꾸는 IDEA
 * 3. Insertion Sort: key로 저장하고 위치를 찾아간다.
 * 4. Merge Sort
 * 5. Quick Sort
 */

void bubble_sort(vector<int> A, int n){
    for(int last = 0; last < n; last--){
        for(int i = 0; i < n-last-1; ++i){
            if(A[i] > A[i+1]) swap(A[i], A[i+1]);
        }
    }
}

void selection_sort(vector<int> A, int n){
    for(int last = n-1; last >= 0; --last){
        auto max = *max_element(A.begin(), A.begin()+last+1);
        if(A[last] != max) swap(A[last], max);
    }
}

void insertion_sort(vector<int> A, int n){
    for(int j = 1; j < n; ++j){
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] >= key){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i+1] = key;
    }
}

void Merge(vector<int> A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1], R[n2+1];
    for(int i = 0; i < n1; ++i){
        L[i] = A[p + i]; 
    }
    for(int j = 0; j < n2; ++j){
        R[j] = A[q+j+1];
    }
    auto INF = std::numeric_limits<int>::max();
    L[n1] = INF; R[n2] = INF;

    int i=0,j=0;
    for(int k = p; k < r; ++k){
        if(L[i] >= R[j]){
            A[k] = R[j];
            j++;
        }
        else{
            A[k] = L[i];
            i++;
        }
    }
}

void Merge_Sort(vector<int> A, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        Merge_Sort(A, p, q);
        Merge_Sort(A, q+1, r);
        Merge(A, p, q, r);
    }
}

int Partition(vector<int> A, int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r; ++j){
        if(A[j] < x){
            i = i + 1;
            swap(A[j], A[i]);
        }
    }
    swap(A[i+1], A[r]);

    return i+1;
}

void Quick_Sort(vector<int> A, int p, int r){
    if(p < r){
        int q = Partition(A, p, r);
        Quick_Sort(A, p, q-1);
        Quick_Sort(A, q+1, r);
    }
}