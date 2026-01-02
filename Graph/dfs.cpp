#include <iostream>
#include <vector>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

/** DFS 구현 준비물
 * 1. vector 3가지: adjs, order, vertices (이웃노드, 방문순서, 그래프)
 * 2. idx, chr, addEdge: 인덱스 변환 및 이웃노드 추가
 * 3. DFS, DFS_VISIT: 두개 다 출발점만 매개변수로 받음
 */


struct Vertex{
    int color = WHITE;
};

vector<vector<int>> adj;
vector<Vertex> vertices;
vector<char> order;

int idx(char c){ // A가 0번째니까.
    return c - 'A';
}

char chr(int i){ // ascii 기준에서 'A'에서 얼마나 떨어져있나
    return (char)('A' + i);
}

void addEdge(char u, char v){
    adj[idx(u)].push_back(idx(v));
}

void DFS_VISIT(int u){
    vertices[u].color = GRAY;
    order.push_back(chr(u)); // 방문 순서 기록

    for (int v: adj[u]) {
        if (vertices[v].color == WHITE) {
            DFS_VISIT(v);
        }
    }
    vertices[u].color = BLACK;
}

void DFS(char start) {
    int s = idx(start);
    if(vertices[s].color == WHITE) DFS_VISIT(s);
}

vector<char> solution(char start){
    order.clear();
    DFS(start);
    return order;
}

int main(){
    int N = 5;
    adj.assign(N, {});
    vertices.assign(N, {});

    addEdge('A','B');
    addEdge('B','C');
    addEdge('C','D');
    addEdge('D','E');

    vector<char> res = solution('A');

    for(int i = 0; i < res.size(); i++){
        cout << res[i];
        if (i != res.size() - 1) cout << "->";
    }
    cout << endl;
    return 0;
}