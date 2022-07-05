#include <bits/stdc++.h>
#define endl '\n'
#define INF 1000000000 // 10^9, Floyd-Warshall에선 20억보다 안전
#define MAX_N 26
#define _CRT_SECURE_NO_DEPRECATE
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// index = (index + 1 ) % n;		// index++; if (index >= n) index = 0;
// index = (index + n - 1 ) % n;	// index--; if (index < 0) index = n - 1;

//class Node {
//	char data;
//	Node* parent;
//	Node* left;
//	Node* right;
//public:
//	Node() : data(NULL), parent(nullptr){}
//	Node(char _data) : data(_data), parent(nullptr){}
//	Node(char _data, Node* left, Node* right) : Node(_data) {
//		this->left = left;
//		this->right = right;
//	}
//	void setParent(Node* parent) {
//		this->parent = parent;
//	}
//	void setLeft(Node* left) {
//		this->left = left;
//	}
//	void setRight(Node* right) {
//		this->right = right;
//	}
//	char getData() {
//		return data;
//	}
//	Node* getParent() {
//		return parent;
//	}
//	Node* getLeft() {
//		return left;
//	}
//	Node* getRight() {
//		return right;
//	}
//};
//
//class Tree {
//	Node* root;
//	vector<Node*> nodeList;
//public:
//	Tree(char data) : root(new Node(data)) {
//		nodeList.push_back(root);
//	}
//	Node* getRoot() {
//		return root;
//	}
//	void insert(char parent, char left, char right) {
//		int idx = find(parent);
//		Node* parentNode = nodeList[idx];
//		Node* leftNode = new Node(left);
//		leftNode->setParent(parentNode);
//		nodeList.push_back(leftNode);
//		parentNode->setLeft(leftNode);
//		Node* rightNode = new Node(right);
//		rightNode->setParent(parentNode);
//		nodeList.push_back(rightNode);
//		parentNode->setRight(rightNode);
//	}
//	void preOrder(Node* node) {
//		if (node == nullptr || node->getData() == '.')
//			return;
//		cout << node->getData();
//		preOrder(node->getLeft());
//		preOrder(node->getRight());
//	}
//	void inOrder(Node* node) {
//		if (node == nullptr || node->getData() == '.')
//			return;
//		inOrder(node->getLeft());
//		cout << node->getData();
//		inOrder(node->getRight());
//	}
//	void postOrder(Node* node) {
//		if (node == nullptr || node->getData() == '.')
//			return;
//		postOrder(node->getLeft());
//		postOrder(node->getRight());
//		cout << node->getData();
//	}
//protected:
//	int find(char data) {
//		for(int i = 0; i < nodeList.size(); i++) {
//			if (nodeList[i]->getData() == data)
//				return i;
//		}
//		return -1;
//	}
//};

ii tree[MAX_N + 1];
void preorder(int node) {
	if (!isupper(node + 'A'))
		return;
	cout << (char)(node + 'A');
	preorder(tree[node].first);
	preorder(tree[node].second);
}
void inorder(int node) {
	if (!isupper(node + 'A'))
		return;
	inorder(tree[node].first);
	cout << (char)(node + 'A');
	inorder(tree[node].second);
}
void postorder(int node) {
	if (!isupper(node + 'A'))
		return;
	postorder(tree[node].first);
	postorder(tree[node].second);
	cout << (char)(node + 'A');
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr	);
	int N;
	cin >> N;
	//Tree tree('A');
	for(int i = 0; i < N; i++) {
		char p, l, r;
		cin >> p >> l >> r;
		auto& child = tree[p - 'A'];
		if (l == '.')
			l = '[';
		if (r == '.')
			r = '[';
		child = make_pair(l - 'A', r - 'A');
		//tree.insert(p, l, r);
	}
	//Node* root = tree.getRoot();
	//tree.preOrder(root);
	preorder(0);
	cout << endl;
	//tree.inOrder(root);
	inorder(0);
	cout << endl;
	//tree.postOrder(root);
	postorder(0);
}