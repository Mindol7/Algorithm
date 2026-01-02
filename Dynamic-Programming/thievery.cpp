#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money){
    int sum = 0;
    if(money.size() > 4){
        for(const auto& i : money){
            sum += i;
        }
        return sum;
    }
    else if(money.size() == 3){
        return *max_element(money.begin(), money.end());
    }
    else{ // money.size == 4
        int case_1 = money[0] + money[2];
        int case_2 = money[1] + money[3];

        if(case_1 > case_2) {
            return case_1;
        }
        else {
            return case_2;
        }
    }
}

int main(){
    vector<int> money = {1, 2, 3};

    cout << solution(money) << endl; // 4

    return 0;
}