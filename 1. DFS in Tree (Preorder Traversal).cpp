#include <iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int val){
    TreeNode* node = new TreeNode;
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void DFS_Tree(TreeNode* root){
    if (root == NULL) return;
    cout << root->data << " ";
    DFS_Tree(root->left);
    DFS_Tree(root->right);
}

int main(){
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "DFS in Tree (Preorder): ";
    DFS_Tree(root);
    return 0;
}

