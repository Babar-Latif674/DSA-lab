#include <iostream>
#define SIZE 100
using namespace std;

class StackArray{
    int top;
    int arr[SIZE];

public:
    StackArray(){
        top = -1;
    }
    void push(int value){
        if (top >= SIZE - 1){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }
    void pop(){
        if (top < 0){
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display(){
        if (top < 0 ){
            cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
            cout << arr[i] << "  ";
        cout << endl;
    }
};

