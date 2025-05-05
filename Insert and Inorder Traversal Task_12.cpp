#include <iostream>
#include <algorithm>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) : data(val), left(NULL), right(NULL){}
};

class BST{
public:
    BSTNode* root;

    BST(){
        root = NULL;
    }

    BSTNode* insert(BSTNode* node, int value){
        if (node == NULL) return new BSTNode(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    void inorder(BSTNode* node){
        if (node) {
            inorder(node->left);
            cout << node->data << "  ";
            inorder(node->right);
        }
    }
};
struct AVLNode{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : data(val), left(NULL), right(NULL), height(1){}
};

class AVL{
public:
    AVLNode* root;

    AVL(){
        root = NULL;
    }

    int getHeight(AVLNode* node){
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node){
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* y){
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x){
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, int key){
        if (!node) return new AVLNode(key);

        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);
        
        if (balance > 1 && key < node->left->data) return rotateRight(node);
        if (balance < -1 && key > node->right->data) return rotateLeft(node);
        if (balance > 1 && key > node->left->data){
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && key < node->right->data){
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void inorder(AVLNode* node){
        if (node){
            inorder(node->left);
            cout << node->data << "  ";
            inorder(node->right);
        }
    }
};
int main(){
    BST bst;
    bst.root = bst.insert(bst.root, 50);
    bst.insert(bst.root, 30);
    bst.insert(bst.root, 70);
    bst.insert(bst.root, 20);
    bst.insert(bst.root, 40);

    cout << "BST Inorder: ";
    bst.inorder(bst.root);
    cout << "\n\n";

    AVL avl;
    avl.root = avl.insert(avl.root, 50);
    avl.insert(avl.root, 30);
    avl.insert(avl.root, 70);
    avl.insert(avl.root, 20);
    avl.insert(avl.root, 40);

    cout << "AVL Inorder: ";
    avl.inorder(avl.root);
    cout << "\n\n";

    return 0;
}


