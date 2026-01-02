#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left, * right;
        Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST{
    private:
        Node* root;
        Node* insertNode(Node* node, int key){
            if(!node){
                return new Node(key);
            }
            if(key < node->val) node->left = insertNode(node->left, key);
            else node->right = insertNode(node->right, key);
            return node;
        }

        bool searchNode(Node* node, int key){
            if(!node){
                return false;
            }
            if(key == node->val){
                return true;
            }
            return (key < node->val) ? searchNode(node->left, key) : searchNode(node->right, key);
        }

        Node* findMin(Node* node){
            while(node && node->left){
                node = node->left;
            }
            return node;
        }

        int getMin(Node* node){
            while(node && node->left){
                node = node->left;
            }
            return node->val;
        }

        int getMax(Node* node){
            while(node && node->right){
                node = node->right;
            }
            return node->val;
        }

        Node* deleteNode(Node* node, int key){
            if(!node){
                return nullptr;
            }
            if(key < node->val) node->left = deleteNode(node->left, key);
            else if(key > node->val) node->right = deleteNode(node->right, key);
            else{
                if(!node->left && !node->right){
                    delete node;
                    return nullptr;
                }
                else if(!node->left){
                    Node* tmp = node->right;
                    delete node;
                    return tmp;
                }
                else if(!node->right){
                    Node* tmp = node->left;
                    delete node;
                    return tmp;
                }

                Node* successor = findMin(node->right);
                node->val = successor->val;
                node->right = deleteNode(node->right, successor->val);
            }
            return node;
        }

        bool isEmpty(Node* node){
            if(!node){
                return true;
            }
            else return false;
        }

    public:
        BST() : root(nullptr) {}
        void insert(int key){
            root = insertNode(root, key);
        }
        bool search(int key){
            return searchNode(root, key);
        }
        bool empty(){
            return isEmpty(root);
        }
        bool remove(int key){
            if(isEmpty(root)){
                return false;
            }
            root = deleteNode(root, key);
            return true;
        }
        int min(){
            if(isEmpty(root)){
                return false;
            }
            return getMin(root);
        }
        int max(){
            if(isEmpty(root)){
                return false;
            }
            return getMax(root);
        }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case, n;
    cin >> test_case;
    char ch;
    int val;

    while(test_case-- > 0){
        BST Q;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> ch;
            if(ch == 'I'){
                cin >> val;
                Q.insert(val);
            }
            else if(ch == 'D'){
                cin >> val;
                if(val == 1){ // 최댓값 삭제
                    int q_max = Q.max();
                    Q.remove(q_max);
                }
                else if(val == -1){ // 최솟값 삭제
                    int q_min = Q.min();
                    Q.remove(q_min);
                }
            }
        }
        if(Q.empty()) cout << "EMPTY" << '\n';
        else cout << Q.max() << ' ' << Q.min() << '\n';
    }
    return 0;
}