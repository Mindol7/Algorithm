#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr, int n, int k){
    int count = 0;
    int key;
    for(int j = 1; j < n; ++j){
        key = arr[j];
        int i = j-1;
        bool moved = false;

        while(i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            count++;
            if(count == k){
                cout << arr[i+1];
                return;
            }
            i--;
            moved = true;
        }
        if(moved){ // moved가 false면 제자리에 있던거임.
            arr[i+1] = key;
            count++;
            if(count == k){    
                cout << key;
                return;
            }
        }
        
    }

    cout << -1;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    insertion_sort(arr, n, k);

    return 0;
}