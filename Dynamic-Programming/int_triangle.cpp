    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int solution(vector<vector<int>> triangle) {
        size_t rows = triangle.size();
        size_t cols = triangle[rows-1].size();

        vector<vector<int>> dp(rows, vector<int>(cols,0)); // 5x5 dp table

        dp[0][0] = triangle[0][0]; // 7
        for(int i = 1; i < rows; ++i) {
            for(int j = 0; j <= i; ++j) {
                if (j == 0){
                    dp[i][0] = triangle[i][0] + dp[i-1][0];
                }
                else if (j==i){
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else {    
                    dp[i][j] = max(triangle[i][j] + dp[i-1][j-1], triangle[i][j] + dp[i-1][j]);
                }
            }
        }
        int result = 0;
        for(int j = 0; j < cols; ++j) {
            result = max(dp[rows-1][j], result);
        }

        return result;
    }

    int main() {
        vector<vector<int>> triangle = {
            {7},
            {3,8},
            {8,1,0},
            {2,7,4,4},
            {4,5,2,6,5}
        };

        int result = solution(triangle);

        cout << result << endl;

        return 0;
    }