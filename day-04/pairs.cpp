#include <iostream>
#include <fstream>

using namespace std;

bool within_range(int start, int end, int number) {
	return (start <= number && end >= number);
}

int main() {
	ifstream f("input.txt");
	string line;
	int overlaps = 0;
	while (getline(f, line)) {
		string first = line.substr(0, line.find(','));
		string second = line.substr(line.find(',') + 1);
		// cout << first << " " << second << endl;

		int s1,e1; int s2,e2;
		s1 = stoi(first.substr(0, first.find('-')));
		e1 = stoi(first.substr(first.find('-') + 1));

		s2 = stoi(second.substr(0, second.find('-')));
		e2 = stoi(second.substr(second.find('-') + 1));
		// cout << s1 << " " << e1 << " " << s2 << " " << e2 << endl;

		//if (s1 <= s2 && e1 >= e2 || s2 <= s1 && e2 >= e1)
		if (within_range(s1, e1, s2) || within_range(s1, e1, e2) 
				|| within_range(s2, e2, s1) || within_range(s2, e2, e1))
			overlaps++;
	}
	printf("%d\n", overlaps);
	return 0;
}
