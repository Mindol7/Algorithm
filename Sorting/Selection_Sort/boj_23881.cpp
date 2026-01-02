#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr, int k){
    int count = 0;
    for(int last = arr.size()-1; last >= 1; --last){
        auto max = max_element(arr.begin(), arr.begin() + last + 1);
        if(arr[last] != *max) {
            // count++;
            // if(count == k){
            //     cout << arr[last] << " " << *max ;
            //     return;
            // }
            swap(arr[last], *max);
        }
    }

    cout << -1;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    selection_sort(arr, k);

    return 0;
}