#include <iostream>
#include <string>
using namespace std;



bool isanswer(string n)
{
    long long num1, num2;
    string s1 = n.substr(0, n.size() / 2);
    string s2 = n.substr(n.size() / 2);
    num1 = stol(s1); num2 = stol(s2);
    long long c = stol(n);
    if (num1 * num2 != 0 && c % (num1 * num2) == 0)
        return true;
    return false;
}

int main()
{
    int n; cin >> n;
    string a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];

    }
    for (int i = 0; i < n; i++) {
        if (isanswer(a[i]))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

