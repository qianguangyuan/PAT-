#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int visited[10001];
	vector<int> v[10001];
	for (int i = 0; i < n - 1; i++) {
		int j, k; cin >> j >> k;
		v[j].push_back(k);
		v[k].push_back(j);
	}

}

