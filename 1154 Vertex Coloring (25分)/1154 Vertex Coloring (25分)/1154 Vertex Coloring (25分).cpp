#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int n, m;
vector<int> v[10001];
int a[10001];

bool isSame() {
	for (int i = 0; i < 10001; i++) {
		for (auto it : v[i]) {
			if (a[i] == a[it])
				return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int j, k; cin >> j >> k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	int k; cin >> k;
	while (k--) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (isSame())cout << "No" << endl;
		else {
			unordered_map<int, int> map;
			for(int i=0;i<n;i++)
					map[a[i]]++;
			cout << map.size() << '-' << "coloring" << endl;
		}
	}
	return 0;
}