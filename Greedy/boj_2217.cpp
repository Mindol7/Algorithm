#include <bits/stdc++.h>
using namespace std;

/**
 * 임의로 몇개의 로프를 선택해도됨.
 * 가장 큰 무게 들 수 있는 로프부터 검사.
 * 10 9 8 4 2 1 -> (1개면 10, 2개면 18, 3개면 24, 4개면 16)
 */

int greedy(vector<int> &loop, int N){
    int result = 0;
    int select_loop_num = 1; // 임의로 선택된 로프들
    vector<int> select_weight(N, 0);
    for(int i = N-1; i >= 0; --i){
        select_weight[N-1-i] = (N-i) * loop[i];
    }

    return *max_element(select_weight.begin(), select_weight.end());
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> loop(N);
    for(int i = 0; i < N; ++i){
        cin >> loop[i];
    }
    sort(loop.begin(), loop.end()); // 크기 순으로 정렬
    cout << greedy(loop, N);

    return 0;
}