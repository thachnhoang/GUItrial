#ifndef HEAD_H
#define HEAD_H

class head {
private:
	vector <string> name;
	vector <string> part_number;
	vector <string> weight;
	vector <double> cost;
	vector <string> description;
public:
	void create(string, string, string, string, double);
	string print();
	string print_feature(string part);
	double get_cost(string part);
};
#endif 

#pragma once
