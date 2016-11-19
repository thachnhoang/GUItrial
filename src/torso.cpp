#include "std_lib_facilities.h"
#include "torso.h"


void torso::create(string nam, string number, string wgt, string des, double ct, int count)
{
	name.push_back(nam);
	part_number.push_back(number);
	weight.push_back(wgt);
	description.push_back(des);
	cost.push_back(ct);
	battery_count.push_back(count);
}

string torso::print()
{
	ostringstream of;
	int size = name.size();
	for (int i = 0; i < size; i++)
	{
		of << (i + 1) << ". " << name[i] << ", #" << part_number[i] << ", " << weight[i] << " lbs, " << battery_count[i] << " battery, " << description[i] << ", $" << cost[i] << "\n";
	}
	return of.str();
}

string torso::print_feature(string part)
{
	ostringstream of;
	for (int i = 0; i < name.size(); i++)
	{
		if (part == name[i])
		{
			of << "torso: " << name[i] << ", " << description[i] << endl;
		}
	}
	return of.str();
}

double torso::get_cost(string part)
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

int torso::get_battery(string part)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (part == name[i])
		{
			return battery_count[i];
		}
	}
	return 0;
}
