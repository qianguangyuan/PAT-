//n的阶乘的计算，n大于100。
//提示：当n超过10时，n的阶乘就超过32位补码所能表示数的范围了。此时需要定义一个int型或者char型数组存储大整数乘法的乘数以及结果。

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int array[10001] = { 0 };//第一万位置可能产生进位，所以加一
	array[0] = 1;
	int digit = 1;//位数
	for (int i = 2; i <= n; i++)//从2开始乘
	{
		int carry = 0;//进位
		for (int j = 0; j < digit; j++)
		{
			int k = array[j] * i + carry;
			array[j] = k % 10;
			carry = k / 10;
		}
		while (carry != 0)
		{
			array[++digit] = carry % 10;
			carry /= 10;
		}
	}
	for (int i = digit - 1; i >= 0; i--)
		cout << array[i];
	cout << endl;
    return 0;
}