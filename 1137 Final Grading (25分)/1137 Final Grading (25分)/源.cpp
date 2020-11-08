#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Stu {
	string id;
	int gm, gf, g,gp;
};

vector<Stu> v;
unordered_map<string, int> Mymap;

bool compare(const Stu& n1, const Stu& n2) {
	return n1.g != n2.g ? n1.g > n2.g:n1.id < n2.id;
}

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	int cnt = 1;
	while (n--) {
		string name; int points;
		cin >> name >> points;
		if (points >= 200) {
			Mymap[name] = cnt++;
			v.push_back({ name,-1,-1,0,points });
		}
	}
	while (m--) {
		string name;
		int score;
		cin >> name >> score;
		if (Mymap[name] != 0) {
			v[Mymap[name] - 1].gm = score;
		}
	}
	while (k--) {
		string name; int score;
		cin >> name >> score;
		if (Mymap[name] !=0) {
			int i = Mymap[name] - 1;
					v[i].gf = score;
					if (v[i].gm < score)
						v[i].g = score;
					else v[i].g = (0.6 * score + 0.4 * v[i].gm+0.5);
				}
			}
	sort(v.begin(), v.end(),compare);
	for (int i = 0; i < v.size(); i++)
		if (v[i].g >= 60)
			printf("%s %d %d %d %d\n", v[i].id.c_str(), v[i].gp, v[i].gm, v[i].gf, v[i].g);
	return 0;
}