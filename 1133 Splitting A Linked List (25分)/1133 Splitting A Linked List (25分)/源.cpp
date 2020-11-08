#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

struct Node {
	int data;
	int next;
};

vector <int>v1, v2, v3, ans, temp;

int main() {
	Node node[100001];
	int first, n, k;
	cin >> first >> n >> k;
	for (int i = 0; i < n; i++) {
		int add, data, next;
		cin >> add;
		cin>>node[add].data >> node[add].next;
	}
	while (first!=-1)
	{
		temp.push_back(first);
		first = node[first].next;
	}
	for (int i = 0; i < temp.size(); i++) {
		if (node[temp[i]].data < 0) v1.push_back(temp[i]);
		else if (node[temp[i]].data >= 0 && node[temp[i]].data <= k)v2.push_back(temp[i]);
		else v3.push_back(temp[i]);

	}
	for (int i = 0; i < v1.size(); i++) {
		ans.push_back(v1[i]);
	}
	for (int i = 0; i < v2.size(); i++) {
		ans.push_back(v2[i]);
	}
	for (int i = 0; i < v3.size(); i++) {
		ans.push_back(v3[i]);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%05d %d %05d\n", ans[i], node[temp[i]].data, node[temp[i]].next);
	}
	
}