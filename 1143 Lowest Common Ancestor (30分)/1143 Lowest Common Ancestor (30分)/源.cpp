#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	unordered_map<int,bool> map;
	for (int i = 0; i < m; i++) {
		cin >> v[i];
		map[v[i]] = 1;
	}
	while (n--) {
		int j, k; cin >> j >> k;
		for (int i = 0; i < m; i++) {
			int a = v[i];
			if ((a <= j && a >= k) || (a <= k && a > j))
			{
				if (a == j || a == k) {
					prrin
				}
			}
		}
	}

}