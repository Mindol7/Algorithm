#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left, * right;

        Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST{
    Node* root;  
    private:
        Node* insertNode(Node* node, int key){
            if(!node){
                return new Node(key);
            }
            if(key < node->val){
                node->left = insertNode(node->left, key);
            }
            else{
                node->right = insertNode(node->right, key);
            }
            return node;
        }

        void postorderNode(Node* node){
            if(node->left != nullptr) postorderNode(node->left);
            if(node->right != nullptr) postorderNode(node->right);
            cout << node->val << '\n'; 
        }

    public:
        BST() : root(nullptr) {}
        void insert(int key){
            root = insertNode(root, key);
        }

        void postorder(){
            postorderNode(root);
        }
};

int main(){
    int x;
    vector<int> preorder;
    while(cin >> x){
        preorder.push_back(x);
    }

    BST bst; // BST* 로 하면 지금 아무것도 안가르키는 포인터일뿐임. (어떤 객체도 안 가르키고 있음)
    // BST* bst = new BST();

    for(int i = 0; i < preorder.size(); i++){
        bst.insert(preorder[i]);
    }
    
    // 최종적으로 호출
    bst.postorder();
    return 0;
}