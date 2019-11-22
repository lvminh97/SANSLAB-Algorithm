#include <iostream>
using namespace std;

int Fibo(int n) {
	if(n < 2) return n;
	return Fibo(n - 2) + Fibo(n - 1);
}

double pow(double x, int n){ // tinh x^n
	if(n == 0) return 1;
	else if(n > 0) return x * pow(x, n - 1);
	else if(n < 0) return 1.0 / pow(x, -n);
}

int Ckn(int k, int n){
	if(k == 0 || k == n) return 1;
	return Ckn(k, n - 1) + Ckn(k - 1, n - 1);
}

int main() {
	int k, n;
	cin >> k >> n;
	cout << Ckn(k, n);
	return 0;
}
