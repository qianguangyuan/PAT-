#include <iostream>
#include<vector>
using namespace std;

void Divi(vector<int>a, int target)
{
	int left = 0;
	int right = a.size() - 1;
	while (left<=right)
	{
		int middle = (left + right) / 2;
		if (a[middle] == target)
		{
			cout << "找到准确数为:" << middle;
			return;
		}
		else if (a[middle] > target)
			right = middle - 1;
		else
			left = middle + 1;
	}
	//此时right和left已经换位
	cout << "小于" << target << "的最大元素位置为" << right << endl;
	cout << "大于" << target << "的最小元素位置为" << left << endl;
}

int main()
{
	vector<int>a = { 1,3,7,8,9,15,17,19,33 };
	Divi(a, 16);
	return 0;
}

