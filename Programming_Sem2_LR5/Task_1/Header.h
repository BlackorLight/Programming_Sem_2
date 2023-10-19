#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void create_tram(map<string, vector<string>>& stop, map<string, vector<string>>& alltram);

void trams_in_stop(map<string, vector<string>>& stop);

void stops_in_tram(map<string, vector<string>>& stop, map<string, vector<string>>& alltram);

void trams(map<string, vector<string>>& stop);
