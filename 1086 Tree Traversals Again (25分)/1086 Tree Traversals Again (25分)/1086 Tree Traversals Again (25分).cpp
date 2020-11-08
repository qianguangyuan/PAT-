#include <iostream>
#include<vector>
#include<string>
using namespace std;

struct Node {
    int val;
    Node* left, * right;
};

int M;
vector<int> v;

void makenode(Node* &node)
{
    string s;
    int val; cin >> val;
    node = new Node;
    node->val = val;
    cin >> s;
    if (s == "Push") {
        makenode(node->left);
    }
    else {
        node->left = NULL;
    }
    s = ' '; cin >> s;
    if (s == "Push") {
        makenode(node->right);
    }
    else {
        node->right = NULL;
    }
}

void postorder(Node* node) {
    if (node == NULL)return;
    postorder(node->left);
    postorder(node->right);
    v.push_back(node->val);
}

int main()
{
    cin >> M;
    string s; cin >> s;
    Node* node=NULL;
    makenode(node);
    postorder(node);
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1)
        {
            cout << v[i];
        }
        else
            cout << v[i] << ' ';
    }
}

