//n�Ľ׳˵ļ��㣬n����100��
//��ʾ����n����10ʱ��n�Ľ׳˾ͳ���32λ�������ܱ�ʾ���ķ�Χ�ˡ���ʱ��Ҫ����һ��int�ͻ���char������洢�������˷��ĳ����Լ������

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int array[10001] = { 0 };//��һ��λ�ÿ��ܲ�����λ�����Լ�һ
	array[0] = 1;
	int digit = 1;//λ��
	for (int i = 2; i <= n; i++)//��2��ʼ��
	{
		int carry = 0;//��λ
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