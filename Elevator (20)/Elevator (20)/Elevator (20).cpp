#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int pre = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > pre) {
            sum += (a[i] - pre) * 6;
            pre = a[i];
        }
        else {
            sum += (pre - a[i]) * 4;
            pre = a[i];
        }
    }
    sum = sum + n * 5;
    cout << sum;
}
