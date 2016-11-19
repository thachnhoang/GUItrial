#ifndef TORSO_H
#define TORSO_H

class torso {
private:
	vector <string> name;
	vector <string> part_number;
	vector <string> weight;
	vector <double> cost;
	vector <string> description;
	vector <int> battery_count;
public:
	void create(string, string, string, string, double, int);
	string print();
	string print_feature(string part);
	double get_cost(string part);
	int get_battery(string part);
};
#endif // !TORSO_H

#pragma once
