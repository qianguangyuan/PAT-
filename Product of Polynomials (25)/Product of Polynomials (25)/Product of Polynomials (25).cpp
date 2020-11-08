#include <iostream>
#include<cstdio>
#include<vector>
#include<iomanip>
using namespace std;

double v1[1001], v2[1001],v3[2002];

int n, m;
int main()
{
    cin >> n;
    double cof;int exp;
    for (int i = 0; i < n; i++) {
        cin >> exp>>cof;
        v1[exp] = cof;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> exp >> cof;
        v2[exp]=cof;
    }
    for (int i = 0; i < 1001; i++) {
        for(int j = 0;j < 1001; j++)
        {
          v3[i + j] += v1[i] * v2[j];
        }
    }
    int num = 0;
    for (int i = 0; i < 2002; i++) {
        if (v3[i] != 0) {
            num++;
        }
    }
    cout << num ;
    for (int i = 2001; i >=0; i--) {
        if (v3[i] != 0)
        {
            cout << ' ' << i << ' ' << fixed << setprecision(1) << v3[i];
        }
    }
}
