#include<iostream>
using namespace std;

int main (){
	int n = 10;
	int* myPtr = &n;
	
	cout << "Before modification: " << endl;
	cout << "Num: " << n << ", *myPtr:  " << *myPtr << endl;
	*ptr = 20;
	cout << "Before modification: " << endl;
	cout << "Num: " << n << ", *myPtr:  " << *myPtr << endl;
}
