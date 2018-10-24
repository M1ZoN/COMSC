/***************************************************************
Problem: Merge Sort
Description: Implementation of the Merge Sort Algorithm
Name: Mukhammadnozim Islamov, Aleksandr Kurakulov
ID: 1668193, 1633897
Date: 10/22/2018
Status: (complete)
****************************************************************/
#include<iostream>
#include<vector>

using namespace std;

const int LAST = 8;

void merge(int arr[], int low, int middle1, int high) {
	bool pushed = true;
	int temparr[LAST + 1];
	for (int i = low, j = middle1+1, k = 0; k <= LAST; k++) {
		if (((i <= middle1) && arr[i] < arr[j]) || (j>high)) {
			temparr[k] = arr[i++];
		}
		else {
			temparr[k] = arr[j++];
		}
	}
	for (int i = low, t = 0; i <= high; i++, t++) {
		arr[i] = temparr[t];
	}
}

void mergeSort(int arr[], int low, int high) {
	if ((high - low) >= 1) {
		int middle1 = (low + high) / 2;

		mergeSort(arr, low, middle1);
		mergeSort(arr, middle1+1, high);


		merge(arr, low, middle1, high);
	}
}


int main() {
	int arr[] = { 7,6,8,1,2,10,4,3,5 };
	mergeSort(arr, 0, LAST);

	for (int i = 0; i <= LAST; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}