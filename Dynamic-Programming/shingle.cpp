#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> arr){
    int result = 0;
    size_t n = arr.size();
    vector<vector<int>> dp(4, vector<int>(arr[0].size(), 0));
    size_t cols = arr[0].size();

    dp[0][0] = arr[0][0]; // pattern 0
    dp[1][0] = arr[1][0]; // pattern 1
    dp[2][0] = arr[2][0]; // pattern 2
    dp[3][0] = arr[0][0] + arr[2][0]; // pattern 3

    for(int i = 1; i < arr[0].size(); ++i) {
        dp[0][i] = arr[0][i] + max(dp[1][i-1], dp[2][i-1]); // pattern 0이 선택된 경우, pattern 1,2 가능
        dp[1][i] = arr[1][i] + max({dp[0][i-1], dp[2][i-1], dp[3][i-1]}); // pattern 1이 선택된 경우, pattern 0,2,3 가능
        dp[2][i] = arr[2][i] + max(dp[0][i-1], dp[1][i-1]); // pattern 2이 선택된 경우, pattern 0,1 가능
        dp[3][i] = arr[0][i] + arr[2][i] + dp[1][i-1]; // pattern 3이 선택된 경우, pattern 1 가능
    }

    return max({dp[0][cols-1], dp[1][cols-1], dp[2][cols-1], dp[3][cols-1]});
}

int main(){
    vector<vector<int>> v1 = {
        {1,3,3,2},
        {2,1,4,1},
        {1,5,2,3}
    };
    vector<vector<int>> v2 = {
        {1,7,13,2,6},
        {2,-4,2,5,4},
        {5,3,5,-3,1}
    };

    cout << solution(v1) << endl; // 19
    cout << solution(v2) << endl; // 32

    return 0;
}