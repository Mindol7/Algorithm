#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int p[], int cur){
    for(int nxt : adj[cur]){
        if(nxt == p[cur]) continue;
        p[nxt] = cur;
        DFS(adj, p, nxt);
    }
}

int main(){
    int V, E;
    cin >> V;
    E = V-1;
    vector<int> adj[V+1];
    int p[V+1];
    int u, v;
    for(int i = 0; i < V+1; i++){
        p[V+1] = 0;
    }
    for(int i = 1; i <= V-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(adj, p, 1);

    for(int i = 2; i <= V; ++i){
        cout << p[i] << '\n';
    }

    return 0;
}