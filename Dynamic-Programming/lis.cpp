#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(const vector<int> nums){
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;

    for(int i = 1; i < nums.size(); ++i){
        for(int j = 0; j < i; ++j){
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    auto result = max_element(dp.begin(), dp.end());
    return *result;
}

int main(){
    vector<int> nums = {1,4,2,3,1,5,7,3};
    vector<int> nums2 = {3,2,1};   

    cout << solution(nums) << endl; // 5
    cout << solution(nums2) << endl; // 1
    return 0;
}