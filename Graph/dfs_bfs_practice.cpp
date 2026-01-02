#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

/**
 * 1. 공통 함수 구현: IDX 변환, Edge 추가
 * 2. vector 및 queue 구현
 */

 struct Vertex{
    int color = WHITE;
 };

 vector<vector<int>> adj;
 vector<char> order;
 vector<Vertex> vertices;
 queue<int> q;

 int idx(char c){
    return c - 'A';
 }

 char chr(int i){
    return (char)(i + 'A');
 }

 void addEdge(char u, char v){
    adj[idx(u)].push_back(idx(v));
 }

 /**
  * DFS 구현
  */

 void DFS_VISIT(char u){
    vertices[idx(u)].color = GRAY;
    order.push_back(u);

    for(int v : adj[idx(u)]){
        if(vertices[v].color == WHITE){
            DFS_VISIT(chr(v));
        }
    }

    vertices[idx(u)].color = BLACK;
 }

 void DFS(char start){
    order.clear();
    if(vertices[idx(start)].color == WHITE){
        DFS_VISIT(start);
    }
  }

  /**
   * BFS 구현
   */

 void BFS(char start){
    order.clear();
    vertices[idx(start)].color = GRAY;
    q.push(idx(start));

    while(!q.empty()){
        int u = q.front();
        q.pop();
        order.push_back(chr(u));
        for(int v : adj[u]){
            if(vertices[v].color == WHITE){
                order.push_back(chr(v));
                vertices[v].color = GRAY;
                q.push(v);
            }
        }
        vertices[u].color = BLACK;
    }

 }