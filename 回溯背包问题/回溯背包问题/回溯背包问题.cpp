#include<iostream>
using namespace std;

int n;//物品个数
int c;//背包容量
int bestvalue;//最大价值
int v[100];//物品的价值
int w[100];//物品的重量
int x[100];//x[i]当前装包的物品
int bestx[100];//最终装包的物品

void Backtrack(int i, int cv, int cw)//cw当前包内物品重量，cv当前包内物品价值
{
    int j;
    if (i > n)//搜索到了叶子结点，回溯结束
    {
        if (cv > bestvalue)//更换价值及装包方案
        {
            bestvalue = cv;
            for (i = 0; i <= n; i++)
                bestx[i] = x[i];
        }
    }
    else
        for (j = 0; j <= 1; j++)
        {
            x[i] = j;//判断装包还是不装包
            if (cw + x[i] * w[i] <= c)//当前质量比背包容量要小，更新总价值，对i+1进行回溯
            {
                cw += w[i] * x[i];
                cv += v[i] * x[i];
                Backtrack(i + 1, cv, cw);
                //回溯完毕返回当前的最大质量和最大价值
                cw -= w[i] * x[i];
                cv -= v[i] * x[i];
            }
        }
}

int main()
{
    int i;
    bestvalue = 0;
    cout << "输入物品的个数为:" << endl;
    cin >> n;
    cout << "输入背包的最大容量为:" << endl;
    cin >> c;
    cout << "输入物品的质量分别为:" << endl;
    for (i = 1; i <= n; i++)
        cin >> w[i];
    cout << "输入物品的价值分别为:" << endl;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    Backtrack(1, 0, 0);//从i=1开始初始化调用回溯函数
    cout << "最大价值为:" << endl;
    cout << bestvalue << endl;
    cout << "装入的物品为:" << endl;
    for (i = 1; i <= n; i++) {
        if (bestx[i] == 1)
            cout << "第" << i << "件物品被装包" << endl;
    }
    cout << endl;
    return 0;
}
