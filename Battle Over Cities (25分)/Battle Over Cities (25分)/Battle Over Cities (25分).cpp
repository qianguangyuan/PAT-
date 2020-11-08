#include<iostream>
#include<vector>
using namespace std;

int ncity, nroad, dcity, lost;
vector<int> a[1000];
bool visited[1000] = { false };

void dfs(int j)
{
	visited[j] = true;
	for (int i = 0; i <a[j].size(); i++)
	{
		if (a[j][i] != lost && visited[a[j][i]] == false)
		{
			dfs(a[j][i]);
		}
	}
}

int main()
{
	cin >> ncity >> nroad >> dcity;
	for (int i = 0; i < nroad; i++)
	{
		int j, k;
		cin >> j >> k;
		a[j].push_back(k);
		a[k].push_back(j);
	}
	while(dcity--){
		cin >> lost;
		for (int i = 0; i <= ncity; i++)
		{
			visited[i] = false;
		}
		int j = 0;
		for (int i = 1; i <= ncity; i++)
		{
			if (!visited[i]  && i != lost)
			{
				j++;
				dfs(i);
			}
		}
		if (j == 0)
			cout << 0 << endl;
		else
			cout << j - 1 << endl;
	}
}