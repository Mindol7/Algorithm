#include <bits/stdc++.h>
using namespace std;

void preorder(char cur, const char lc[], const char rc[]){
    cout << cur;
    int idx = cur - 'A' + 1;
    if(lc[idx] != '.') preorder(lc[idx], lc, rc);
    if(rc[idx] != '.') preorder(rc[idx], lc, rc);
}

void inorder(char cur, const char lc[], const char rc[]){
    int idx = cur - 'A' + 1;
    if(lc[idx] != '.') inorder(lc[idx], lc, rc);
    cout << cur;
    if(rc[idx] != '.') inorder(rc[idx], lc, rc);
}

void postorder(char cur, const char lc[], const char rc[]){
    int idx = cur - 'A' + 1;
    if(lc[idx] != '.') postorder(lc[idx], lc, rc);
    if(rc[idx] != '.') postorder(rc[idx], lc, rc);
    cout << cur;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; // Binary Tree의 Node 수
    cin >> N;
    char lc[N+1]; lc[0] = '.';
    char rc[N+1]; rc[0] = '.';
    char root, l, r;
    
    for(int i=1; i <= N; ++i){
        cin >> root >> l >> r;
        if(root != '.'){    
            lc[(root-'A'+1)] = l;
            rc[(root-'A'+1)] = r;
        }
    }

    preorder('A', lc, rc); cout << '\n';
    inorder('A', lc, rc); cout << '\n';
    postorder('A', lc, rc);

    return 0;
}