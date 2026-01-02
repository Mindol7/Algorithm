#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 배열의 요소를 각각 곱함
 * 2. S의 값 가장 작게 해야함. (A 재배열), B는 재배열 못함.
 */

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
  
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int s = 0;
    for(int i = 0; i < n; ++i){
        s += a[i] * b[i];
    }

    cout << s;
    return 0;
}