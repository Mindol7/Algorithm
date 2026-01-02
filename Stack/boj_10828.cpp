#include <bits/stdc++.h>
using namespace std;

/**
 * push, top, size, empty, pop
 */
int main(){
    int N;
    cin >> N;
    string ins;
    stack<int> S;
    while(N-- >= 0){
        getline(cin, ins); 
        if(ins.find("push") != string::npos){
            string s = ins.substr(5,ins.size()-5);
            int num = stoi(s);
            S.push(num);
        }
        else if(ins.find("top") != string::npos){
            if(!S.empty()) cout << S.top() << '\n';
            else cout << "-1" << '\n';
        }
        else if(ins.find("size") != string::npos){
            cout << S.size() << '\n';
        }
        else if(ins.find("empty") != string::npos){
            cout << S.empty() << '\n';
        }
        else if(ins.find("pop") != string::npos){
            if(!S.empty()) {
                cout << S.top() << '\n';
                S.pop();
            }
            else cout << "-1" << '\n';
        }
    }
    return 0;
}