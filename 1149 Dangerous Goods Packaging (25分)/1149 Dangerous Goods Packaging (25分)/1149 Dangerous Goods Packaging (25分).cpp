#include <iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;

map<int, vector<int>> Mymap;

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int j, k; cin >> j >> k;
		Mymap[j].push_back(k);
		Mymap[k].push_back(j);
	}
	while (m--) {
		int num;
		cin >> num;
		vector<int> v, a(100000);
		int flag = 0;
		for (int i = 0; i < num; i++) {
			int j; cin >> j; a[j] = 1;
			v.push_back(j);
		}
		for(int i=0;i<v.size();i++){
			for (int j = 0;j < Mymap[v[i]].size();j++) {
				if (a[Mymap[v[i]][j]] == 1) {//如果u的相克也签了到，直接输出否
					flag = 1;
					break;
				}
			}
		}

		if (flag == 1)cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
