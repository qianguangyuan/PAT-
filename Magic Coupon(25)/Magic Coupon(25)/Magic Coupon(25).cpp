#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<long long > a, b;
    int m, n;
    cin >> m;
    long long num;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        a.push_back(num);
    }
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cin >> num;
        b.push_back(num);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long sum = 0;
    for (int i = 0, j = 0;(i<m )&& (j<n) && (a[i] < 0) && (b[j] < 0); i++, j++)
    {
        sum += a[i] * b[j];
    }
    for (int i = m-1, j = n-1; (i>=0 )&& (j>=0 )&& (a[i]>0)&&(b[j]>0); i--, j--)
    {
        sum+=a[i] * b[j];
    }
    cout << sum;
    return 0;
}
