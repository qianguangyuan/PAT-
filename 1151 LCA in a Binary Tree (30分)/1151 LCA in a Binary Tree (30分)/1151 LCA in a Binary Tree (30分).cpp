#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> pre, in;

struct Node {
	int val;
	Node* left, *right;
};

Node* makenode(int h1,int t1,int h2,int t2) {
	if (h1 > t1)return;
	Node* root = new Node;
	root->val = pre[h1];
	int index;
	for (int index = h2; in[index] = pre[h1]; index++);
	root->left = makenode(h1 + 1,index-h2+h1 , h2, index - 1);
	root->right = makenode(t1-t2+index+1, t1, index + 1, t2);
	return root;
}

int main() {
	cin >> N >> M;
	pre.resize(M);
	in.resize(M);
	int Hash[10001] = { 0 };
	for (int i = 0; i < M; i++) {
		cin >> pre[i];
		Hash[pre[i]] = 1;
	}
	for (int i = 0; i < M; i++)cin >> in[i];
	while (N--)
	{
		int j, k;
		cin >> j >> k;
		if (Hash[j] == 0 && Hash[k] == 0)
			cout << "ERROR: " << j << " and " << k << " are not found." << endl;
		else if(Hash[j]==0)
			cout << "ERROR: " << j <<" is not found." << endl;
		else if(Hash[k]==0)
			cout << "ERROR: " << k << " is not found." << endl;
		else
		{
			Node* root = NULL;
			root = makenode(0, N - 1, 0, N - 1);
		}
	}
}