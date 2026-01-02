#include <bits/stdc++.h>

using namespace std;

void COUNTING_SORT(vector<int> &a, vector<int> &b, int k){
    vector<int> c(k);

    for(int i = 0; i < k; ++i){
        c[i] = 0;
    }

    for(int j = 0; j < a.size(); ++j){
        c[a[j]]++;
    }

    for(int i = 0; i < k; ++i){
        c[i] = c[i] + c[i-1];
    }

    for(int j = a.size()-1; j >= 0; j--){
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

int main(){

    return 0;
}