#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> Q;
    string s;
    int n;
    int a;
    cin >> n;
    while(n-- > 0){
        cin >> s;
        if(s == "push"){
            cin >> a;
            Q.push(a);
        }
        else if(s == "pop"){
            if(Q.empty()){
                cout << "-1" << '\n';
            }else{    
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        else if(s == "size"){
            cout << Q.size() << '\n';
        }
        else if(s == "empty"){
            if(Q.empty()){
                cout << "1" << '\n';
            }
            else{
                cout << '0' << '\n';
            }
        }
        else if(s == "front"){
            if(!Q.empty()) cout << Q.front() << '\n';
            else cout << "-1" << '\n';
        }
        else if(s == "back"){
            if(!Q.empty()) cout << Q.back() << '\n';
            else cout << "-1" << '\n';
        }
    }
    return 0;
}