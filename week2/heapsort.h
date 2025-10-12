#include <iostream>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	for (int i = n / 2 - 1; i >= 0; i--) {
		if (left < n && arr[left] > arr[largest]) {
			left = largest;
		}
		if (right < n && arr[right] > arr[largest]) {
			right = largest;
		}
		if (arr[i] != largest) {
			swap(arr[i], arr[largest]);
			heapify(arr, n, largest);
		}
 	}
	
}

void heapsort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

