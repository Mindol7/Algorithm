#include <bits/stdc++.h>
using namespace std;

int activity_selector(vector<pair<int,int>> &activity, int N){
    int n = N;
    vector<pair<int,int>> A;
    A.push_back({activity[0].first, activity[0].second});
    int i = 0;

    for(int m = 1; m < n; ++m){
        if(activity[m].first >= activity[i].second){
            A.push_back({activity[m].first, activity[m].second});
            i = m;
        }
    }
    return A.size();
}

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<pair<int,int>> activity(N);
    int s, f;
    for(int i = 0; i < N; i++){
        cin >> s >> f;
        activity[i] = make_pair(s,f);
    }
    sort(activity.begin(), activity.end(), cmp);
    cout << activity_selector(activity, N);
    return 0;
}