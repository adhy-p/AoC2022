#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#define N 3

using namespace std;

auto minheap = [](int val1, int val2) { return val1 > val2; };

void push(priority_queue<int, vector<int>, decltype(minheap)>& pq, int val) {
	if (pq.size() < N) {
		pq.push(val);
	} else {
		if (pq.top() < val) {
			pq.pop();
			pq.push(val);
		}
	}
}

int main() {
	ifstream iFile("input.txt");

	//int max = -1;				// task 1
	priority_queue<int, vector<int>, decltype(minheap)> pq(minheap);
	int total = 0;

	int curr_elf = 0;
	string line;

	while (getline(iFile, line)) {
		if (line.compare("") == 0) {
			//if (curr_elf > max) 
			//	max = curr_elf;
			push(pq, curr_elf);
			curr_elf = 0;
		} else {
			curr_elf += stoi(line);
		}
	}

	//cout << max << endl;
	while (!pq.empty()) {
		//cout << pq.top() << endl;
		total += pq.top();
		pq.pop();
	}
	cout << total << endl;

	return 0;
}
