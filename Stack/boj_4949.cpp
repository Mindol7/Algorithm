#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int string_check = -1;
    while(true){
        stack<char> st;
        getline(cin, s);
        if(s == "."){
            return 0;
        }

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') st.push('(');
            else if(s[i] == '[') st.push('[');
            else if(s[i] == ')'){
                if(st.empty() || st.top() != '('){
                    cout << "no" << '\n';
                    string_check = 1;
                    break;
                }
                else st.pop();
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top() != '['){
                    cout << "no" << '\n';
                    string_check = 1;
                    break;
                }
                else st.pop();
            }
        }
        if(string_check == 1){
            string_check = -1;
            continue;
        }
        if(!st.empty()){
            cout << "no" << '\n';
        }
        else{
            cout << "yes" << '\n';
        }
    }

    return 0;
}