#include <iostream>
using namespace std;


struct Fraction
{
    long long up, down;
};

long long gcd(int a, int b)
{
    return b == 0 ? abs(a):gcd(b, a % b);
}

Fraction Addup(Fraction a, Fraction b)
{
    a.up = a.up * b.down + a.down * b.up;
    a.down = a.down * b.down;
    if (a.up > a.down)
    {
        long long d = gcd(abs(a.up), a.down);
        a.up /= d;
        a.down /= d;
    }
    else
    {

        long long d = gcd(abs(a.down), a.up);
        a.up /= d;
        a.down /= d;
    }
    return a;
}


void showresult(Fraction a) {
    if (a.down == 1)
        cout << a.up;
   /* else if(a.up>0){
        cout << a.up / a.down << " " << a.up % a.down << "/" << a.down;
    }*/
    else {
        cout << a.up / a.down << " " << a.up % a.down << "/" << a.down;
    }
}
int main()
{
    int num;
    cin >> num;
    Fraction sum, temp;
    sum.down = 1;
    sum.up = 0;
    while (num--)
    {

        cin >> temp.up >> temp.down;
        if (temp.up > temp.down)
        {
            long long d = gcd(temp.up, temp.down);
            temp.up /= d;
            temp.down /= d;
        }
        else
        {

            long long d = gcd(temp.down, temp.up);
            temp.up /= d;
            temp.down /= d;
        }
        sum = Addup(sum, temp);
    }
    showresult(sum);
    return 0;
}
