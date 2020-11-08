#include <iostream>
#include<vector>
#include<cmath>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0)return false;
    }
    return true;
}

int reverse(int num, int radix)
{
    vector<int> v;
    for (int i = 0; num > 0; i++)
    {
        v.push_back(num % radix);
        num /= radix;
    }
    num = 0;
    for (int i = 0; i < v.size(); i++) {
        num += v[i] * pow(radix, v.size() - i - 1);
    }
    return num;
}

int main()
{
    int n, radix;
    while (1) {
        cin >> n;
        if (n < 0) break;          //输入负数立即退出循环
        cin >> radix;
        if (isPrime(n) && isPrime(reverse(n, radix))) //本身与反转数同时为素数
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
