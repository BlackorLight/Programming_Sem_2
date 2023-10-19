#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void change(map<string, string>& regions, map<string, string>& centers, map<string, vector<string>>& lastregions);

void renames(map<string, string>& regions, map<string, string>& centers, map<string, vector<string>>& lastregions);

void about(map<string, string>& regions);

void all(map<string, string>& regions);
