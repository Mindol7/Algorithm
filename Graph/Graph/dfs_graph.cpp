#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool vis[10];

void dfs(){
    stack<int> s;
    s.push(1);

    vis[1] = true;

    while(!s.empty()){
        int cur = s.top();
        s.pop();

        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            s.push(nxt);
            vis[nxt] = true;
        }
    }
}

int main(){
    dfs();

    return 0;
}