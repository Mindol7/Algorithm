#include <bits/stdc++.h>
using namespace std;

int coin(const vector<int> &coins, int N, int K){
    int result = 0;
    int sum = 0;
    
    // for(int i = N-1; i >= 0; --i){
    //     sum += coins[i];
    //     if(sum == K) return result+1;
    //     if(sum > K){
    //         sum -= coins[i];
    //     }
    //     else if(sum < K){
    //         result++;
    //         ++i;
    //     }
    // }
    // return -1;

    for(int i = N-1; i >= 0; i--){
        result += K / coins[i];
        K %= coins[i];
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> coins(N);
    int money;
    for(int j = 0; j < N; ++j){
        cin >> money;
        coins[j] = money;
    }

    cout << coin(coins, N, K) << '\n';

    return 0;
}