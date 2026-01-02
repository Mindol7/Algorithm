#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> painting(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> painting[i][j];
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int painting_num = 0;
    int max_painting_width = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int,int>> Q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(painting[i][j] == 0 || vis[i][j] == 1) continue;

            painting_num++;
            int tmp_width = 0;

            Q.push({i, j});
            vis[i][j] = 1;

            while(!Q.empty()){
                auto cur = Q.front();
                Q.pop();
                tmp_width++;

                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(painting[nx][ny] == 0) continue;
                    if(vis[nx][ny] == 1) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }

            max_painting_width = max(max_painting_width, tmp_width);
        }
    }

    cout << painting_num << "\n" << max_painting_width << "\n";
    return 0;
}
