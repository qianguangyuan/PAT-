#include <iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> a[100];
int b[100] = { 0 };
int maxlever=0;

void dfs(int curid, int lever)
{
    if (lever > maxlever) maxlever = lever;
    if (a[curid].size() > 0)
    {
        for (int i = 0; i < a[curid].size(); i++)
        {
            dfs(a[curid][i], lever + 1);
        }
    }
    else
        b[lever]++;
}

int main()
{
    cin >> M >> N;
    for (int i = N - 1; i >= 0; i--)
    {
        int id; int time; cin >> id >> time;
        for (int i = time - 1; i >= 0; i--)
        {
            int child; cin >> child;
            a[id].push_back(child);
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= maxlever; i++)
        cout << b[i] << " ";
    return 0;
}
