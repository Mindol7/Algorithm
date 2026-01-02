#include <bits/stdc++.h>

using namespace std;

long long COUNT(vector<long long> &a, int n){
    int cnt = 0, mxcnt = 0;
    long long mxval = (-1) * (1ll << 62) + (-1);

    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i){
        if(i == 0 || a[i-1] == a[i]) cnt++;
        else{
            if(cnt > mxcnt){
                mxcnt = cnt;
                mxval = a[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > mxcnt) mxval = a[n-1];
    return mxval;
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    long long r = COUNT(a, n);
    cout << r << '\n';

    return 0;
}