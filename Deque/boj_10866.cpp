#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> DQ;
    int n;
    string s;
    int a;
    cin >> n;

    while(n-- > 0){
        cin >> s;
        if(s == "push_front"){
            cin >> a;
            DQ.push_front(a);
        }
        else if(s == "push_back"){
            cin >> a;
            DQ.push_back(a);
        }
        else if(s == "pop_front"){
            if(DQ.empty()) cout << "-1" << '\n';
            else{
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if(s == "pop_back"){
            if(DQ.empty()) cout << "-1" << '\n';
            else{
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
            
        }
        else if(s == "size"){
            cout << DQ.size() << '\n';
        }
        else if(s == "empty"){
            if(DQ.empty()){
                cout << '1' << '\n';
            }
            else cout << '0' << '\n';
        }
        else if(s == "front"){
            if(DQ.empty()) cout << "-1" << '\n';
            else cout << DQ.front() << '\n';
        }
        else if(s == "back"){
            if(DQ.empty()) cout << "-1" << '\n';
            else cout << DQ.back() << '\n';
        }
    }

    return 0;
}