#include <iostream>
#include<vector>
using namespace std;

int m, n, nroad, pnode, lasttake= 0x3f3f3f3f,lastsend= 0x3f3f3f3f;
vector<int> v[501],path,lastp;
int a[501],b[501], dis[501][501];
int mindis[501] = { 0x3f3f3f3f };

void dfs(int cur, int dist,int send,int take) {
	if (dist > mindis[cur])return;
	path.push_back(cur);
	if (cur == pnode) {
		if (dist< mindis[cur]||(dist==mindis[cur]&&send<lastsend)||(dist==mindis[cur]&&take<lasttake))
		{
			lastp=path;
			lasttake=take;
			lastsend=send;
			mindis[cur]=dist;
		}
	}
	else {
		mindis[cur] = dist;
		for (int i = 0; i < v[cur].size(); i++) {
			int j = v[cur][i];
			if (take + a[j] < m / 2)
				dfs(j, dist + dis[cur][j], send+m / 2 - take - a[j], 0);
			else
				dfs(j, dist + dis[cur][j], send, take + a[j] - m / 2);
		}
	}

	path.pop_back();
}

int main()
{
	cin >> m >> n >> pnode >> nroad;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < nroad; i++) {
		int j, k, dist; cin >> j >> k >> dist;
		v[j].push_back(k);
		v[k].push_back(j);
		dis[j][k] = dist;
		dis[k][j] = dist;
	}
	for (int i = 0; i <= n; i++)
		mindis[i] = 0x3f3f3f3f;

	dfs(0, 0,0,0);
	cout << lastsend << ' ';
	cout << 0;
	for (int i = 1; i < lastp.size(); i++)
		cout << "->"<<lastp[i]  ;
	cout << ' ' << lasttake;
	return 0;
}
