#include "std_lib_facilities.h"
#include "arm.h"


void arm::create(string nam, string number, string wgt, string des, double ct, int power)
{
	name.push_back(nam);
	part_number.push_back(number);
	weight.push_back(wgt);
	description.push_back(des);
	cost.push_back(ct);
	power_consumed.push_back(power);
}

string arm::print()
{
	ostringstream of;
	int size = name.size();
	for (int i = 0; i < size; i++)
	{
		of << (i + 1) << ". " << name[i] << ", #" << part_number[i] << ", " << weight[i] << " lbs, " << power_consumed[i] << " W, " << description[i] << ", $" << cost[i] << "\n";
	}
	return of.str();
}

string arm::print_feature(string part)
{
	ostringstream of;
	for (int i = 0; i < name.size(); i++)
	{
		if (part == name[i])
		{
			of << "arm: "<< name[i] << ", " << power_consumed[i] << " W, " << description[i] << endl;
		}
	}
	return of.str();
}

double arm::get_cost(string part)
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


