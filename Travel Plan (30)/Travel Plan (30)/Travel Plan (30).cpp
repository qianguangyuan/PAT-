#include <iostream>
#include<vector>
using namespace std;

int N, M, S, D;
vector<int> a[500];
vector<int> r,minr;
int cost[500][500], dis[500][500];
int mincost[500] = { 0x3f3f3f3f }, mindis[500] = { 0x3f3f3f3f };

void dfs(int start,int distance,int cos)
{
    if (distance > mindis[start])  return;
    r.push_back(start);
    if (start == D) {
        if ((distance < mindis[start]) || distance == mindis[start] && cos < mincost[start])
        {
            minr = r;
            mindis[start] = distance;
            mincost[start] = cos;
        }
    }
    else
    {
        mindis[start] = distance;
        for (int i = 0; i < a[start].size(); i++)
        {
            int j = a[start][i];
            dfs(j, distance + dis[start][j],cos+cost[start][j]);
        }
    }
    r.pop_back();
}

int main()
{
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++)
    {
        int city1, city2, distance, cost1;
        cin >> city1 >> city2 >> distance >> cost1;
        a[city1].push_back(city2);
        a[city2].push_back(city1);
        cost[city1][city2] = cost[city2][city1] = cost1;
        dis[city1][city2] = dis[city2][city1] = distance;
    }
    for (int i = 0; i < N; i++)
    {
        mincost[i] = 0x3f3f3f3f;
        mindis[i] = 0x3f3f3f3f;
    }
    dfs(S,0,0);
    
    for (int i = 0; i < minr.size(); i++) {
        cout << minr[i] << ' ';
    }
    cout << mindis[D] << ' ' << mincost[D];
    return 0;

}
