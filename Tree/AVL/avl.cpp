#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* left, * right;
        int height;
        Node(int key) : val(key), left(nullptr), right(nullptr), height(1) {}
};

class AVL{
    private:
        Node* root;

        int getHeight(Node* node){
            if(!node){
                return -1;
            }
            return node->height;
        }

        Node* leftRotation(Node* node){
            Node* tmp = node->right;
            node->right = tmp->left;
            tmp->left = node;
            tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            return tmp;
        }

        Node* rightRotation(Node* node){
            Node* tmp = node->left;
            node->left = tmp->right;
            tmp->right = node;
            tmp->height = 1 + max(getHeight(tmp->left), getHeight(tmp->right));
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            return tmp;
        }
    
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
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            int balance = getHeight(node->left) - getHeight(node->right);

            if(balance > 1){
                // LR Case
                if(key > node->left->val){
                    node->left = leftRotation(node->left);
                    return rightRotation(node);
                }
                // LL Case
                else{
                    return rightRotation(node);
                }
            }
            else if(balance < -1){
                // RL Case
                if(key < node->right->val){
                    node->right = rightRotation(node->right);
                    return leftRotation(node);
                }
                // RR Case
                else{
                    return leftRotation(node);
                }
            }
            return node;
        }

        bool searchNode(Node* node, int key){
            if(!node){
                return false;
            }
            if(node->val == key){
                return true;
            }
            return key < node->val ? searchNode(node->left, key) : searchNode(node->right, key);
        }

        Node* findMin(Node* node){
            while(node && node->left){
                node = node->left;
            }
            return node;
        }

        Node* deleteNode(Node* node, int key){
            if(!node){
                return nullptr;
            }
            if(key < node->val){
                node->left = deleteNode(node->left, key);
            }
            else if(key > node->val){
                node->right = deleteNode(node->right, key);
            }
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
                else{
                    Node* successor = findMin(node->right);
                    node->val = successor->val;
                    node->right = deleteNode(node->right, successor->val);
                }
            }

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            int balance = getHeight(node->left) - getHeight(node->right);

            if(balance > 1){
                // LR Case
                if(key < node->left->val){
                    node->left = rightRotation(node->left);
                    return leftRotation(node);
                }
                // LL Case
                else{
                    return leftRotation(node);
                }
            }
            else if(balance < -1){
                // RL Case
                if(key > node->right->val){
                    node->right = leftRotation(node->right);
                    return rightRotation(node);
                }
                // RR Case
                else{
                    return rightRotation(node);
                }
            }

            return node;
        }

        // 순회
        void preOrder(Node* node){
            if(!node){
                return;
            }
            cout << node->val << " ";
            preOrder(node->left);
            preOrder(node->right);
        }

        void inOrder(Node* node){
            if(!node){
                return;
            }
            inOrder(node->left);
            cout << node->val << " ";
            inOrder(node->right);
        }

        void postOrder(Node* node){
            if(!node){
                return;
            }
            postOrder(node->left);
            postOrder(node->right);
            cout << node->val << " ";
        }

    public:
        AVL() : root(nullptr) {}
        void insert(int key){
            root = insertNode(root, key);
        }
        bool search(int key){
            return searchNode(root, key);
        }
        void remove(int key){
            root = deleteNode(root, key);
        }
};

int main(){

    return 0;
}