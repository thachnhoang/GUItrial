#include "std_lib_facilities.h"
#include "battery.h"


void battery::create(string nam, string number, string wgt, string des, double ct, int ener)
{
	name.push_back(nam);
	part_number.push_back(number);
	weight.push_back(wgt);
	description.push_back(des);
	cost.push_back(ct);
	energy.push_back(ener);
}

string battery::print()
{
	ostringstream of;
	int size = name.size();
	for (int i = 0; i < size; i++)
	{
		of << (i + 1) << ". " << name[i] << ", #" << part_number[i] << ", " << weight[i] << " lbs, " << energy[i] << " kW/h, " << description[i] << ", $" << cost[i] << "\n";
	}
	return of.str();
}

string battery::print_feature(string part)
{
	ostringstream of;
	for (int i = 0; i < name.size(); i++)
	{
		if (part == name[i])
		{
			of << "battery: " << name[i] << ", " << energy[i] << " kW/h, " << description[i] << endl;
		}
	}
	return of.str();
}

double battery::get_cost(string part)
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


