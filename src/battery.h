#ifndef BATTERY_H
#define BATTERY_H

class battery {
private:
	vector <string> name;
	vector <string> part_number;
	vector <string> weight;
	vector <double> cost;
	vector <string> description;
	vector <int> energy;
public:
	void create(string, string, string, string, double, int);
	string print();
	string print_feature(string part);
	double get_cost(string part);
};
#endif 

#pragma once
