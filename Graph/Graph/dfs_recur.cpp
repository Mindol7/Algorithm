#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];

bool vis[10];


// stack이 없음

void dfs(int cur){
    vis[cur] = true;
    for(auto nxt : adj[cur]){
        if(vis[cur]) continue;
        dfs(nxt);
    }
}