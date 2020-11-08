#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    double a[1001] = { 0 };
    double b[1001] = { 0 }, c[1001] = { 0 };
    int n, m;
    cin >> n;
    int index;
    for (int i = 0; i < n; i++)
    {
        cin >> index;
        cin >> a[index];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> index;
        cin >> b[index];
    }
    int sum=0;
    for (int i = 0; i < 1001; i++)
    {
        c[i] = a[i] + b[i];
        if (c[i] != 0)
        {
            sum++;
        }
    }
    cout <<sum;
    for (int i = 1000; i >= 0; i--)
    {
        if (c[i] != 0)
        {
            cout << ' ' << i << ' '<<fixed<<setprecision(1) << c[i];
        }
    }
    return 0;
}
