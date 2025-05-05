#include <iostream>
using namespace std;

class QueueLL{
    Node *front, *rear;

public:
    QueueLL(){
        front = rear = NULL;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);
        if (!rear){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue(){
        if (!front){
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Dequeued: " << front->data << endl;
        Node* temp = front;
        front = front->next;
        if (!front) rear = NULL;
        delete temp;
    }
    void display(){
        Node* temp = front;
        while (temp){
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

