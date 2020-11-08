#include<iostream>
#include<string>
using namespace std;

int main() {
    string a;
    cin >> a;
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] - '0';
    }
    string str[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
    string sum2 = to_string(sum);
    for (int i = 0; i < sum2.size(); i++) {
        if (i > 0)cout << ' ';
        cout << str[sum2[i] -'0' ];
    }
    return 0;
}