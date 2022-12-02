#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

// p1 -> A: rock, B: paper, C: scissors
// p2 -> X: rock, Y: paper, Z: scissors
// task2 X: lose, Y; draw, Z: win
// lose: 0, draw: 3, win: 6

int main() {
	ifstream f("input.txt");
	char p1, p2;
	char p1s[3] = {'A', 'B', 'C'};
	char p2s[3] = {'X', 'Y', 'Z'};
	int shape[3] = {1, 2, 3};

	int score = 0;
	while (f >> p1 >> p2) {
		int i, j;
		for (i = 0; i < 3; i++) {
			if (p1 == p1s[i])
				break;
		}

		for (j = 0; j < 3; j++) {
			if (p2 == p2s[j])
				break;
		}

		//int diff = j - i;
		//if (diff == 1 || diff == -2) {
		//	score += 6;
		//} else if (diff == 0) {
		//	score += 3;
		//} 

		if (j == 2) {
			i += 1;
			i %= 3;
			score += shape[i];
			score += 6;
		} else if (j == 1) {
			score += shape[i];
			score += 3;
		} else {
			i -= 1;
			if (i < 0)
				i = 2;
			score += shape[i];
		}
		//score += shape[j];
	}
	cout << score << endl;
	return 0;
}
