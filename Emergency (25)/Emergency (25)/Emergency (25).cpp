#include <iostream>
#include<vector>
using namespace std;

int city; int nroad;
int start, nend;
int dis[500][500];
int mindis[500] = {0x3f3f3f3f};//起始点到终点的最短距离
vector <int> a[500];
int team[500];//每个城市的team数
int path;//最短路径数
int maxteam[500];
 
void dfs(int curcity, int distance,int teamnum)
{
    if (distance > mindis[curcity])
    {
        //cout << "1";
        return;
    }
    if (curcity == nend)//到达目的地
    {
        if (distance == mindis[curcity])
        {
            if (teamnum > maxteam[curcity])
                maxteam[curcity] = teamnum;
            path++;
        }
        else
        {
            mindis[curcity] = distance;
            path = 1;
            maxteam[curcity] = teamnum;
        }
    }
    else 
    {
        //cout << "fun";
        if (distance < mindis[curcity]) mindis[curcity] = distance;
        for (int i = 0; i < a[curcity].size(); i++)
        {
            int j = a[curcity][i];
            dfs(j, distance + dis[curcity][j], teamnum + team[j]);
        }
    }
}

int main()
{
    cin >> city >> nroad >> start >> nend;
    for (int i = 0; i < city; i++)
    {
        cin >> team[i];
    }
    for (int i = 0; i < nroad; i++)
    {
        int m, n, distance;
        cin >> m >> n >> distance;
        a[m].push_back(n);
        a[n].push_back(m);
        dis[m][n] = dis[n][m]=distance;
    }
    for (int i = 0; i < nroad; i++)
     {
        mindis[i] = 0x3f3f3f3f;
    //    cout << mindis[i];
     }
    dfs(start, 0, team[start]);
    cout << path << ' ' << maxteam[nend];
    return 0;
}
