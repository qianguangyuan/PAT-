#include<iostream>
#include<vector>
#include<set>
using namespace std;

//这里我觉得我的思路比题解要好一些，分析入度，把指向一个点的所有点都记录进去，如果同时记录所有遍历过的点，如果
//某个遍历的点未出现，则直接不是拓扑排序

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> v[1001];
	while (m--)
	{
		int j, k; cin >> j >> k;
		v[k].push_back(j);
	}
	cin >> m;
	vector <int> a(n);
	set<int>ans;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++)cin>>a[i];
		int Hash[1001] = { 0 };
		for (int i = 0; i < n; i++) {
			Hash[a[i]] = 1;
			for (auto it : v[a[i]]) {
				if (Hash[it] == 0)
				{
					ans.insert(j);
						break;
				}
			}
		}
	}
	int i = 1;
	for (auto it:ans) {
		cout <<it;
		if (i != ans.size())cout << ' ';
		i++;
	}
		return 0;
}
