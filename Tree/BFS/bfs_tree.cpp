#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10];
int p[10]; // parent
int depth[10]; // depth 정보

// vis 대신 parent 정보만 준다.

void bfs(int root){
    queue<int> q;
    q.push(root);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int nxt : adj[cur]){
            if(p[cur] == nxt) continue; // 위를 본거니까 pass
            q.push(nxt);
            p[nxt] = cur; // 부모로 설정
            depth[nxt] = depth[cur] + 1;
        }
    }
}