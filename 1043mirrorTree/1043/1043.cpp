#include<iostream>
#include<vector>
using namespace std;


int n,a[10000],user;
vector<int> post;

struct node {
	int val;
	node* right, * left;
};

node* makeBST(int cursor, int ceil, int floor) {
	node* p = new node;
	user++;
	p->val = a[cursor];
	int i;
	for (i = cursor + 1; i < n && a[i] >= floor; i++);
	if (i == cursor + 1)p->left = nullptr;
	else p->left = makeBST(cursor + 1, a[cursor], floor);
	if (i<n && a[i]>a[cursor] && a[i] < ceil)
		p->right = makeBST(i, ceil, a[cursor]);
	return p;
}

void postorder(node* root) {
	if (!root)return;
	postorder(root->left);
	postorder(root->right);
	post.push_back(root->val);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	user = 0;

	node* root = makeBST(0, 1000000000, -100000000);
	if (user == n) {
		cout << "Yes\n";
		postorder(root);
		for (int i = 0; i < post.size(); i++) {
			if (i)cout << ' ';
			cout << post[i];
		}
	}
	else {
		user = 0;
		root = makeBST(0, 1000000000, -100000000);
		cout << "NO";
		return 0;
	}
}