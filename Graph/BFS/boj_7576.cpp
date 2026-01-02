#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int BFS(vector<vector<int>> &box, int n, int m){
    int zero_count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(box[i][j] == 0) zero_count++;
        }
    }

    if(zero_count == 0) return 0; // 안익은 토마토 없음

    queue<pair<int,int>> Q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, -1));
    vector<vector<int>> day(n, vector<int>(m, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(box[i][j] == 1 && vis[i][j] == -1){
                Q.push({i,j});
                vis[i][j] = 0;
            }
        }
    }

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(box[nx][ny] == -1) continue;       // 빈 칸
            if(vis[nx][ny] != -1) continue;       // 이미 방문

            if(box[nx][ny] == 0){
                box[nx][ny] = 1;                  // 익게 만들기
                vis[nx][ny] = 0;                  // 방문 표시
                day[nx][ny] = day[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(box[i][j] == 0) return -1;
        }
    }

    int result = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            result = max(result, day[i][j]);
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> box[i][j];
        }
    }

    cout << BFS(box, n, m) << '\n';
    return 0;
}
