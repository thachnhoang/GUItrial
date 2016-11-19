#include "robotPart.h"

#ifndef ORDER_H
#define ORDER_H

class customerOrder {
private:
	vector <string> BC_name;
	vector <string> BC_address;
	vector <string> BC_phone;
	vector <string> BC_email;
	vector <string> order_number;
	vector <string> sale_date;
	vector <string> robot_ordered;
	//vector <double> price;
	vector <double> quantity;
	vector <string> saleman;
	vector <double> profit;
public:
	customerOrder();
	void set_order(string, string, string, string, string, string, string, string, double, double);
	void customer_info();
	void sale_info();
	//void print(string name);
	//double total_profit();
	//void save();
	//void customer_order(string name);
	//void customer_bill(string name);
};

extern customerOrder* order;
#endif // !ORDER_H

#pragma once
