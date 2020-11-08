#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> pre, in;

struct Node {
	int val;
	Node* left, * right;
};

Node* makenode(int h1, int t1, int h2, int t2)
{
	if (t1 < h1)return NULL;
	Node* node = new Node;
	node->val = pre[h1];
	int index;
	for (index = h2; in[index] != pre[h1]; index++);
	node->left = makenode(h1 + 1,index-h2+h1 , h2, index - 1);
	node->right = makenode(index-h2+h1+1, t1, index + 1, t2);
	return node;
}

bool flag = false;

void dfs(Node* root) {
	if (root == NULL||flag==true)
		return;
	dfs(root->left);
	dfs(root->right);
	if (flag == false) {
		cout << root->val;
		flag = true;
	}
}

int main() {
	cin >> n;
	pre.resize(n);
	in.resize(n);
	for (int i = 0; i < n; i++) cin >> pre[i];
	for (int i = 0; i < n; i++) cin >> in[i];
	Node* root = NULL;
	root = makenode(0, n - 1, 0, n - 1);
	dfs(root);
	return 0;
}