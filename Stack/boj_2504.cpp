#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<char> S;
    string str;
    cin >> str;
    int acc = 1;
    int ans = 0;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '('){
            S.push(str[i]);
            acc *= 2;
        }
        else if(str[i] == '['){
            S.push(str[i]);
            acc *= 3;
        }
        else if(str[i] == ')'){
            if(!S.empty() && S.top() == '('){    
                if(str[i-1] == '('){    
                    ans += acc;
                }
                acc /= 2;
                S.pop();
            }   
            else{
                cout << 0 << '\n';
                return 0;
            }
        }
        else if(str[i] == ']'){
            if(!S.empty() && S.top() == '['){
                if(str[i-1] == '['){    
                    ans += acc;
                }
                acc /= 3;
                S.pop();
            }   
            else{
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    if(!S.empty()) ans = 0;

    cout << ans << '\n';

    return 0;
}