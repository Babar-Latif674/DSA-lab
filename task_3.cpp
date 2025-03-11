#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data = val;
			next = NULL;
		}
};
class LinkedList {
	public:
		Node* head;
		LinkedList(){
			head =  NULL;
		}
		void insert_at_start(int val){
			Node* newNode = new Node(val);
			newNode->next = head;
			head = newNode;
		}
		void insert_at_last(int val){
			Node* newNode = new Node(val);
			if(head ==  NULL){
				head = newNode;
			}
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		void display(){
			Node* temp = head;
			while(temp != NULL){
				cout << temp->data <<endl;
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
}; 
int main(){
	LinkedList list1;
	list1.insert_at_start(10);
	list1.insert_at_last(15);
	list1.insert_at_last(20);
	list1.insert_at_start(5);
	
	cout << "After insertion; " << endl;
	list1.display();	
}







