#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define N 9 // todo: determine the number of stacks automatically.

using namespace std;

void print_state(vector<vector<char>>& arr) {
	for (int i = 0; i < N; i++) {
		cout << "arr " << i << ": ";
		for (auto c: arr[i])
			cout << c;
		cout << endl;
	}
}


void print_top(vector<vector<char>>& arr) {
	for (int i = 0; i < N; i++) {
		cout << arr[i].back();
	}
	cout << endl;
}

void init(vector<vector<char>>& arr, vector<string> input) {
	// [N] [M] [F] [D] [R] [C] [W] [T] [M]
	//  1   2   3   4   5   6   7   8   9 
	// index: 1, 5, 9, ...

	for (int i = 0; i < input.size(); i++) {
		string line = input[input.size() - 1 - i];
		for (int i = 0; i < N; i++) {
			int idx = i * 4 + 1;
			if (line[idx] != ' ' && isalpha(line[idx])) // isalpha to handle the last line
				arr[i].push_back(line[idx]);
		}
	}
}

void process_data(vector<vector<char>>& arr, string line) {
	string tmp1, tmp2, tmp3;
	int n, src, dst;
	stringstream ss(line);

	ss >> tmp1 >> n >> tmp2 >> src >> tmp3 >> dst;
	src -= 1; dst -= 1; // 0 indexing

	//cout << n << " " << src << " " << dst << endl;

	for (int i = 0; i < n; i++) {
		arr[dst].push_back(arr[src].back());
		arr[src].pop_back();
		// print_state(arr);
	}
	reverse(arr[dst].end() - n, arr[dst].end());
	//print_state(arr);
	return;
}

int main() {
	ifstream f("input.txt");
	vector<string> input;
	string line;

	vector<vector<char>> arr;
	arr.reserve(N);

	bool init_state = true;
	while (getline(f, line)) {
		if (line.compare("") == 0) {
			init(arr, input);
			init_state = false;
			continue;
		}

		if (init_state) {
			input.push_back(line);
		} else {
			process_data(arr, line);
		}
	}

	print_top(arr);
	return 0;
}
