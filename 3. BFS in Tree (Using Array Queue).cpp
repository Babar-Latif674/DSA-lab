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
TreeNode* queue[100];
int front = 0, rear = 0;

void enqueue(TreeNode* node){
    queue[rear++] = node;
}

TreeNode* dequeue(){
    return queue[front++];
}

bool isEmpty(){
    return front == rear;
}

void BFS_Tree(TreeNode* root){
    if (!root) return;
    enqueue(root);

    while (!isEmpty()){
        TreeNode* current = dequeue();
        cout << current->data << " ";

        if (current->left) enqueue(current->left);
        if (current->right) enqueue(current->right);
    }
}

int main(){
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    cout << "BFS in Tree: ";
    BFS_Tree(root);
    return 0;
}

