
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int, int>mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int num = 1;
    while (mp[num] > 0) num++;
    cout << num << endl;
}