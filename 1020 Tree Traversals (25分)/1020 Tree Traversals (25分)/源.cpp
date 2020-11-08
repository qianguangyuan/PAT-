#include<iostream>
#include<queue>
using namespace std;

int n;
int post[40], in[40];

struct Node {
	int val;
	Node* left, * right;
};

Node *pre(int h1, int t1, int h2, int t2) {
	if (h1>t1)return NULL;
	Node* node = new Node;
	int index;
	node->val = post[t1];
	for (index=h2; in[index] != post[t1]; index++);
	node->left=pre(h1, index-1-h2+h1, h2, index - 1);
	node->right=pre(index - h2 + h1, t1 - 1, index + 1, t2);
	return node;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)cin >> post[i];
	for (int i = 0; i < n; i++)cin >> in[i];
	Node* root = pre(0, n - 1, 0, n - 1);
	Node* Queue[40];
	int head = 0, tail = 0;
	Queue[tail++] = root;
	while (head < tail) {
		if (head != 0)cout << ' ';
		Node* p = Queue[head++];
		cout << p->val;
		if (p->left)Queue[tail++] = p->left;
		if (p->right)Queue[tail++] = p->right;
	}
}