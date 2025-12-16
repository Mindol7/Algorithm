#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int rows = str1.length()+1;
    int cols = str2.length()+1;
    vector<vector<int>> vec(rows, vector<int>(cols, 0));

    for(int i = 1; i < rows; ++i){
        for(int j = 1; j < cols; ++j){
            if(str1[i] == str2[j]){
                vec[i][j] = vec[i-1][j-1] + 1;
            }
            else{
                vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
            }
        }
    }
    int result = vec[rows-1][cols-1];
    return result;
}

int main(void) {
    string str1 = "ABCBDAB";
    string str2 = "BDCAB";
    string str3 = "AGGTAB";
    string str4 = "GXTXAYB";
    
    cout << solution(str1, str2) << endl; // 4
    cout << solution(str3, str4) << endl; // 4

    return 0;
}