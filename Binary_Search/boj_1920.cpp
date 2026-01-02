#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A[100005];
    int target[100005];
    int N, M;

    cin >> N;
    for(int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    cin >> M;
    for(int i = 0; i < M; ++i) cin >> target[i];
    
    for(int i = 0; i < M; ++i){
        int low = 0, high = N-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(A[mid] == target[i]){
                cout << 1 << '\n';
                break;
            } 
            else if(A[mid] > target[i]){
                high = mid - 1;
            }
            else{ // A[mid] < target[i]
                low = mid + 1;
            }
        }
        if(low > high) cout << 0 <<'\n';
    }

    return 0;  
}