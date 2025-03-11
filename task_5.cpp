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
		void display_first(){
			if(head) cout << "1st Node: " << head->data << endl;
		}
		void display_last(){
			Node* temp = head;
			while(temp && temp->next !=NULL){
				temp = temp->next;
			}
			if(head) cout << "Last Node: " << temp->data << endl;
		}
		void display_nth(int n){
			Node* temp = head;
			int count = 1;
			while(temp !=NULL){
				if(count == n){
					cout << "nth Node: " << temp->data << endl;
				}
				temp = temp->next;
				count++;
			}
			cout << "invalid position " << endl;
		}
		void display_center(){
			Node *slow = head, *fast = head;
			while (fast != NULL && fast->next != NULL){
				slow = slow->next;
				fast = fast->next->next;
			}
			if(slow) cout << "middle node: " << slow->data << endl;
		}
};
int main(){
	LinkedList list1;
	for(int i = 1; i <= 5; i++) {
	list1.insert_at_last(i * 10);
    }
	list1.display_first();
	list1.display_last();
	list1.display_nth(4);
	list1.display_center();
}
		
		
		
		
