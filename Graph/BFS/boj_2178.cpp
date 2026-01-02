#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

int BFS(const vector<vector<int>> &maze, int n, int m){
    vector<vector<int>> vis(n, vector<int>(m,0));
    queue<pair<int,int>> Q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    pair<int,int> str = make_pair(0,0);
    pair<int,int> tar = make_pair(n-1,m-1);
    Q.push(str);
    vis[str.X][str.Y] += 1;

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maze[nx][ny] == 0) continue;
            if(vis[nx][ny] != 0) continue;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    return vis[tar.X][tar.Y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));

    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        for(int j = 0; j < m; ++j){
            maze[i][j] = a[j] - '0';
        }
    }

    cout << BFS(maze, n, m) << '\n';

    return 0;
}