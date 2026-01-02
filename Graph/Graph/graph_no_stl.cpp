#include <bits/stdc++.h>

using namespace std;

int main(){
    // Directed Graph with no STL.
    int edge[10][2];
    int deg[10];
    int* adj[10];
    int idx[10];

    int v, e;
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> edge[i][0] >> edge[i][1];
        deg[edge[i][0]]++;
    }

    for(int i = 1; i <= v; i++){
        adj[i] = new int[deg[i]];
    }

    for(int i = 0; i < e; i++){
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v;
        idx[u]++;
    }

    // Undirected Graph with no STL.
    for(int i = 0; i < e; i++){
        cin >> edge[i][0] >> edge[i][1];
        deg[edge[i][0]]++; deg[edge[i][1]]++;
    }

    for(int i = 1; i <= v; i++){
        adj[i] = new int[deg[i]];
    }

    for(int i = 0; i < e; i++){
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v;
        idx[u]++;
        adj[v][idx[v]] = u;
        idx[v]++;
    }

    return 0;
}