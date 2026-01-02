#include <bits/stdc++.h>

using namespace std;

int graph(int V, int E){
    int u, v;
    vector<int> adj[V+1];
    int count = 0;

    for(int i = 0; i < E; i++){
        cin >> u >> v;
        if(u == v) return -1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> Q;
    vector<int> vis(V+1, 0);

    for(int i = 1; i <= V; i++){
        if(vis[i] != 0) continue;
        Q.push(i);
        count++;
        vis[i] = 1;

        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();

            for(auto nxt : adj[cur]){
                if(vis[nxt] != 0) continue;
                vis[nxt] = 1;
                Q.push(nxt);
            }
        }
    }
    return count;
}

int main(){
    int V, E; // V, E
    cin >> V >> E;
    cout << graph(V, E) << '\n';
    return 0;
}