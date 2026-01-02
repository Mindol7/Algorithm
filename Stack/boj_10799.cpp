#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<pair<char, int>> S;
    string str;
    cin >> str;
    vector<double> lazer;
    vector<pair<int,int>> stick;
    int stick_start;
    int stick_end;
    int sum = 0;

    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '(') {
            S.push({'(', i}); // Ex) { (,4 };
        }
        else if(str[i] == ')') {
            if(str[i-1] == '('){
                lazer.push_back((double)(i+i-1)/2);
                S.pop();
            }
            else{
                stick_start = S.top().second;
                stick_end = i;
                stick.push_back({stick_start, stick_end});
                S.pop();
            }
        }
    }

    for(auto i : stick){
        int result = 1;
        for(int j = 0; j < lazer.size(); ++j){
            if(lazer[j] > i.first && lazer[j] < i.second){
                result += 1;
            }
        }
        sum += result;
    }
    cout << sum << '\n';

    return 0;
}