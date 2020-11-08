#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5;
const int C = 20;
int flag[N + 1] = { 0 };//物品是否在背包中，下标从1开始算
int V[N + 1][Capacity + 1] = { 0 }; //造表记录子问题的最优解
int Knapsack(int w[], int v[], int n, int C);//实际物品数目，背包容量
int main()
{
    int w[] = { 0,3,2,1,4,5 };
    int v[] = { 0,25,20,15,40,50 };
    int n = 5, C = 6;
    int maxValue = Knapsack(w, v, n, C);
    cout << maxValue;
    return 0;
}
int Knapsack(int w[], int v[], int n, int C) {
    for (int i = 0; i <= n; ++i)
        V[i][0] = 0;
    for (int j = 0; j <= C; ++j)
        V[0][j] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= C; ++j)
        {
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else {
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
            }
        }

    for (int i = n, j = C; i > 0; --i)
    {
        if (V[i][j] > V[i - 1][j])
        {
            flag[i] = 1;
            j -= w[i];
        }
        else
            flag[i] = 0;
    }
    cout << "造表\n";
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= C; ++j)
            cout << V[i][j] << '\t';
        cout << endl;
    }

    for (int i = 1; i <= n; ++i)
        cout << flag[i] << '\t';
    cout << endl;
    return V[n][C];
}