#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int val){
			data = val;
			next = NULL;
		
		}
};
class circular_linked_list{
	public:
		Node* head;
		circular_linked_list(){
			head = NULL;
		}
		void insert_at_start(int val){
			Node* newNode = new Node(val);
			if(head == NULL){
				head = newNode;
				head->next = head;
			}
			Node* temp = head;
			while(temp->next != head){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
			head = newNode;
		}
		void insert_at_last(int val){
		Node* newNode = new Node(val);
			if(head == NULL){
				head = newNode;
				head->next = head;
			}
			Node* temp = head;
			while(temp->next != head){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = head;
		}
		void insert_at_nth(int val, int pos){
		if(pos == 1){
		insert_at_start(val);	
		}	
		Node* newNode = new Node(val);
		Node* temp = head;
		for(int i = 1; i < pos - 1 && temp->next != head; i++){
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
		}
		void insert_at_center(int val){
			if (head == NULL){
			insert_at_start(val);	
			}
			int count = 0;
			Node* temp = head;
			do{
				count++;
				temp = temp->next;
			}while (temp != head);
			int mid = count / 2 + 1;
			insert_at_nth(val, mid);
		}
		void display(){
			if (head == NULL){
			cout << "Empty List" << endl;	
			}
			Node* temp = head;
			do{
				cout << temp->data << "  ";
				temp = temp->next;
			}while(temp != head);
			cout << "Towards back to head " << endl;
		}
		void display_reverse(Node* current, Node* stop){
			if(current->next != stop){
				display_reverse(current->next, stop);
			}
			cout << current->data << " ";
		}
		void reverse_display(){
			if(head == NULL){
				cout << "Empty List" << endl;
			}
			display_reverse(head, head);
			cout << "Back to head" << endl;
		}
};
int main(){
	circular_linked_list cList;
	cList.insert_at_last(7);
	cList.insert_at_last(9);
	cList.insert_at_start(6);
	cList.insert_at_nth(12, 3);
	cList.insert_at_center(15);
	
	cout << "Circular Linked List: " << endl;
	cList.display();
	cout << "Reverse order: " << endl;
	cList.reverse_display();
}







