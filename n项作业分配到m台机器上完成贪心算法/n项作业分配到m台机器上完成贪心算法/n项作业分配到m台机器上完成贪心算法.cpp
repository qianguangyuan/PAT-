// 已知有n个独立的作业J1，J2…，Jn由m台相同的机器进行加工处理。作业i所需的处理时间为ti。
//现约定，任何作业Ji可以在任何一台机器上处理，但未完成前不允许间断、划分。
//试用贪心法设计一种调度方案，把n项作业分配到m台机器上完成，所需时间T = MAX{ Ti }(1≦i≦m)，
//其中Ti为分配给机器i的处理作业的时间之和。目标是使得T尽可能小。（各机器负载均衡）
//将n个作业按时间长到时间短排序，把时间最长的作业放入机器，再依次把次长的放入机器，直到
//机器都在工作，再取作业放入作业时间最短的机器上，最后工作时间持续最长的机器即为最短的处理时间
#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int Min(vector< int > worktime, int worknum) {
    int min = 0;
    for (int i = 1; i < worknum; i++)
    {
        if (worktime[i] < worktime[min]) 
            min = i;
    }
        return min;
    }


void BestSolution(vector<int> &a, int worknum)//数组记录需要时长
{
    sort(a.begin(), a.end());//对数组排序
    if (worknum > a.size())
    {
        cout << "最短时间为：" << a[a.size() - 1];
        return;
    }
    else
    {
        vector<int> worktime;//工作时间
        for (int i = 0; i < worknum; i++)
        {
            worktime.push_back(0);
        }
        for (int i = a.size()-1; i >=0; i--)
        {
           int min= Min(worktime, worknum);
           cout << "第" << min + 1 << "号机器处理任务"<<i+1<<"用了"<<a[i]<<"时间"<<endl;
           worktime[min] += a[i];
        }
        sort(worktime.begin(),worktime.end());//机器作业时间从小到大排序
        for (int i = 0; i < worknum; i++)
        {
            cout << worktime[i] << "  ";
        }
        cout << "最短时间为:" << endl;
        cout << worktime[worknum-1] << endl;
    }
}


int main()
{
    vector<int> a = { 1,2,3,4,5,9,7,8,6};
    BestSolution(a, 4);
    return 0;

}

