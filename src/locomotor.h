#ifndef LOCOMOTOR_H
#define LOCOMOTOR_H

class locomotor {
private:
	vector <string> name;
	vector <string> part_number;
	vector <string> weight;
	vector <double> cost;
	vector <string> description;
	vector <int> power_consumed;
	vector <int> speed;
public:
	void create(string, string, string, string, double, int, int);
	string print();
	string print_feature(string part);
	double get_cost(string part);
};
#endif 

#pragma once
