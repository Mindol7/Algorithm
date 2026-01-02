#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> A(N), sortedA;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    sortedA.erase(unique(sortedA.begin(), sortedA.end()), sortedA.end());

    for(int i = 0; i < N; ++i){
        int idx = lower_bound(sortedA.begin(), sortedA.end(), A[i]) - sortedA.begin();
        cout << idx << " ";
    }

    return 0;
}