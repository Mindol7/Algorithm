#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

pair<int,int> getPoint(vector<string> &maze, char c, int n, int m){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(maze[i][j] == c) return {i,j};
        }
    }
    return {-1,-1};
}

void BFS(vector<string> &maze, int n, int m){
    queue<pair<int,int>> Q;
    queue<pair<int,int>> fire_Q;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    pair<int,int> jihon = getPoint(maze, 'J', n, m);

    // 불 여러 개 큐에 넣기
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(maze[i][j] == 'F'){
                fire_Q.push({i,j});
            }
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, -1));
    Q.push(jihon);
    vis[jihon.X][jihon.Y] = 0;

    while(!Q.empty()){
        int fireSize = fire_Q.size();
        while(fireSize--){
            auto fire_cur = fire_Q.front();
            fire_Q.pop();

            for(int dir = 0; dir < 4; ++dir){
                int nx = fire_cur.X + dx[dir];
                int ny = fire_cur.Y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;

                maze[nx][ny] = 'F';
                fire_Q.push({nx,ny});
            }
        }

        int jihunSize = Q.size();
        while(jihunSize--){
            auto cur = Q.front();
            Q.pop();

            if(cur.X == 0 || cur.X == n-1 || cur.Y == 0 || cur.Y == m-1){
                cout << vis[cur.X][cur.Y] + 1 << "\n";
                return;
            }

            for(int dir = 0; dir < 4; ++dir){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] != -1) continue;
                if(maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;

                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> maze(n);

    for(int i = 0; i < n; ++i){
        cin >> maze[i];
    }

    BFS(maze, n, m);
    return 0;
}
