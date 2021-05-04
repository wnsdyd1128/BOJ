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
class Queue {
private:
	size_t size;
	List_Node* front;
	List_Node* rear;
public:
	Queue() : size(0), front(nullptr), rear(nullptr) {}
	size_t getSize() {
		return size;
	}
	bool isEmpty() {
		return size ? false : true;
	}
	void Push(int data) {
		List_Node* node = new List_Node(data);
		if (isEmpty()) {
			front = rear = node;
		}
		else {
			rear->setNext(node);
			rear = node;
		}
		size++;
	}
	int Pop() {
		if (isEmpty()) {
			return -1;
		}
		List_Node* node = front;
		int temp = front->getData();
		front = front->getNext();
		size--;
		if (isEmpty()) {
			front = rear = nullptr;
		}
		delete node;
		return temp;
	}
	int Front() {
		if (isEmpty()) {
			return -1;
		}
		return front->getData();
	}
	int Rear() {
		if (isEmpty()) {
			return -1;
		}
		return rear->getData();
	}
};

int main() {
	Queue q;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string str;
		int n;
		cin >> str;
		if (str == "push") {
			cin >> n;
			q.Push(n);
		}
		if (str == "pop") {
			cout << q.Pop() << endl;
		}
		if (str == "front") {
			cout << q.Front() << endl;
		}
		if (str == "back") {
			cout << q.Rear() << endl;
		}
		if (str == "size") {
			cout << q.getSize() << endl;
		}
		if (str == "empty") {
			if (q.isEmpty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
}