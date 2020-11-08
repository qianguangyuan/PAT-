// n阶Hanoi塔问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{

	void hanoi(int num, char a, char b, char c);
	int num;
	cout << "请输入移动的汉诺塔:";
	cin >> num;
	hanoi(num, 'a', 'b', 'c');
	return 0;
}
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		cout << "移动第" << n << " 个盘子 " << a << " 到 " << c << endl;//盘子数为1时 直接从a移到c,递归的出口
	else
	{
		hanoi(n - 1, a, c, b); //将上面的n-1个盘子借助c从a移到b
		cout << "移动第" << n << " 个盘子 " << a << "到" << c << endl;//把第n个盘子从a移到c
		hanoi(n - 1, b, a, c);//把b上的n-1个盘子移到c
	}
}
