#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

int partitionSort(int* a, int L, int R, int id){
	int pivot = a[id];
	int count = 0;
	swap(a[id], a[R]);
	for(int i = L; i <= R; i++){
		if(a[i] < pivot){
			swap(a[i], a[L + count]);
			count++;
		}
	}
	swap(a[R], a[L + count]);
	return L + count;
}

void QuickSort(int* a, int L, int R){
	if(L < R){
		int id = (L + R) / 2;
		id = partitionSort(a, L, R, id);
		if(id > L) QuickSort(a, L, id - 1);
		if(id < R) QuickSort(a, id + 1, R);
	}
}

void output(int* a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

int main(){
	int n = 9;
	int a[] = {1, 5, 7, 2, 4, 3, 0, 9, 8};
	QuickSort(a, 0, n - 1);
	output(a, n);
}
