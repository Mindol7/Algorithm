#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

void preorder(int cur){ // 전위 순회
    cout << cur << ' '; // 현재 노드 방문
    if(lc[cur] != 0) preorder(lc[cur]); // 왼쪽 있다면 왼쪽으로 계속 감
    if(rc[cur] != 0) preorder(rc[cur]); // 오른쪽 있다면 오른쪽으로 계속 감
}

void inorder(int cur){
    if(lc[cur] != 0) inorder(lc[cur]);
    cout << cur << ' ';
    if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur){ // 후위 순회
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
    cout << cur << ' ';
}