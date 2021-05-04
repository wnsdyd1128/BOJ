#include <iostream>
using namespace std;

class List_Node {
private:
	int data;
	List_Node* next;
public:
	List_Node() : data(NULL), next(nullptr) {}
	List_Node(int _data) : data(_data), next(nullptr) {}
	int getData() const {
		return data;
	}
	List_Node* getNext() const {
		return next;
	}
	void setData(int _data) {
		this->data = _data;
	}
	void setNext(List_Node* next) {
		this->next = next;
	}
};

class Stack {
private:
	size_t size;
	List_Node* head;
public:
	Stack() : size(0), head(nullptr) {}
	size_t getSize() {
		return size;
	}
	bool isEmpty() {
		return size ? false : true;
	}
	void Push(int data) {
		List_Node* node = new List_Node(data);
		if (isEmpty()) {
			head = node;
		}
		else {
			node->setNext(head);
			head = node;
		}
		size++;
	}
	int Pop() {
		if (isEmpty()) {
			return -1;
		}
		List_Node* node = head;
		int temp = head->getData();
		head = head->getNext();
		delete node;
		size--;
		return temp;
	}
	int Top() {
		if (isEmpty()) {
			return -1;
		}
		return head->getData();
	}
};

int main() {
	Stack s;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string str;
		int n;
		cin >> str;
		if (str == "push") {
			cin >> n;
			s.Push(n);
		}
		if (str == "pop") {
			cout << s.Pop() << endl;
		}
		if (str == "top") {
			cout << s.Top() << endl;
		}
		if (str == "size") {
			cout << s.getSize() << endl;
		}
		if (str == "empty") {
			if (s.isEmpty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
}