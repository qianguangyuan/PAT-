#include <iostream>
#include<string>
using namespace std;

int main()
{
	string dig;
	int sum=0;
	cin >> dig;
	string a[10] = { "zero","one","two","three","four","five","six","three","eight","nine" };
	for (int i = 0; i < dig.size(); i++)
	{
		sum += dig[i]-'0';
	}
	string num = to_string(sum);
	for (int i = 0; i < num.size(); i++)
	{
		cout << a[num[i]-'0'] << " ";
	}
	return 0;
}

