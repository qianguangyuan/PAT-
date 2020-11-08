#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n, m;
int dis[201][201];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int j, k, distance;
		cin >> j >> k >> distance;
		dis[j][k] = dis[k][j] = distance;
	}
	cin >> m;
	vector<int> v;
	for(int i=0;i<m;i++){
		int k; cin >> k;
		v.resize(k);
		set<int> s;
		bool cycleflag = false;
		bool flag = 1;
		for (int i = 0; i < k; i++) {
			cin >> v[i];
			s.insert(v[i]);
		}
		if (s.size() < n || v[0] != v[k - 1]) {
			flag = false;
		}
		int distance = 0;
		for (int i = 0; i < k - 1; i++) {
			if (dis[v[i]][v[i + 1]] == 0) {
				flag = false;
				break;
			}
			distance += dis[v[i]][v[i + 1]];
		}
		if(flag==false){
			cout<<"Path "<<i+1<<": "<<distance<<" (TS simple cycle)"