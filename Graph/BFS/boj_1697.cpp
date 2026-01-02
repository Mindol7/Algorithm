#include <bits/stdc++.h>

using namespace std;

int BFS(int start, int target){
    int dy[2] = {1,-1};
    queue<int> Q;
    vector<int> vis;
    int n;
    if(start > target) {
        n = 100001;
        vis.assign(n, -1);
    }
    else{
        n = 100001;
        vis.assign(n, -1);
    } 

    Q.push(start);
    vis[start] = 0;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        if(cur == target) return vis[cur];

        for(int dir = 0; dir < 2; ++dir){
            int ny = cur + dy[dir];
            if(ny < 0 || ny >= n) continue;
            if(vis[ny] != -1) continue;
            Q.push(ny);
            vis[ny] = vis[cur] + 1;
        }

        int ny = cur*2;
        if(ny < 0 || ny >= n) continue;
        if(vis[ny] != -1) continue;
        Q.push(ny);
        vis[ny] = vis[cur] + 1;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b; // 5, 17
    cout << BFS(a,b) << '\n'; // 4

    return 0;
}