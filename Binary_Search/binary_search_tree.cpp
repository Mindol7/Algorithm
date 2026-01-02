#include <bits/stdc++.h>
using namespace std;

/** 이진 탐색 트리
 * 정의: 자식 노드가 2개 이하, Left Child (Parent보다 작음), Right Child (Parent보다 큼)
 * 기능:
 *  1. 탐색(Search): 현재 Node의 Key보다 작으면 왼쪽, 크면 오른쪽 이동
 *  2. 삽입(Insert): Root Node에서 출발해 내려가다 Null 위치에 삽입.
 *  3. 삭제(Delete): 
 *      - 자식노드 0개: 단순 삭제
 *      - 자식노드 1개: 부모 노드가 삭제 노드의 자식을 바라보게함.
 *      - 자식노드 2개: 삭제 노드의 큰 값 중 가장 작은 값을 선택하여 올림
*/

class Node{
public:
    int val;
    Node *left, *right;

    Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST{
    private:
        Node* root;
        
        Node* insertNode(Node* node, int key){
            if(!node){ // 현재 위치에는 node 존재 x (그 자리에 노드 생성해서 돌려줌)
                return new Node(key);
            }
            if(key < node->val){
                node->left = insertNode(node->left, key); // 왼쪽으로 계속 이동하고 끝단에서 달아줌.
            }
            else{
                node->right = insertNode(node->right, key); // 오른쪽으로 계속 이동하고 끝단에서 달아줌.
            }
            return node;
        }

        bool searchNode(Node* node, int key){
            if(!node){ // 못 찾으면 false 반환 (노드 존재하지 않을때 못찾았다 판단.)
                return false;
            }

            if(key == node->val){ // 찾아서 true 반환
                return true;
            }

            return key < node->val ? searchNode(node->left, key) : searchNode(node->right, key); // 이동함.
        }

        Node* findMin(Node* node){ // 오른쪽 서브트리에서 가장 작은 값 찾음
            while(node && node->left){
                node = node->left;
            }
            return node;
        }

        Node* deleteNode(Node* node, int key){
            if(!node) return nullptr; // 삭제할 노드 없다고 판단
            if(key < node->val){
                node->left = deleteNode(node->left, key); // 왼쪽으로 이동
            }
            else if(key > node->val){
                node->right = deleteNode(node->right, key); // 오른쪽으로 이동
            }
            else{ // 삭제할 노드 찾음
                // Case 1: 자식 노드 0개 (단순 삭제 후 null ret)
                if(!node->left && !node->right){
                    delete node;
                    return nullptr;
                }
                // Case 2: 자식 노드 1개 (오른쪽만 존재)
                if(!node->left){ // 삭제 후 오른쪽 연결
                    Node* tmp = node->right;
                    delete node;
                    return tmp;
                }
                if(!node->right){ // 삭제 후 왼쪽 연결
                    Node* tmp = node->left;
                    delete node;
                    return tmp;
                }

                // Case 3: 자식 노드 2개
                Node* successor = findMin(node->right); // 오른쪽 서브 트리에서 최솟값 (올릴 찾음)
                node->val = successor->val; // 올려줄 노드로 값 변경
                node->right = deleteNode(node->right, successor->val); // successor를 올렸으니 node->right에서 successor 삭제.
            }
            return node;
        }

    public:
        BST() : root(nullptr) {}
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