#include <bits/stdc++.h>
using namespace std;
#define SIZE 20000005

int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(a[mid] >= target) en = mid; // target이 처음등장하면 왼쪽에 있는지도 봐야함 (en을 mid로 조정)
        else st = mid+1; // 현재 위치 mid가 target보다 작으니까 mid+1로 조정
    }
    return st;
}

int upper_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(a[mid] > target) en = mid; // 큰게 처음 등장하면 왼쪽에 있는지도 봐야하니까 en=mid로 조정
        else st = mid + 1; // 현재 위치 mid가 target보다 작거나 같으니까 st를 mid+1로 조정
        // 어차피 우리는 큰게 처음 등장하는거 찾는게 목표. (같은 값 등장하면 같은 값 오른쪽으로 이동하여 큰게 나타나는거 찾도록함.)
    }
    return st;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A[500005], target[500005], result[SIZE];
    int N, M;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    cin >> M;
    
    fill(result, result+SIZE,-1);

    for(int i = 0; i < M; ++i){
        cin >> target[i];
    }

    sort(A, A+N);
    int min_value = 10000000;
    
    for(int i = 0; i < M; ++i){
        int low = 0, high = N-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(A[mid] == target[i]){
                int left = mid - 1, right = mid + 1;
                int cnt = upper_bound(A, A+N, target[i]) - lower_bound(A, A+N, target[i]);
                result[target[i]+min_value] = cnt;
                break;
            }
            else if(A[mid] < target[i]) low = mid+1;
            else high = mid-1;
        }
        if(low > high){
            result[target[i]+min_value] = 0;
        }
    }

    for(int i = 0; i < M; ++i){
        if(result[target[i]+min_value] != -1) cout << result[target[i]+min_value] << " ";
    }

    return 0;
}