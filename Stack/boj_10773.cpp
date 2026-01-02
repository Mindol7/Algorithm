#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> S;
    int sum = 0;
    while(N--){
        int i;
        cin >> i;
        if(i == 0) S.pop();
        else S.push(i); 
    }
    while(!S.empty()){
        sum += S.top();
        S.pop();
    }
    cout << sum;
    return 0;
}