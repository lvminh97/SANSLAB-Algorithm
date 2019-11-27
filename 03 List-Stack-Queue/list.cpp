#include <iostream>
using namespace std;

struct Node{
	int value;
	Node* next;
};

class List{
private:
	Node* head;
public:
	List(): head(NULL) {}
	bool isEmpty(){
		return head == NULL;
	}
	void push_back(int v){ // them 1 phan tu vao cuoi danh sach
		if(isEmpty()){ // danh sach chua co gi
			head = new Node;
			head->value = v;
			head->next = NULL;
		}
		else{
			Node* tmp = head;
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			Node* newNode = new Node;
			newNode->value = v;
			newNode->next = NULL;
			tmp->next = newNode;
		}
	}
	int pop_back(){
		if(isEmpty()) return NULL;
		else if(head->next == NULL){ // chi co 1 node
			int value = head->value;
			head = NULL;
			return value;
		}
		else{
			Node* tmp = head;
			while(tmp->next->next != NULL){
				tmp = tmp->next;
			}
			int value = tmp->next->value;
			tmp->next = NULL;
			return value;
		}
	}
	void show(){
		if(isEmpty()) return;
		else{
			Node* tmp = head;
			while(tmp != NULL){
				cout << tmp->value << " ";
				tmp = tmp->next;
			}
			cout << endl;
		}
	}
};

int main(){
	List l;
	l.push_back(2);
	l.push_back(3);
	l.push_back(1);
	l.show();
	cout << l.pop_back() << endl;
	l.show();
	return 0;
}
