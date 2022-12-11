#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

bool startswith(string s, string prefix) {
	return (s.compare(0, prefix.size(), prefix) == 0);
}

class Directories {
	public:
		Directories (ifstream& f) {
			string line;
			while(getline(f, line)) {
				commands.push_back(line);
			}
		}

		void run() {
			for (auto& line: commands) {
				if (startswith(line, "$")) {
					line = line.substr(line.find(" ") + 1);
					cout << line << endl;
					string cmd = line.substr(0, line.find(" "));
					line = line.substr(line.find(" ") + 1);
					string args = "";
					if (line.find(" ") != -1)
						args = line.substr(line.find(" ") + 1);
					cout << "cmd: " << cmd << endl;
					cout << "args: " << args << endl;
				}
			}
		}


	private:
		vector<string> commands;
		unordered_map<string, size_t> files;
		unordered_map<string, Directories> dirs;
		string cwd;
};

int main() {
	ifstream f("input.txt");
	Directories d(f);
	d.run();
	return 0;
}
