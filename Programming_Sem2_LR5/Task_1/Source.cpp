#include "Header.h"

void create_tram(map<string, vector<string>>& stop, map<string, vector<string>>& alltram) {
	string name;
	cin >> name;
	int n;
	cin >> n;
	vector<string> stops;
	string place;
	int chek = 0;
	while (n != 0) {
		cin >> place;
		stops.push_back(place);
		auto it = alltram.find(place);
		if (it == alltram.end()) {
			vector <string> namesoftrams;
			namesoftrams.push_back(name);
			alltram.insert(make_pair(place, namesoftrams));
		}
		else {
			int check = 0;
			for (auto m : (it->second)) {
				if (m == name) {
					check++;
					break;
				}
			}
			if (check == 0) {
				it->second.push_back(name);
			}
		}
		n--;
	}
	stop.insert(make_pair(name, stops));
	return;
}

void trams_in_stop(map<string, vector<string>>& stop) {
	string name;
	cin >> name;
	int chek = 0;
	for (auto i : stop) {
		for (auto j : i.second) {
			if (j == name) {
				cout << i.first << " ";
				chek++;
				break;
			}
		}
	}
	cout << endl;
	if (chek == 0) {
		cout << "Stops is absent\n";
	}
	return;
}

void stops_in_tram(map<string, vector<string>>& stop, map<string, vector<string>>& alltram) {
	string tram;
	cin >> tram;
	vector<string> name;
	int chek = 0;
	for (auto i : stop) {
		if (i.first == tram) {
			name = i.second;
			for (auto j : i.second) {
				chek++;
				cout << j;
				for (auto it : alltram) {
					int check = 0;
					if (it.first == j) {
						for (auto its : it.second) {
							if (its != tram) {
								if (check == 0) {
									cout << "	trams ";
								}
								check++;
								cout << its << " ";
							}
						}
						if (check != 0) {
							cout << "pass through this station" << endl;
						}
						else {
							cout << "	no others trams pass through this station" << endl;
						}
					}

				}
			}
			cout << "\n";
			break;
		}
	}
	if (chek == 0) {
		cout << "Trams is absent\n";
	}
	return;
}

void trams(map<string, vector<string>>& stop) {
	int chek = 0;
	for (auto i : stop) {
		cout << "TRAM " << i.first << ": ";
		chek++;
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << "\n";
	}
	if (chek == 0) {
		cout << "Trams is absent\n";
	}
	return;
}
