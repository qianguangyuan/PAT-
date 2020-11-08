#include<iostream>
#include<string>
#include<unordered_map>
#include<set>
using namespace std;

unordered_map<string, set<string>> mymap[6];

int main() {
	int n; cin >> n;		getchar();
	for (int i = 0; i < n; i++) {
		string id, title, author, key, publisher, year;
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		do {
			cin >> key;
			mymap[3][key].insert(id);
		} while (getchar() == ' ');
		getline(cin, publisher);
		getline(cin, year);
			mymap[1][title].insert(id);
			mymap[2][author].insert(id);
			mymap[4][publisher].insert(id);
			mymap[5][year].insert(id);
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; string word;
		cin >> num;
		getchar();
		getchar();
		getline(cin, word);
		cout << num << ": " << word << endl;
		if (mymap[num][word].size()) {
			for (string each : mymap[num][word]) {
				cout << each << endl;
			}
		}
		else
			cout << "Not Found" << endl;
	}
		return 0;
}