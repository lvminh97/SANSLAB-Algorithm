#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

void heapify(int* a, int i, int n){
	int L = 2 * i + 1;
	int R = 2 * i + 2;
	int maxId = i;
	if(L < n && a[L] > a[maxId]) maxId = L;
	if(R < n && a[R] > a[maxId]) maxId = R;
	if(maxId != i){
		swap(a[maxId], a[i]);
		heapify(a, maxId, n);
	}
}

void buildHeap(int* a, int n){
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify(a, i, n);
	}
}

void HeapSort(int* a, int n){
	buildHeap(a, n);
	for(int i = n - 1; i > 0; i--){
		swap(a[0], a[i]);
		heapify(a, 0, i - 1);
	}
}

void output(int* a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	int a[] = {1, 5, 7, 2, 4, 3, 0, 9, 8, 11, 6, 3, 2, 7, 9, 3, 1, 6, 8, 3};
	int n = sizeof(a) / sizeof(int);
	HeapSort(a, n);
	output(a, n);
}
