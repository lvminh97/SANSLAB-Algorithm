#include <iostream>
using namespace std;

#define MAX 100

double A[MAX][MAX]; // ma tran nho

void init(int k, int n){
	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= n; j++){
			A[i][j] = -1;
		}
	}
}

double Ckn(int k, int n){
	if(A[k][n] == -1){ // chua duoc tinh
		if(k == n || k == 0) A[k][n] = 1;
		else A[k][n] = Ckn(k, n - 1) + Ckn(k - 1, n - 1);
	}
	return A[k][n];
} 

int main(){
	int k, n; 
	cin >> k >> n;
	init(k, n);
	cout << Ckn(k, n);
}
