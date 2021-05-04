#include <iostream>
using namespace std;

class List_Node {
private:
	int data;
	List_Node* next;
	List_Node* prev;
public:
	List_Node() : data(NULL), next(nullptr), prev(nullptr) {}
	List_Node(int _data) : data(_data), next(nullptr), prev(nullptr) {}
	int getData() const {
		return data;
	}
	List_Node* getNext() const {
		return next;
	}
	List_Node* getPrev() const {
		return prev;
	}
	void setData(int _data) {
		this->data = _data;
	}
	void setNext(List_Node* next) {
		this->next = next;
	}
	void setPrev(List_Node* prev) {
		this->prev = prev;
	}
};
class Deque {
private:
	size_t size;
	List_Node* front;
	List_Node* rear;
public:
	Deque() : size(0), front(nullptr), rear(nullptr) {}
	size_t getSize() {
		return size;
	}
	bool isEmpty() {
		return size ? false : true;
	}
	void push_front(int data) {
		List_Node* node = new List_Node(data);
		if (isEmpty()) {
			front = rear = node;
			node->setPrev(nullptr);
		}
		else {
			node->setNext(front);
			front->setPrev(node);
			front = node;
		}
		size++;
	}
	void push_back(int data) {
		List_Node* node = new List_Node(data);
		if (isEmpty()) {
			front = rear = node;
			node->setPrev(nullptr);
		}
		else {
			rear->setNext(node);
			node->setPrev(rear);
			rear = node;
		}
		size++;
	}
	int pop_front() {
		if (isEmpty()) {
			return -1;
		}
		List_Node* node = front;
		int temp = front->getData();
		if (front->getNext() != nullptr) {
			front = front->getNext();
		}
		front->setPrev(nullptr);
		size--;
		if (isEmpty()) {
			front = rear = nullptr;
		}
		delete node;
		return temp;
	}
	int pop_back() {
		if (isEmpty()) {
			return -1;
		}
		List_Node* node = rear;
		int temp = rear->getData();
		if (rear->getPrev() != nullptr) {
			rear = rear->getPrev();
		}
		rear->setNext(nullptr);
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
	void ShowInfo() {
		List_Node* node = front;
		while (node->getNext() != nullptr) {
			cout << node->getData() << " -> ";
			node = node->getNext();
		}
		cout << node->getData() << endl;
	}
};

int main() {
	Deque q;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		string str;
		int n;
		cin >> str;
		if (str == "push_front") {
			cin >> n;
			q.push_front(n);
		}
		if (str == "push_back") {
			cin >> n;
			q.push_back(n);
		}
		if (str == "pop_front") {
			cout << q.pop_front() << endl;
		}
		if (str == "pop_back") {
			cout << q.pop_back() << endl;
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
		if (str == "show") {
			q.ShowInfo();
		}
	}
}