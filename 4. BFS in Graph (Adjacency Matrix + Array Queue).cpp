#include <iostream>
using namespace std;

const int SIZE = 5;
int adj[SIZE][SIZE] ={
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,1,1},
    {0,1,1,0,1},
    {0,0,1,1,0}
};

bool visited[SIZE] ={false};
int queue[100];
int front = 0, rear = 0;

void enqueue(int val){
    queue[rear++] = val;
}
int dequeue(){
    return queue[front++];
}
bool isEmpty(){
    return front == rear;
}

void BFS_Graph(int start){
    enqueue(start);
    visited[start] = true;

    while (!isEmpty()){
        int node = dequeue();
        cout << node << " ";

        for (int i = 0; i < SIZE; i++){
            if (adj[node][i] && !visited[i]){
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main(){
    cout << "BFS in Graph: ";
    BFS_Graph(0);
    return 0;
}

