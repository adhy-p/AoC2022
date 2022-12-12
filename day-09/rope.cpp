#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>

using namespace std;

#define N 10

void move_head(char dir, int& x, int& y) {
	switch (dir) {
		case 'U': y++; break;
		case 'D': y--; break;
		case 'R': x++; break;
		case 'L': x--; break;
		default: break;
	}
}

bool move_tail(int hx, int hy, int& tx, int& ty) {
	int dx = hx - tx;
	int dy = hy - ty;
	unordered_map<int, int> m = { {-2, -1}, {2, 1} };

	if (abs(dx) < 2 && abs(dy) < 2)
		return false;

	if (m.find(dx) != m.end()) {
		tx += m[dx];
		if (hy > ty) {
			ty++;
		} else if (hy < ty) {
			ty--;
		}
		return true;
	}

	if (m.find(dy) != m.end()) {
		ty += m[dy];
		if (hx > tx) {
			tx++;
		} else if (hx < tx) {
			tx--;
		}
		return true;
	}

	return true;
}

void simulate(set<pair<int, int>>& path, int hx[N], int hy[N], char dir, int dist) {
	for (int i = 0; i < dist; i++) {
		move_head(dir, hx[0], hy[0]);
		for (int i = 1; i < N; i++) {
			bool moved = move_tail(hx[i-1], hy[i-1], hx[i], hy[i]);
			if (i == N - 1 && moved)
				path.insert({hx[i], hy[i]});
		}
	}
}

int main() {
	ifstream f("input.txt");
	char dir;
	int dist;

	int hx[N] = {0};
	int hy[N] = {0};

	set<pair<int, int>> path;

	path.insert({0, 0});
	while (f >> dir >> dist) {
		simulate(path, hx, hy, dir, dist);
	}

	//for (auto p: path)
	//	cout << p.first << " " << p.second << endl;

	cout << path.size() << endl;
	return 0;
}
