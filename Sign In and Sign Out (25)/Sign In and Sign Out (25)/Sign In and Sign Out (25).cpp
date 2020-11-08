#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Per
{
	string id;
	string in;
	string out;
};

bool comparein(Per &p1, Per &p2)
{
	string s1 = p1.in.substr(0,2);
	string s2=p2.in.substr(0, 2);
	if (s1 == s2)
	{
		string s3 = p1.in.substr(3, 2);
		string s4 = p2.in.substr(3, 2);
		if (s3 == s4)
		{
			string s5 = p1.in.substr(6, 2);
			string s6 = p2.in.substr(6, 2);
			return s5 < s6;
		}
		else 
		return s3 < s4;
	}
	else
		return s1 < s2;
}

bool compareout(Per &p1, Per &p2)
{

	string s1 = p1.out.substr(0, 2);
	string s2 = p2.out.substr(0, 2);
	if (s1 == s2)
	{
		string s3 = p1.out.substr(3, 2);
		string s4 = p2.out.substr(3, 2);
		if (s3 == s4)
		{
			string s5 = p1.out.substr(6, 2);
			string s6 = p2.out.substr(6, 2);
			return s5 > s6;
		}
		else
			return s3 > s4;
	}
	else
		return s1 > s2;
}


int main()
{
	int N;
	cin >> N;
	Per* person = new Per[N];
	for (int i = 0; i < N; i++)
	{
		cin >> person[i].id >> person[i].in >> person[i].out;
	}
	sort(person, person+N, comparein);
	cout << person[0].id << " ";
	sort(person, person+N, compareout);
	cout << person[0].id;
	return 0;

}