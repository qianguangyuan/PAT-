#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

int Sum;
vector<vector<int>> v;

void dfs(TreeNode* root, int sum,vector<int> temp) {
    if (sum + root->val == Sum) {
        temp.push_back(root->val);
        v.push_back(temp);
        return;
    }
    else if (sum + root->val > Sum)
        return;
    else {
        temp.push_back(root->val);
        if (root->left)
            dfs(root->left, sum + root->val, temp);
        if (root->right)
            dfs(root->right, sum + root->val, temp);
    }
}

int main() {
    vector<int> v;
    v.po
}