#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, int p, int q, int r, int k, int &count){
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    const int INF = numeric_limits<int>::max();

    for(int i = 0; i < n1; ++i) L[i] = A[p + i];
    for(int j = 0; j < n2; ++j) R[j] = A[q + 1 + j];
    L[n1] = R[n2] = INF;

    int i = 0, j = 0;
    for(int t = p; t <= r; ++t){
        if(L[i] <= R[j]){
            A[t] = L[i++];
        } else {
            A[t] = R[j++];
        }
        count++;
        if(count == k){
            cout << A[t] << '\n';
            exit(0);  // 바로 종료
        }
    }
}

void merge_sort(vector<int> &A, int p, int r, int k, int &count){
    if(p < r){
        int q = (p + r) / 2;
        merge_sort(A, p, q, k, count);
        merge_sort(A, q + 1, r, k, count);
        merge(A, p, q, r, k, count);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(int i = 0; i < n; ++i) cin >> A[i];

    int count = 0;
    merge_sort(A, 0, n - 1, k, count);

    cout << -1 << '\n';  // K번 저장 안 됐을 경우
}
