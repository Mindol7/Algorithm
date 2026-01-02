#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case, n;
    cin >> test_case;
    char ch;
    int val;

    while(test_case-- > 0){
        multiset<int> ms;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> ch;
            if(ch == 'I'){
                cin >> val;
                ms.insert(val);
            }
            else if(ch == 'D'){
                cin >> val;
                if(val == 1){ // 최댓값 삭제
                    if(ms.empty()) continue;
                    else{
                        int max_val = *prev(ms.end());
                        auto it = ms.find(max_val);
                        if(it != ms.end()) ms.erase(it);
                    }
                }
                else if(val == -1){ // 최솟값 삭제
                    if(ms.empty()) continue;
                    else{
                        int min_val = *ms.begin();
                        auto it = ms.find(min_val);
                        if(it != ms.end()) ms.erase(it);
                    }
                }
            }
        }
        if(ms.empty()) cout << "EMPTY" << '\n';
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
    return 0;
}