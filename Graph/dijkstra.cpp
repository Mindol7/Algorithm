#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

/** 준비물 준비
 * 1. INF, Edge, Graph
 */

const int INF = numeric_limits<int>::max();

struct Edge{
    int to;
    int weight;
};

struct Graph{
    int v;
    vector<vector<Edge>> adj;

    Graph(int n) : v(n), adj(n){};
    void addEdge(int u, int v, int w){
        adj[u].push_back({v,w});
    }
};

/**
 * 함수 준비
 * 1. ISS(G,s,d,pi), RELAX(u,v,w,d,pi)
 */

void INITIALIZE_SINGLE_SOURCE(const Graph &G, int s, vector<int> &d, vector<int> &pi){
    d.assign(G.v, INF);
    pi.assign(G.v, -1);
    d[s] = 0;
}

bool RELAX(int u, int v, int w, vector<int> &d, vector<int> &pi){
    if(d[u] != INF && d[v] > d[u] + w){
        d[v] = d[u] + w;
        pi[v] = u;
        return true;
    }
    return false;
}

/**
 * 알고리즘 작성
 */

void DIJKSTRA(const Graph &G, int s, vector<int> &d, vector<int> &pi){
    INITIALIZE_SINGLE_SOURCE(G, s, d, pi);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // pair로 저장하고, 컨테이너는 vector로 한다.
    pq.push({0,s});


    while(!pq.empty()){
        auto [d_u, u] = pq.top();
        pq.pop();
        if(d_u != d[u]) continue;

        for(auto &e : G.adj[u]){
            int v = e.to;
            int w = e.weight;

            if(RELAX(u,v,w,d,pi)){
                pq.push({d[v], v});
            }
        }
    }
}

void printPath(int s, int t, const vector<int>& parent){
    if(t==-1) return;
    if(t==s) {
        cout << s;
        return;
    }
    printPath(s, parent[t], parent);
    cout << " -> " << t;
}