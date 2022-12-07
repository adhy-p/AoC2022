#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

size_t calc_score(string first, string second) {
	size_t p = 0;
	unordered_map<char, int> m1;
	unordered_map<char, int> m2;
	for (auto c: first)
		m1[c] = 1;

	for (auto c: second) {
		if (m1.find(c) != m1.end() && m2.find(c) == m2.end()) {
			if (isupper(c)) {
				p += c - 'A' + 27;
			} else {
				p += c - 'a' + 1;
			}
			m2[c] = 1;
		}
	}

	return p;
}

size_t calc_score(vector<string> group) {
	size_t p;
	unordered_map<char, int> m[3];

	int i = 0;
	for (auto s: group) {
		for (auto c: s) {
			m[i].insert({c, 1});
		}
		i++;
	}

	for (char c = 'a'; c <= 'z'; c++) {
		if (m[0].find(c) != m[0].end() && m[1].find(c) != m[1].end()
				&& m[2].find(c) != m[2].end()) {
		p = c - 'a' + 1;
		return p;
		}
	}

	for (char c = 'A'; c <= 'Z'; c++) {
		if (m[0].find(c) != m[0].end() && m[1].find(c) != m[1].end()
				&& m[2].find(c) != m[2].end()) {
		p = c - 'A' + 27;
		return p;
		}
	}

	return 0;
}

int main() {
	ifstream f("input.txt");
	//ifstream f("t0.txt");

	size_t priorities = 0;
	size_t len;
	string s;
	vector<string> group;
	while (f >> s) {
		//len = s.size();
		//string first = s.substr(0, len / 2);
		//string second = s.substr(len / 2);
		// cout << first << " " << second << endl;
		//priorities += calc_score(first,second);
		group.push_back(s);
		if (group.size() == 3) {
			priorities += calc_score(group);
			group.clear();
		}
	}
	printf("%ld\n", priorities);

	return 0;
}
