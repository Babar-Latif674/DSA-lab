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
		void delete_at_first(){
			if (head == NULL){
				cout << "Empty list!" << endl;
			}
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		void delete_at_last(){
			if (head == NULL){
				cout << "Empty list!" << endl;
			}
			if (head->next == NULL){
				delete head;
				head = NULL;
			}
			Node* temp = head;
			while (temp->next->next != NULL){
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
		}
		void delete_at_Nth(int n){
			if (head == NULL){
				cout << "Empty list!" << endl;
			}
			if (n == 1){
				delete_at_first();
			}
			Node* temp = head;
			for (int i = 1; temp != NULL && i < n-1; i++){
			temp = temp->next;	
			}
			if (temp == NULL || temp->next == NULL){
				cout << "Position is not valid! " << endl;
			}
			Node* toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
		}
		void delete_at_center(){
			if (head == NULL){
				cout << "Empty list!" << endl;
			}
			Node *slow = head, *fast = head, *previous = NULL;
			while (fast !=NULL && fast->next != NULL){
				previous = slow;
				slow = slow->next;
				fast = fast->next->next;
			}
			if (previous == NULL){
				head = slow->next;
			}else {
				previous->next = slow->next;
			}
			delete slow;
		}
		void display(){
			Node* temp = head;
			while (temp != NULL){
				cout << temp->data <<endl;
				 temp = temp->next;
			}
			cout << "NULL" << endl;
		}
};
int main(){
	LinkedList list;
	for (int i = 1; i <= 5; i++){
		list.insert_at_last(i * 10);
	}
	cout << "Started list: ";
	list.display();
	list.delete_at_first();
	cout << "Deleting first node: ";
	list.display();
	
	list.delete_at_last();
	cout << "Deleting Last node: ";
	list.display();
	
	list.delete_at_Nth(2);
	cout << "Deleting nth node: ";
	list.display();
	
	list.delete_at_center();
	cout << "Deleting Center node: ";
	list.display();
	
}
