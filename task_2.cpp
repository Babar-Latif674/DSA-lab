#include<iostream>
using namespace std;

int findMaximum(int arr[], int num){
	int maxValue = arr[0];
	for (int i = 1; i < num; i++){
		if (arr[i] > maxValue){
			maxValue = arr[i];
		}
	}
	return maxValue;
}
int main(){
	int arr[] = {12, 15, 17, 46, 64};
	int num = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Max value: " << findMaximum(arr, num) << endl;
}
