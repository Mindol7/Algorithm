#include <bits/stdc++.h>
using namespace std;

int PARTITION(vector<int> &A, int p, int r, int k, int &count){
    int x = A[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; ++j) {
        if (A[j] <= x) {
            ++i;
            swap(A[i], A[j]);
            count++;
            if (count == k) {
                cout << A[i] << " " << A[j] << '\n';
                exit(0);
            }
        }
    }
    if(i+1 != r){ // 피벗이 원래 위치에 있을 때는 count 안해줌.
        swap(A[i + 1], A[r]);
        count++;
        if (count == k) {
            cout << A[i + 1] << " " << A[r] << '\n';
            exit(0);
        }
    }

    return i + 1;
}

void QUICK_SORT(vector<int> &A, int p, int r, int k, int &count){
    if (p < r) {
        int q = PARTITION(A, p, r, k, count);
        QUICK_SORT(A, p, q - 1, k, count);
        QUICK_SORT(A, q + 1, r, k, count);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, count = 0;
    cin >> n >> k;
    vector<int> A(n);

    for (int i = 0; i < n; ++i) cin >> A[i];

    QUICK_SORT(A, 0, n - 1, k, count);
    cout << -1 << '\n';
    return 0;
}
