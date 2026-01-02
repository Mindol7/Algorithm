#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> left(n1+1);
    vector<int> right(n2+1);

    for(int i = 0; i < n1; ++i){
        left[i] = arr[p+i];
    }
    for(int j = 0; j < n2; ++j){
        right[j] = arr[q+j+1];
    }

    int limits = numeric_limits<int>::max();

    left[n1] = limits; right[n2] = limits;

    int i = 0, j = 0;

    for(int k = p; k <= r; ++k){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
    }
}

void merge_sort(vector<int> &arr, int p, int r){
    int q;
    if(p < r){
        q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    merge_sort(arr, 0, n-1);

    for(auto &i : arr){
        cout << i << " ";
    }

    return 0;
}