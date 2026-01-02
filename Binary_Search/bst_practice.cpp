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
            if(key < node->val){
                node->left = insertNode(node->left, key);
            }
            else{
                node->right = insertNode(node->right, key);
            }
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

        Node* findMin(Node* node, int key){
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
                // Case 1
                if(!node->left && !node->right){
                    delete node;
                    return nullptr;
                }

                // Case 2
                if(!node->left){
                    Node* tmp = node->right;
                    delete node;
                    return tmp;
                }
                if(!node->right){
                    Node* tmp = node->left;
                    delete node;
                    return tmp;
                }

                Node* successor = findMin(node->right, key);
                node->val = successor->val;
                node->right = deleteNode(node->right, successor->val);
            }

            return node;
        }
    
    public:
        BST(): root(nullptr) {};
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