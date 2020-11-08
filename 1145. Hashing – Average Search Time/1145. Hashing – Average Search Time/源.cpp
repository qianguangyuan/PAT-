#include<iostream>
using namespace std;

bool isPrime(int i) {
	if (i <= 1)return false;
	for (int j = 2; j * j <=i; j++) {
		if (i % j == 0)return false;
	}
	return true;
}

int main() {
	int tsize, n, m;
	cin >> tsize >> n >> m;
	while (!isPrime(tsize))tsize++;
	int* a = new int[tsize];
	for (int i = 0; i < tsize; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		int flag = 0;
		for (int i = 0; i < tsize; i++) {
			int pos = (k + i * i) % tsize;
			if (a[pos] == 0) {
				a[pos] = k;
				flag = 1;
				break;
			}
		}
		if (flag == 0)cout << k <<" cannot be inserted." << endl;
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		for (int i = 0; i <tsize; i++) {
			count++;
			int pos = (k + i * i) % tsize;
			if (a[pos] == k||a[pos]==0)break;
		}
		
	}
	printf("%.1lf\n", count * 1.0 / m);
	return 0;
}