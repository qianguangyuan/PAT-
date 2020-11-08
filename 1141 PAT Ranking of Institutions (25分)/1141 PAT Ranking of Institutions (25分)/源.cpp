#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Node {
	string name;
	int tws, ns;
};

bool compare(const Node& n1, const Node& n2) {
	if (n1.tws != n2.tws)return n1.tws > n2.tws;
	if (n1.ns != n2.ns)return n1.ns < n2.ns;
	else return n1.name < n2.name;
}

unordered_map<string, int> Mymap;
unordered_map<string, double> sum;

int main() {
	int m; cin >> m;
	while (m--) {
		string id, name;
		double score;
		cin >> id >> score >> name;
		for (int i = 0; i < name.size(); i++)
			name[i] = tolower(name[i]);
		Mymap[name]++;
		if (id[0] =='T')
			score= score * 1.5;
		else if(id[0]=='B') score=score / 1.5;
		sum[name] += score;
	}
	vector<Node> v(Mymap.size());
	int i = 0;
	for (auto it : Mymap) {
		v[i].name = it.first;
		v[i].ns = it.second;
		v[i].tws = sum[it.first];
		i++;
	}
	sort(v.begin(), v.end(), compare);
	cout << Mymap.size() << endl;
	int rank = 1, pre=0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].tws != pre) rank = i + 1;
		pre = v[i].tws;
		cout << rank << ' ' << v[i].name << ' ' << v[i].tws << ' ' << v[i].ns << endl;
	}
	return 0;
}
	