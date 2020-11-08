#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

struct Stu {
	string name;
	string id;
	int grade;
};

bool compare(Stu& s1, Stu& s2) {
	return s1.grade < s2.grade;
}
int main()
{
	int n, flag = false;
	cin >> n;
	Stu* stu = new Stu[n];
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].name >> stu[i].id >> stu[i].grade;

	}
	int g1, g2; cin >> g1 >> g2;
	sort(stu, stu + n, compare);
	for (int i = n - 1; i >= 0; i--) {
		if (stu[i].grade >= g1 && stu[i].grade <= g2)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "NONE";
	else
	{
		for (int i = n - 1; i >= 0; i--) {
			if (stu[i].grade>=g1&&stu[i].grade<=g2)
			{
				cout << stu[i].name << ' ' << stu[i].id << endl;
			}
		}
	}
		return 0;
}