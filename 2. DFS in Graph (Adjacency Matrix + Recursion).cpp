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

void DFS_Graph(int node){
    cout << node << " ";
    visited[node] = true;
    for (int i = 0; i < SIZE; i++){
        if (adj[node][i] && !visited[i]){
            DFS_Graph(i);
        }
    }
}

int main(){
    cout << "DFS in Graph: ";
    DFS_Graph(0);
    return 0;
}

