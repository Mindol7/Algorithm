#include <bits/stdc++.h>
using namespace std;

int PARTITION(vector<int> &A, int p, int r){
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; ++j) {
        if (A[j] <= x) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    if(i+1 != r){ // 피벗이 원래 위치에 있을 때는 count 안해줌.
        swap(A[i + 1], A[r]);
    }
    return i + 1;
}

void QUICK_SORT(vector<int> &A, int p, int r){
    if (p < r) {
        int q = PARTITION(A, p, r);
        QUICK_SORT(A, p, q - 1);
        QUICK_SORT(A, q + 1, r);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; ++i) cin >> A[i];

    QUICK_SORT(A, 0, n - 1);

    for(auto i : A){
        cout << i << '\n';
    }
    return 0;
}
