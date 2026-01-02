#include <iostream>
#include <vector>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

/**
 * 준비물 준비
 * 1. adj, vertices, order
 * 2. 구조체
 */

struct Vertex{
    int color = WHITE;
};

vector<char> order;
vector<vector<int>> adj;
vector<Vertex> vertices;

/**
 * 함수 준비
 * 1. idx, chr, addEdge
 */

int idx(char c){
    return c - 'A';
}

char chr(int i){
    return i + 'A';
}

void addEdge(char u, char v){
    adj[idx(u)].push_back(idx(v));
}

/**
 * 알고리즘 준비
 * 1. DFS, DFS_VISIT
 */

void DFS_VISIT(char s){
    order.push_back(s);
    vertices[idx(s)].color = GRAY;

    for(int v : adj[idx(s)]){
        if(vertices[v].color == WHITE){
            DFS_VISIT(chr(v));
        }
    }

    vertices[idx(s)].color = BLACK;
    
}

void DFS(char s){
    order.clear();
    if(vertices[idx(s)].color == WHITE) DFS_VISIT(s);
}