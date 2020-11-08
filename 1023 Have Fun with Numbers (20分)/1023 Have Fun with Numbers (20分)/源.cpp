#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	map<int, int> mymap;
	string s; cin >> s;
	int num[30] = { 0 };
	int carry = 0;
	for (int i = 0; i < s.size(); i++) {
		mymap[(s[i]-'0')]++;
	}
	for (int i = s.size()-1; i >=0; i--) {
		int j = (s[i] -'0') * 2 + carry;
		carry = j / 10;
		num[s.size() - i - 1] = j % 10;
	}
	if (carry > 0) {
		cout << "No" << endl;
		cout << 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			cout << num[i];
		}
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		mymap[num[i]]--;
		if (mymap[num[i]] == 0)
			mymap.erase(num[i]);
	}
	if (mymap.size() == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = s.size() - 1; i >= 0; i--) {
		cout << num[i];
	}
	return 0;
	}