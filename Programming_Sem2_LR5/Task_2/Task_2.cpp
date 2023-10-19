#include "Header.h"

enum COMMANDS {
	CHANGE = 1,
	RENAME,
	ABOUT,
	ALL, EXIT
};

int main() {
	cout << "Commands:\nCHANGE = 1\nRENAME=2\nABOUT=3\nALL=4\nEXIT=5\n";
	string command;
	map<string, string> regions;
	map<string, string> centers;
	map<string, vector<string>> lastregions;
	while (true) {
		cin >> command;
		if (command == "CHANGE" || command == to_string(CHANGE)) {
			change(regions, centers, lastregions);
		}
		else if (command == "RENAME" || command == to_string(RENAME)) {
			renames(regions, centers, lastregions);
		}
		else if (command == "ABOUT" || command == to_string(ABOUT)) {
			about(regions);
		}
		else if (command == "ALL" || command == to_string(ALL)) {
			all(regions);
		}
		else if (command == "EXIT" || command == to_string(EXIT)) {
			exit(0);
		}
		else {
			cout << "Incorrect command, Enter command again" << endl;
		}
	}
}
