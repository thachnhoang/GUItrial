#include "std_lib_facilities.h"
#include "locomotor.h"


void locomotor::create(string nam, string number, string wgt, string des, double ct, int power, int spd)
{
	name.push_back(nam);
	part_number.push_back(number);
	weight.push_back(wgt);
	description.push_back(des);
	cost.push_back(ct);
	power_consumed.push_back(power);
	speed.push_back(spd);
}

string locomotor::print()
{
	ostringstream of;
	int size = name.size();
	for (int i = 0; i < size; i++)
	{
		of << (i + 1) << ". " << name[i] << ", #" << part_number[i] << ", " << weight[i] << " lbs, " << power_consumed[i] << " W, " << speed[i] << " mph, " << description[i] << ", $" << cost[i] << "\n";
	}
	return of.str();
}

string locomotor::print_feature(string part)
{
	ostringstream of;
	for (int i = 0; i < name.size(); i++)
	{
		if (part == name[i])
		{
			of << "motor: " << name[i] << ", " << power_consumed[i] << " W, " << speed[i] << " mph, " << description[i] << endl;
		}
	}
	return of.str();
}

double locomotor::get_cost(string part)
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


