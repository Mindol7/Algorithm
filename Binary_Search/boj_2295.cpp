#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; ++i){
        cin >> v[i];
    }
    vector<int> v2;

    sort(v.begin(), v.end());

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            v2.push_back(v[i] + v[j]);
        }
    }

    int max_val = 0;
    sort(v2.begin(), v2.end());
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            int tar = v[j] - v[i];
            if(binary_search(v2.begin(), v2.end(), tar)){
                tar = v2[lower_bound(v2.begin(), v2.end(), tar) - v2.begin()] + v[i];
                if(tar > max_val) max_val = tar;
            }
        }
    }

    cout << max_val;

    return 0;
}