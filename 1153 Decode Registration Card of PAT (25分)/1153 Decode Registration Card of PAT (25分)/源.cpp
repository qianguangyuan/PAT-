#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


struct node {
	int val;
	string id;
};


bool compare(const node &n1, const node& n2) {
	if (n1.val == n2.val)
		return n1.id < n2.id;
	return n1.val > n2.val;
}

int main() {
	int n, m; cin >> n >> m;
	vector<node> v(n);
	for (int i = 0; i < n; i++) 
		cin >> v[i].id >> v[i].val;
	for (int i = 1; i <= m; i++) {
		int j; string s;
		cin >> j >> s;
		cout << "Case " << i << ": " << j << ' ' << s << endl;
		if (j == 1) {
			vector<node> ans;
			for (int k = 0; k < n; k++) {
				if (v[k].id.substr(0,1) == s) {
					ans.push_back(v[k]);
				}
			}
			if(ans.size()==0)  printf("NA\n");
			sort(ans.begin(), ans.end(),compare);
			for (auto it : ans)
				cout << it.id << ' ' << it.val << endl;
		}
		if (j == 2) {
			int count = 0, sum = 0;
			for (int i = 0; i < n; i++) {
				if (v[i].id.substr(1, 3) == s) {
					count++;
					sum += v[i].val;
				}
			}
			if (count != 0)printf("%d %d", count, sum);
			else printf("NA\n");
		}
		if (j == 3) {
			unordered_map<string, int> Mymap;
			vector<node> ans;
			for (int i = 0; i < n; i++) {
				if (v[i].id.substr(4, 6) == s) {
					Mymap[v[i].id.substr(1, 3)]++;
				}
			}
				for (auto it : Mymap)
					ans.push_back({ it.second,it.first });
				sort(ans.begin(), ans.end(),compare);
				for (auto it : ans) 
					printf("%s %d\n", it.id.c_str(), ans[j].val);
				if(ans.size()==0)cout << "NA" << endl;
		}
	}
	return 0;
}