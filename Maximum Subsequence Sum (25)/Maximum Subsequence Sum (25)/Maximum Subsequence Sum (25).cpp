#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[10001];
    for (int i = 0; i < n; i++)cin >> a[i];
    int sum = 0;
    int maxsum = 0;
    int left = 0, right = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
        {
            sum = 0;
            j= i + 1;
            continue;
        }
        if (sum > maxsum)
        {
            maxsum = sum;
            right = i;
            left = j;
        }
    }
    if (maxsum == 0) {
        cout << 0 << ' ' << a[0] << ' ' << a[n - 1];
        return 0;
    }
    cout << maxsum << ' ' << left<< ' ' << right;
}
