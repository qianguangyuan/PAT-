/*归并排序，两个数组如果从小到大排序只需要找到第（m+n-1)/2个数据就行了，为了节约内存，
数组仅记录第一个数组，第二个数组通过移动进行比较，当count==mid即可，输出所指向的数据，即为中间数*/

#include<iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m;
	long long* a = new long long [m];
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	cin >> n;
	int mid = (m + n - 1) / 2;
	int count = 0, i = 0, j = 0;
	long long a2;
	cin >> a2;
	while (count < mid)
	{
		if (a[i] < a2) i++;
		else
		{
			j++;
			if (j < n)
				cin >> a2;
			else
				a2 = 0xfffffff;
		}
		count++;
		
	}
	cout << (a[i] < a2 ? a[i] : a2);
}