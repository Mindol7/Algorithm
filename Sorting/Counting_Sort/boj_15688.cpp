#include <bits/stdc++.h>

using namespace std;

void COUNTING_SORT(vector<int> &a, vector<int> &b, int k){
    const int SIZE = 2000001;
    const int OFFSET = 1000000;
    vector<int> c(SIZE,0);


    for(int j = 0; j < (int)a.size(); ++j){
        c[a[j]+OFFSET]++;
    }

    for(int i = 1; i < SIZE; ++i){
        c[i] = c[i] + c[i-1];
    }

    for(int j = a.size()-1; j >= 0; --j){
        b[c[a[j]+OFFSET]-1] = a[j];
        c[a[j]+OFFSET]--;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; ++i){
        int value;
        cin >> value;
        a[i] = value;
    }

    int k = *max_element(a.begin(), a.end());
    COUNTING_SORT(a,b,k);

    for(auto &i : b){
        cout << i << '\n';
    }

    return 0;
}