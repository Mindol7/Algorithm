#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
bool vis[10];

void bfs(){
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();

        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = true;
        }
    }
}

void bfs_no_cyclic(){
    int v = 9;
    queue<int> Q;
    for(int i = 1; i <= v; i++){
        if(vis[i]) continue;
        Q.push(i);
        vis[i] = true;
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();

            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                Q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

int main(){
    bfs();

    return 0;
}