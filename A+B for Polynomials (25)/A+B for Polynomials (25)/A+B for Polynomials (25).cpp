#include <iostream>
#include<cmath>
#include<vector>
using namespace std;

struct Poly
{
	int  exp;
	double cof;
};

int main()
{
	vector<Poly> p1, p2;
	int m, n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		Poly np;
		cin >> np.exp >> np.cof;
		p1.push_back(np);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Poly np;
		cin >> np.exp >> np.cof;
		p2.push_back(np);
	}
	vector<Poly> p3;
	int i = 0, j = 0;
	while (i<p1.size()&&j<p2.size())
	{
		if (p1[i].exp == p2[j].exp)
		{
			Poly np;
			np.cof = p1[i].cof + p2[j].cof;
			if (fabs(np.cof)<1e-8)
			{
				continue;
			}
			np.exp = p1[i].exp;
			p3.push_back(np);
			i++; j++;
		}
		else if (p1[i].exp > p2[j].exp)
		{
			p3.push_back(p1[i]);
			i++;
		}
		else {
			p3.push_back(p2[j]);
			j++;
		}
	}
	while (i<p1.size())
	{
		p3.push_back(p1[i]);
		i++;
	}
	while ( j<p2.size())
	{
		p3.push_back(p2[j]);
		j++;
	}
	cout << p3.size();
	for (int i = 0; i < p3.size(); i++)
	{
		cout << " " << p3[i].exp <<' '<< p3[i].cof;
	}
	return 0;
}

