#include "Header.h"

void change(map<string, string>& regions, map<string, string>& centers, map<string, vector<string>>& lastregions) {
	string region;
	cin >> region;
	string new_center;
	cin >> new_center;
	auto it = regions.find(region);
	if (it == regions.end()) {
		for (auto i : lastregions) {
			for (auto j : i.second) {
				if (j == region) {
					auto its = centers.find(i.first);
					cout << "Region " << i.first << " has changed its administrative center from " << its->first << " to " << new_center << endl;
					it->second = new_center;
					centers.erase(its);
					region = its->second;
					centers.insert(make_pair(new_center, region));
					return;
				}
			}
		}
		cout << "New region " << region << " with administrative center " << new_center << endl;
		regions.insert(make_pair(region, new_center));
		centers.insert(make_pair(new_center, region));
	}
	else {
		if (it->second == new_center) {
			cout << "Incorrect" << endl;
			return;
		}
		cout << "Region " << region << " has changed its administrative center from " << it->second << " to " << new_center << endl;
		auto its = centers.find(it->second);
		it->second = new_center;
		centers.erase(its);
		centers.insert(make_pair(new_center, region));
	}
	return;
}

void renames(map<string, string>& regions, map<string, string>& centers, map<string, vector<string>>& lastregions) {
	string old_region;
	cin >> old_region;
	string new_region;
	cin >> new_region;
	auto it = regions.find(old_region);
	if (it == regions.end()) {
		cout << "Incorrect" << endl;
	}
	else {
		cout << old_region << " has been renamed to " << new_region << endl;
		auto its = centers.find(it->second);
		string center = it->second;
		its->second = new_region;
		regions.erase(it);
		regions.insert(make_pair(new_region, center));
		auto lastit = lastregions.find(old_region);		if (lastit != lastregions.end()) {
			string last1 = old_region;
			vector<string> last2 = lastit->second;
			last2.push_back(last1);
			lastregions.erase(lastit);
			lastregions.insert(make_pair(new_region, last2));
		}
		else {
			vector<string> last2 = { old_region };
			lastregions.insert(make_pair(new_region, last2));
		}
	}
	return;
}

void about(map<string, string>& regions) {
	string region;
	cin >> region;
	auto it = regions.find(region);
	if (it == regions.end()) {
		cout << "Incorrect" << endl;
	}
	else {
		cout << it->first << " has administrative center " << it->second << endl;;
	}
	return;
}

void all(map<string, string>& regions) {
	int check = 0;
	for (auto i : regions) {
		cout << i.first << " - " << i.second << endl;
		check++;
	}
	if (check == 0) {
		cout << "Incorrect" << endl;
	}
	return;
}
