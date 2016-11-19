#include "std_lib_facilities.h"
#include "head.h"


void head::create(string nam, string number, string wgt, string des, double ct)
{
	name.push_back(nam);
	part_number.push_back(number);
	weight.push_back(wgt);
	description.push_back(des);
	cost.push_back(ct);
}

string head::print()
{
	ostringstream of;
	int size = name.size();
	for (int i = 0; i < size; i++)
	{
		of << (i + 1) << ". " << name[i] << ", #" << part_number[i] << ", " << weight[i] << " lbs, " << description[i] << ", $" << cost[i] << "\n";
	}
	return of.str();
}

string head::print_feature(string part)
{
	ostringstream of;
	for (int i = 0; i < name.size(); i++)
	{
		if (part == name[i])
		{
			of << "head: " << name[i] << ", " << description[i] << endl;
		}
	}
	return of.str();
}

double head::get_cost(string part)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (part == name[i])
		{
			return cost[i];
		}
	}
	return 0;
}


