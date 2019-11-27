// Circular Queue
#include <iostream>
using namespace std;

template <class T>

class Queue {
private:
	T* data;	
	int head, tail;
	int n;
	int count;

public:
	Queue(int n = 64): n(n), data(new T[n]), count(0), head(0), tail(-1) {}
	bool isEmpty() {
		return count == 0;
	}
	bool isFull() {
		return count == n;
	}
	void enqueue(T v) {
		if(isFull()) return;
		tail = (tail + 1) % n;
		data[tail] = v;
		count++;
	}
	T dequeue(){
		if(isEmpty()) return NULL;
		T v = data[head];
		head = (head + 1) % n;
		count--;
		return v;
	}
};

int main(){
	Queue<int> q(3);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	cout << q.dequeue() << " ";
	cout << q.dequeue() << " ";
	q.enqueue(5);
	cout << q.dequeue() << " ";
	cout << q.dequeue() << " ";
}
