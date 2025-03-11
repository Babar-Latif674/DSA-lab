#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data = val;
			next =  NULL;
		}
};
class LinkedList {
	public:
		Node* head;
		LinkedList(){
			head =  NULL;
		}
		void insert_at_position(int val, int pos){
			Node* newNode = new Node(val);
			if(pos == 1){
				newNode->next = head;
				head = newNode;
			}
			Node* temp = head;
			for(int i = 1;temp !=  NULL && i < pos - 1; i++){
				temp = temp->next;
			}
			if(temp ==  NULL){
				cout << "Invalid Possition! " << endl;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
		void display(){
			Node* temp = head;
			while (temp !=  NULL){
				cout << temp->data  << endl;
				temp = temp->next;
			}
			cout << "Null"  << endl;
		}
};
int main(){
	LinkedList list1;
	list1.insert_at_position(10, 4);
	list1.insert_at_position(20, 6);
	list1.insert_at_position(15, 2);
	
	cout << "After insertion: " ;
	list1.display();
}
			
			


