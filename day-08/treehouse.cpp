#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int calc_scenic_score(vector<string>& arr, int row, int col) { 
	if (row == 0 || row == arr.size() - 1 || col ==  0 || col == arr.size() - 1)
		return 0;

	int top = row - 1, bot = row + 1;
	int left = col - 1, right = col + 1;
	int score;

	while (top > 0) {
		if (arr[top][col] >= arr[row][col])
			break;
		top--;
	}

	while (bot < arr.size() - 1) {
		if (arr[bot][col] >= arr[row][col])
			break;
		bot++;
	}

	while (left > 0) {
		if (arr[row][left] >= arr[row][col])
			break;
		left--;

	}

	while (right < arr.size() - 1) {
		if (arr[row][right] >= arr[row][col])
			break;
		right++;
	}
	return (row - top) * (bot - row) * (col - left) * (right - col);
}

void iterate(vector<string>& arr, vector<vector<bool>>& is_visible, int dir) {
	int start_row, end_row, start_col, end_col;
	int max_score;
	if (dir == 1) { // top to bot, left to right
		start_row = 0;
		end_row = arr.size();
		start_col = 0;
		end_col = arr.size();
	} else { // bot to top, right to left
		start_row = arr.size() - 1;
		end_row = -1;
		start_col = arr.size() - 1;
		end_col = -1;
	}

	int i = start_row;
	int j = start_col;
	int tallest_row = -1;
	int tallest_col = -1;

	while (i != end_row) {
		j = start_col;
		while (j != end_row) {
			if (i == 0 || i == arr.size() - 1 || j == 0 || j == arr.size() - 1)
				is_visible[i][j] = true;

			if (arr[i][j] - '0' > tallest_row) {
				tallest_row = arr[i][j] - '0';
				is_visible[i][j] = true;
			} 

			if (arr[j][i] - '0' > tallest_col) {
				tallest_col = arr[j][i] - '0';
				is_visible[j][i] = true;
			} 

			int score = calc_scenic_score(arr, i, j);
			if (score > max_score)
				max_score = score;

			j += dir;
		}
		tallest_row = -1;
		tallest_col = -1;
		i += dir;
	}
	cout << "scenic score: " << max_score << endl;
}


int count_visible(vector<vector<bool>>& is_visible) {
	int visible = 0;
	for (auto row: is_visible) {
		for (auto i: row) {
			if (i)
				visible++;
		}
	}
	return visible;
}

int visible_trees(vector<string> arr) {
	vector<vector<bool>> is_visible(arr.size(), vector<bool>(arr[0].size(), false));

	int directions[2] = {1, -1};
	for (int i = 0; i < 2; i++) {
		iterate(arr, is_visible, directions[i]);
	}

	return count_visible(is_visible);
}

int main() {
	ifstream f("input.txt");
	string line;
	vector<string> arr;

	while (f >> line) {
		arr.push_back(line);
	}

	cout << visible_trees(arr) << endl;
	return 0;
}
