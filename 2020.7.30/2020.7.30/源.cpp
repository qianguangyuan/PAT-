#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;

int main()
{
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int j = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			v.push_back(a[i]);
		};
	}
	int flag=false;
	for (int i = 1; i < v.size(); i++) {
		if (a[i] != a[i - 1] && a[i] - a[i - 1] > 1) {
			cout << a[i - 1] + 1;
			flag = true;
			break;
		}
	}
			return  0;
}