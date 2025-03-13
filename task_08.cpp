#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int val){
			data = val; 
			next = prev = NULL;
		}
};
class DoubliLinkedList{
	public:
		Node* head;
		DoubliLinkedList(){
			head = NULL;
		}
		void insert_at_last(int val){
			Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
		}
		void merge_lists(DoubliLinkedList& list2){
		if (head == NULL){
			head = list2.head;
		}
		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}	
		temp->next = list2.head;
		if(list2.head != NULL){
			list2.head->prev = temp;
		}
		list2.head = NULL;
		}
		void display_forward(){
			Node* temp = head;
			while(temp != NULL){
			cout << temp->data << "  ";
			temp = temp->next;
			}
			cout << "NULL" << endl;
		}
		void display_reverse(){
	   	 if (head == NULL) ;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            cout << temp->data << "  ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
	   }
};
int main(){
	DoubliLinkedList list1, list2;
	
	list1.insert_at_last(10);
	list1.insert_at_last(15);
	list1.insert_at_last(20);
	
	list2.insert_at_last(12);
	list2.insert_at_last(14);
	list2.insert_at_last(16);
	cout << "First Doubli linked list: ";
	list1.display_forward();
	cout << "Second Doubli linked list: ";
	list2.display_forward();
	
	list1.merge_lists(list2);
	cout << "Merged forward Doubli linked list: ";
	list1.display_forward();
	cout << "Merged reverse Doubli linked list: ";
	list1.display_reverse();
}
		
		
		
		
		
		
