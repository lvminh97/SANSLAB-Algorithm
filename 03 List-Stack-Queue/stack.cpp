#include <iostream>
using namespace std;

template <class T>
class Stack {
	private:
		int n;
		T *data;
		int top;
	public:
		Stack(int n = 64): top(-1), n(n), data(new T[n]) {}

		bool isEmpty() {
			return top == -1;
		}
		bool isFull() {
			return top == n - 1;
		}
		
		int size(){
			return top + 1;
		}
		
		bool push(T v) {
			if(isFull()) return false;
			top++;
			data[top] = v;
			return true;
		}
		T pop(){
			if(isEmpty()) return NULL;
			T v = data[top];
			top--;
			return v;
		}
};

int main() {
	// Vi du su dung Stack
	Stack<char> s(128);
	char str[100];
	cin >> str;
	bool flag = true; // ket qua kiem tra
	for(int i = 0; str[i] != 0; i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			s.push(str[i]);
		}
		else{
			if(s.isEmpty()){
				flag = false;
				break;
			}
			else{
				char tmp = s.pop();
				if(str[i] == ')' && tmp != '('
				|| str[i] == ']' && tmp != '['
				|| str[i] == '}' && tmp != '{'){
					flag = false;
					break;
				}
			}
		}
	}
	if(!s.isEmpty()) flag = false;
	if(flag) cout << "Hop le";
	else cout << "Khong hop le";
}
