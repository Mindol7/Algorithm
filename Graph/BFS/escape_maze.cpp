#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

pair<int,int> findPosition(vector<string>maps, char t){
    for(int i = 0; i < maps.size(); ++i){
        for(int j = 0; j < maps[0].size(); ++j){
            if(maps[i][j] == t) return {i,j};
        }
    }
    return {-1,-1};
}

int BFS(vector<string> maps, char s, char e){
    pair<int, int> str, cur, tar;
    int n = maps.size(); int m = maps[0].size();
    queue<pair<int, int>> Q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> visitied(n, vector<int>(m,-1));
    str = findPosition(maps, s);
    tar = findPosition(maps, e);
    if(str.X == -1 || str.Y == -1) return -1;
    
    Q.push({str.X, str.Y});
    visitied[str.X][str.Y] = 0; // 방문함
    
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        if(cur == tar) return visitied[cur.X][cur.Y];
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] == 'X') continue;
            if(visitied[nx][ny] != -1) continue; // 중복 방문 방지
            visitied[nx][ny] =  visitied[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int a = BFS(maps, 'S', 'L');
    cout << "A: " << a << endl;
    if(a == -1) return -1;
    int b = BFS(maps, 'L', 'E');
    if(b == -1) return -1;
    cout << "B: " << b << endl;
    return a+b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> maps = {
        "SOOOL",
        "XXXXO",
        "OOOOO",
        "OXXXX",
        "OOOOE",
    };

    cout << solution(maps) << endl; // 16

    maps.clear();
    maps = {
        "LOOXS",
        "OOOOX",
        "OOOOO",
        "OOOOO",
        "EOOOO"
    };

    cout << solution(maps) << endl;

    return 0;
}