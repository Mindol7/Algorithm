#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

pair<int,int> findPoint(const vector<string>& maps, char target) {
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            if(maps[i][j] == target) return {i, j};
        }
    }
    return {-1, -1};
}

int bfs(const vector<string>& maps, char start, char end) {
    queue<pair<int,int>> q;
    int dir_x[4] = {0, 0, -1, 1}; // 상하좌우
    int dir_y[4] = {-1, 1, 0, 0};

    auto s = findPoint(maps, start);
    auto t = findPoint(maps, end);

    if(s.first == -1 || t.first == -1) return -1;

    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), -1)); // 방문여부 체크

    q.push(s);
    dist[s.first][s.second] = 0;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == t.first && y == t.second) return dist[x][y];

        for(int i = 0; i < 4; i++){
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];

            if (nx <= -1 || nx >= maps.size() || ny <= -1 || ny >= maps[0].size()) continue;
            if (maps[nx][ny] == 'X') continue;
            dist[nx][ny] += 1;

            q.push({nx,ny});
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    int a = bfs(maps, 'S', 'L');
    if(a == -1) return -1;

    int b = bfs(maps, 'L', 'E');
    if(b == -1) return -1;

    return a + b;
}

int main() {
    vector<string> maps1 = {
        "SOOOL",
        "XXXXO",
        "OOOOO",
        "OXXXX",
        "OOOOE"
    };
    cout << solution(maps1) << endl; // 16

    vector<string> maps2 = {
        "LOOXS",
        "OOOOX",
        "OOOOO",
        "OOOOO",
        "EOOOO"
    };
    cout << solution(maps2) << endl; // -1

    return 0;
}