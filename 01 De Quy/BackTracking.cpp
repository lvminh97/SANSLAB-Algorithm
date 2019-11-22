#include <iostream>
using namespace std;

#define MAX 10

int x[MAX]; // chuoi n bit
int k, n;

void solution(){
	for(int i = 0; i < n; i++){
		cout << x[i];
	}
	cout << endl;
}

bool check(int v, int i){
	if(i <= k - 1 || v == 0) return true;
	for(int j = i - 1; j >= i - k; j--){
		if(x[j] == 0) return true;
	}
	return false;
}

void backtrack(int i){
	for(int v = 0; v <= 1; v++){
		if(check(v, i)){
			x[i] = v;
			if(i == n - 1) solution();
			else backtrack(i + 1);	
		}
	}	
}

int main(){
	cin >> n >> k;
	backtrack(0);
}
