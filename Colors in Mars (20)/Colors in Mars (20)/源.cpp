#include<iostream>
#include<vector>
using namespace std;

void PrintDig(int i)
{
	if (i < 10)
		cout << i;
	else
	{
		switch (i)
		{
		case 10:cout << 'A'; break;
		case 11:cout << 'B'; break;
		case 12:cout << 'C'; break;
		default:
			break;
		}
	}
}

int main()
{
	vector<int> input;
	int a, b, c;
	char dig[] = { 'A','B','C' };
	cin >> a >> b >> c;
	input.push_back(a);
	input.push_back(b);
	input.push_back(c);
	for (int i = 0; i < input.size(); i++)
	{
		if (i == 0)
			cout << '#';
		int b = input[i] % 13;
		int a = input[i] / 13;
		PrintDig(a); PrintDig(b);
	}
	return 0;

}