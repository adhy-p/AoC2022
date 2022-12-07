#include <iostream>
#include <fstream>
#include <unordered_map>

#define N 14

using namespace std;

bool check(unordered_map<char, int>& m) {
	int total = 0;
	for (auto& entry: m) {
		if (entry.second > 1)
			return false;
		total += entry.second;
	}
	return (total == N);
}

int main() {
	ifstream f("input.txt"); 
	unordered_map<char, int> m;
	string line;
	getline(f, line);
	int i;
	for (i = 0; i < line.size(); i++) {
		if (i >= N)
			m[line[i - N]] -= 1;

		if (m.find(line[i]) == m.end()) {
			m.insert({line[i], 1});
		} else {
			m[line[i]] += 1;
		}

		if (check(m))
			break;
	}
	cout << i + 1 << endl;
	return 0;
}
