// ALDS1_8_A Binary Search Tree 1
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_A

#include <cstdio>
#include <string>
#include<iostream>
using namespace std;

struct Node {
	int key;
	Node* right, * left, * parent;
} node[500000];

Node* root, * NIL;

int index = 0;
Node* NodeAlloc() {
	return &node[index++];
}

void insert(int k) {
	Node* y = NIL;
	Node* x = root;
	Node* z;

	z = NodeAlloc();
	z->key = k;
	z->left = NIL;
	z->right = NIL;

	while (x != NIL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	z->parent = y;
	if (y == NIL) {
		root = z;
	}
	else {
		if (z->key < y->key) {
			y->left = z;
		}
		else {
			y->right = z;
		}
	}
}

void inorder(Node* u) {
	if (u == NIL) return;
	inorder(u->left);
	printf(" %d", u->key);
	inorder(u->right);
}

void preorder(Node* u) {
	if (u == NIL) return;
	printf(" %d", u->key);
	preorder(u->left);
	preorder(u->right);
}

int main() {
	int n, i, x;
	string com;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		cin >> com;
		if (com == "insert") {
			scanf("%d", &x);
			insert(x);
		}
		else if (com == "print") {
			inorder(root);
			printf("\n");
			preorder(root);
			printf("\n");
		}
	}

	return 0;
}
