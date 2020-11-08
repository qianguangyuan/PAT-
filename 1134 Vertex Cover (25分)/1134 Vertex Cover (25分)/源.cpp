#include<iostream>
#include<vector>
using namespace std;

vector<int> v[10000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		int j, k;
		cin >> j >> k;
		v[j].push_back(i);
		v[k].push_back(i);
	}
	int time;
	cin >> time;
	for (int i = 0; i < time; i++) {
		int num; cin >> num;
		int a[10001];
		for (int i = 0; i < 10001; i++) {
			a[i] = 0;
		}
		for (int i = 0; i < num; i++) {
			int n1; cin >> n1;
			for (int i = 0; i < v[n1].size(); i++)
				a[v[n1][i]] = 1;
		}
		int flag = 0;
		for (int i = 0; i < m; i++) {
			if (a[i] == 0) {
				cout << "No" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0)cout << "Yes" << endl;
	}
	return 0;
}