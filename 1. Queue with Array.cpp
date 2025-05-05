#include <iostream>
#define SIZE 100
using namespace std;

class QueueArray{
    int front, rear;
    int arr[SIZE];

public:
    QueueArray(){
        front = rear = -1;
    }
    void enqueue(int value){
        if (rear == SIZE - 1){
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }
    void dequeue(){
        if (front == -1 || front > rear){
            cout << "Queue Empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }

    void display(){
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

