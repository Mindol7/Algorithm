#include <bits/stdc++.h>
using namespace std;

/** 보류 */
void bubble_sort(vector<int> &arr, int k){
    int count = 0;

    for(int last = arr.size()-1; last > 0; --last){
        for(int i = 0; i < last; ++i){
            if(arr[i] > arr[i+1]) {
                count++;
                if(count == k){
                    cout << arr[i+1] << " " << arr[i];
                    return;
                }
                swap(arr[i], arr[i+1]);
            }
        }
    }
    cout << -1;
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    bubble_sort(arr, k);

    return 0;
}