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
		void merge_lists(LinkedList& list2){
			if (head == NULL){
				head = list2.head;
			}
			Node* temp = head;
			while(temp->data != NULL){
				temp = temp->next;
			}
			temp->next = list2.head;
			list2.head = NULL;
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
	LinkedList list1, list2;
	list1.insert_at_last(10);
	list1.insert_at_last(15);
	list1.insert_at_last(20);
	
	list2.insert_at_last(25);
	list2.insert_at_last(30);
	list2.insert_at_last(35);
	
	cout << "Starting Lists "  << endl;
	list1.display();
	
	cout << "lasts Lists "  << endl;
	list2.display();
	
	list1.merge_lists(list2);
	cout << "merge Lists "  << endl;
	list1.display();
	
}
