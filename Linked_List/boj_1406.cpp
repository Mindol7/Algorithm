#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> list;
    string str;
    cin >> str;
    int n;
    char ins, chr;
    cin >> n;
    for(int i = 0; i < str.size(); ++i){
        list.push_back(str[i]);
    }
    
    auto it = list.end();

    for(int i = 0; i < n; ++i){
        cin >> ins;
        if(ins == 'P'){
            cin >> chr;
            list.insert(it, chr);
        }
        else if(ins == 'L'){
            if(it == list.begin()) continue;
            else it--;
        }
        else if(ins == 'D'){
            if(it == list.end()) continue;
            else it++;
        }
        else if(ins == 'B'){
            if(it == list.begin()) {
                continue;
            }
            else{
                --it;
                it = list.erase(it);
            }
        }
    }
    
    for(auto i : list){
        cout << i;
    }
    return 0;
}