#include <bits/stdc++.h>

using namespace std;

void DFS(vector<int> adj[], int V, int E, int start_v, vector<int> &vis){
    if(vis[start_v] != 0) {  
        return;
    }
    cout << start_v << " ";
    vis[start_v] = 1;
    int cur = start_v;
    for(auto nxt : adj[cur]){
        if(vis[nxt] != 0) continue;
        DFS(adj, V, E, nxt, vis);
    }
}

void BFS(vector<int> adj[], int V, int E, int start_v, vector<int> vis){
    queue<int> Q;
    vis.assign(V+1, 0);

    Q.push(start_v);
    vis[start_v] = 1;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        cout << cur << " ";

        for(auto nxt : adj[cur]){
            if(vis[nxt] != 0) continue;
            vis[nxt] = 1;
            Q.push(nxt);
        }
    }
}


int main(){
    int V, E, start_v;
    cin >> V >> E >> start_v;
    vector<int> vis(V+1, 0);
    vector<int> adj[V+1];
    int u, v;
    for(int i = 0; i < E; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= V; ++i){
        sort(adj[i].begin(), adj[i].end());
    }
    
    DFS(adj, V, E, start_v, vis);
    cout << '\n';
    BFS(adj, V, E, start_v, vis);
    return 0;
}