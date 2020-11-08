#include<iostream>
#include<string>
using namespace std;

string reverse(string s){
	int num[10000];

int main() {
	string n, k;
	cin >> n >> k;
	int i = 0, j = n.size() - 1;
	int count = 0;
	while (j>=i)
	{
		if (n[i] == n[j]){
			count++;
			j--;
			i++;
	}
}