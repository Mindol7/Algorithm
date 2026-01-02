#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

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

void BFS(char start){
    int s = idx(start);
    vertices[s].color = GRAY;
    order.push_back(chr(s));
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            vertices[v].color = GRAY;
            order.push_back(chr(v));

            q.push(v);
        }
        vertices[u].color = BLACK;
    }
}

int main(){
    int n = 5;
    adj.assign(n, {});
    vertices.assign(n, {});
    addEdge('A','B');
    addEdge('B','C');
    addEdge('C','D');
    addEdge('D','E');
    
    BFS('A');
    
    for(char& i : order){
        cout << i << " -> ";
    }
    cout<<endl;
    return 0;
}