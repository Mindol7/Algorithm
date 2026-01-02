#include <bits/stdc++.h>
using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

/** 트리 순회 방법 
 ** 순회는 부모 기준으로 이름이 붙여진다.
 1. 전위 순회: 부모 -> 왼쪽 -> 오른쪽
 2. 중위 순회: 왼쪽 -> 부모 -> 오른쪽
 3. 후위 순회: 왼쪽 -> 오른쪽 -> 부모
*/

void preorder(int cur){
    cout << cur << ' ';
    if(lc[cur] != 0) preorder(lc[cur]);
    if(rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur){
    if(lc[cur] != 0) inorder(lc[cur]);
    cout << cur << ' ';
    if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur){
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
    cout << cur << ' ';
}