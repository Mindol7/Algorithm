#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    size_t rows = land.size();
    size_t cols = land[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];

    for(int i = 1; i < rows; ++i) {
        dp[i][0] = land[i][0] + max({dp[i-1][1], dp[i-1][2], dp[i-1][3]});
        dp[i][1] = land[i][1] + max({dp[i-1][0], dp[i-1][2], dp[i-1][3]});
        dp[i][2] = land[i][2] + max({dp[i-1][0], dp[i-1][1], dp[i-1][3]});
        dp[i][3] = land[i][3] + max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }

    return max({dp[rows-1][0], dp[rows-1][1], dp[rows-1][2], dp[rows-1][3]});
}

int main() {
    vector<vector<int>> land = {
        {1, 2, 3, 5},
        {5, 6, 7, 8},
        {4, 3, 2, 1}
    };

    cout << solution(land) << endl; // 16

    return 0;
}