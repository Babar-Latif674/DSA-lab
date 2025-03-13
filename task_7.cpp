#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int val){
			data = val; prev = NULL;
		}
};
class DoubliLinkedList{
	public:
		Node* head;
		DoubliLinkedList(){
			head = NULL;
		}
		void insert_at_start(int val){
			Node* newNode = new Node(val);
        if (head != NULL) {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
		}
		void insert_at_last(int val){
			Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
		}
		void insert_at_nth(int val, int pos){
			Node* newNode = new Node(val);
        if (pos == 1) {
            insert_at_start(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << " Invalid Position! " << endl;
		}
		 newNode->next = temp->next;
        if (temp->next != NULL) temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
		}
	    
        
       void display_forward(){
       	Node* temp = head;
        while (temp != NULL) {
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
	DoubliLinkedList list;
	list.insert_at_start(12);
	list.insert_at_last(15);
	list.insert_at_nth(25, 5);
	
	cout << "Forward list Displaying: " << endl;
	list.display_forward();
	cout << "Reverse list Displaying: " << endl;
	list.display_reverse();
	
}
