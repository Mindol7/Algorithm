#include <bits/stdc++.h>

using namespace std;

int main(){
    int adj_matrix[10][10] = {};
    int v, e;
    cin >> v >> e;
    // Edge 수 만큼 u,v가 있으니까 for e로 함.
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
    }

    int adj_matrix2[10][10] = {};
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix2[u][v] = 1;
        adj_matrix2[v][u] = 1;
    }

    return 0;
}