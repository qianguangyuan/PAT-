#include<iostream>
#include<vector>
using namespace std;

int n, m;
int e[201][201];
vector<int> v;

int main() {
	cin >> n >> m;
	int i, j;
	while (m--)
	{
		cin >> i >> j;
		e[i][j] = e[j][i] = 1;
	}
	int a; cin >> a;
	while (a--) {
		int k; cin >> k;
		v.resize(k);
		int Hash[201] = { 0 };
		for (int i = 0; i < k; i++) {
			cin >> v[i];
			Hash[v[i]] = 1;
		}
		bool isMaximal = true, isClique = true;
		for (int i = 0; i < k; i++) {
			if (isClique == false)break;
			for (int j = i + 1; j < k; j++) {
				if (e[v[i]][v[j]] == 0) {
					isClique = false;
					cout << "Not a Clique" << endl;
					break;
				}
			}
		}
		if (isClique == false) continue;
		for (int i = 1; i <= n; i++) {
			if (Hash[i] == 0) {
				for (int j = 0; j < k; j++) {
					if (e[i][v[j]] == 0)break;
					if (j == k - 1)isMaximal = false;
				}
			}
		}
			if (isMaximal == false) {
				printf("Not Maximal\n");
			}
		if (isMaximal == true) printf("Yes\n");
	}
	return 0;
}