#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[5] = {-2,2,4,6,13};
    int n = 5;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n-1-i; ++j){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }

    return 0;
}