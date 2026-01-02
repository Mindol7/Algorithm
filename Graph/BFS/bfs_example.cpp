#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[502][502] = 
   {{1,1,1,0,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} };

bool visited[502][502];
int n = 7, m = 10; // row, cols 
int dx[4] = {1,0,-1,0}; // 행의 상 하 의미
int dy[4] = {0,1,0,-1}; // 열의 좌 우 의미

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q; // 좌표로 queue에 넣음
    visited[0][0] = 1; // 시작점을 방문했다고 가정
    Q.push({0,0});

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        cout << "(" << cur.X << ", " << cur.Y << ") -> ";

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx > 502 || ny < 0 || ny > 502) continue;
            if(board[nx][ny] == 0) continue;
            if(visited[nx][ny] == 1) continue;
            Q.push({nx,ny});
            visited[nx][ny] = 1;
        }
    }
}