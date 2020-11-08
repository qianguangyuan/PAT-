#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct Tree {
	int val;
	Tree* left, *right;
};

Tree* Build(Tree* root, int val) {
	if (root == NULL) {
		root = new Tree();
		root->val = val;
		root->left = root->right = NULL;
	}
	else if (abs(root->val) >= abs(val)) {
		root->left=Build(root->left, val);
	}
	else
		root->right=Build(root->right, val);
	return root;
}

bool judge1(Tree* root) {
	if (root == NULL)return true;
	else if (root->val < 0) {
		if (root->left != NULL && root->left->val < 0)return false;
		if (root->right != NULL && root->right->val < 0)return false;
	}
	return judge1(root->left) && judge1(root->right);
}

vector<int> v;

int getNum(Tree* root) {
	if (root == NULL) return 0;
	int l = getNum(root->left);
	//int r = getNum(root->right);
	if (root->val > 0)return l + 1;
	else return l;
}

bool judge2(Tree* root) {
	if (root == NULL) return true;
	int l = getNum(root->left);
	int r = getNum(root->right);
	if (l != r) return false;
	return judge2(root->left) && judge2(root->right);
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int sum; cin >> sum;
		v.clear();
		Tree* root=NULL;
		for (int j = 0; j < sum; j++) {
			int a; cin >> a; v.push_back(a);
			root=Build(root, a);
		}
		if (v[0] < 0 || judge1(root) == false || judge2(root) == false)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	
	}
	return 0;
}